//segment tree with max_query
//1-Based for segtree, input array

int n, m, k;
vector<ll> arr, tree;

ll init(int node, int l, int r) {
	if (l == r) return tree[node] = arr[l];
	int mid = (l + r) / 2;
	return tree[node] = init(node * 2, l, mid) +
		init(node * 2 + 1, mid + 1, r);
}

void upd(int node, int nl, int nr, int i, ll diff) {
	if (nr < i || i < nl) return;

	tree[node] += diff;
	if (nl != nr) {
		int mid = (nl + nr) / 2;
		upd(node * 2, nl, mid, i, diff);
		upd(node * 2 + 1, mid + 1, nr, i, diff);
	}
}

ll qry(int node, int nl, int nr, int l, int r) {
	if (nr < l || r < nl) return 0;
	if (l <= nl && nr <= r) return tree[node];

	int mid = (nl + nr) / 2;
	return qry(node * 2, nl, mid, l, r) + 
		qry(node * 2 + 1, mid + 1, nr, l, r);
}

int main(){
	cin >> n >> m >> k;
	arr = vector<ll>(n + 1, 0);
	tree = vector<ll>(4 * (n + 1), 0);

	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1,1,n);
    
}
