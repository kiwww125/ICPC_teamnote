#define x first
#define y second

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<pll> p;
vector<int> CH;

int ccw(pll a, pll b, pll c) {
	b = { b.x - a.x , b.y - a.y };
	c = { c.x - a.x , c.y - a.y };
	ll ret = b.x * c.y - b.y * c.x;
	//ccw -> 1 , cw -> -1
	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	return -1;
}

bool cmp(pll &a, pll &b) {
	if (ccw(p[0], a, b) == 0) {
		return a.x - p[0].x < b.x - p[0].x;
	}
	return ccw(p[0], a, b) == 1;
}

void graham_scan() {
	for (int i = 0; i < p.size(); i++) {
		while (CH.size() >= 2) {
			int s = CH.size() - 1;
			if (ccw( p[CH[s - 1]], p[CH[s]], p[i]) <= 0) CH.pop_back();
			else break;
		}
		CH.emplace_back(i);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int u, v; cin >> u >> v;
		p.emplace_back(pll(u, v));
	}

	swap(p[0], *min_element(p.begin(), p.end()));
	sort(p.begin() + 1, p.end(), cmp);
	graham_scan();

	cout << CH.size();

	return 0;
}
	
