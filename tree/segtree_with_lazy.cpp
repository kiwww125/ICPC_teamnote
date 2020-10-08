//1-based
//range-sum segment tree

int n, m, lim;
vector<int> tree, lz;

void init(int node, int l, int r) {
	if (l == r) {
		lim = max(lim, node);
		return;
	}

	init(node * 2, l, (l + r) / 2);
	init(node * 2 + 1, (l + r) / 2 + 1, r);
}

//해당 node를 참조할 때만 값의 변경이 발생한다!
void lazy(int node, int l, int r) {
			tree[node] += (r - l + 1) * lz[node];
			if (node * 2 <= lim ) lz[node * 2] += lz[node];
			if (node * 2 + 1 <= lim) lz[node * 2 + 1] += lz[node];
			lz[node] = 0;
}

void upd(int node, int nl, int nr, int l, int r) {
	lazy(node, nl, nr);
	if (nr < l || r < nl) return; 
	if (l <= nl && nr <= r) {
		lz[node]++;
		lazy(node, nl, nr);
		return;
	}

	int mid = (nl + nr) / 2;
	upd(node * 2, nl, mid, l, r);
	upd(node * 2 + 1, mid + 1, nr, l, r);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int qry(int node, int nl, int nr, int l, int r) {

	lazy(node, nl, nr);
	if (nr < l || r < nl ) return 0;
	if (l <= nl && nr <= r) return tree[node];
	
	int mid = (nl + nr) / 2;

	return qry(node * 2, nl, mid, l, r) + qry(node * 2 + 1, mid + 1, nr, l, r);
}

int main() {
	cin >> n >> m;
	tree = lz = vector<int>(n * 4, 0);
	init(1, 1, n);
}
