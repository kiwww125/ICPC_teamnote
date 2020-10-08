// 1-Based Tree used
//par[i][j] := i번째 노드의 2^j번째 조상 //
//par[i][j] 가 존재하지 않으면 0

int n,m;
int parent[200001][20];
int dep[100001];
int Dep;
vector<int> adj[100001];

void get_parent_by_dfs(int curr, int prev = -1) {
	if (prev != -1) dep[curr] = dep[prev] + 1;
	
	Dep = max(Dep, dep[curr]);
	for (int next : adj[curr]) {
		if (next == prev) continue;
		parent[next][0] = curr;
		get_parent_by_dfs(next, curr);
	}
	return;
}

void get_every_parent() {
	for (int i = 1; i < 20 ; i++) {
		for (int j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
	return;
}

int LCA(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);

	//노드 높이 맞춰주기
	for (int i = 19; i >= 0; i--) {
		if (dep[u] - dep[v] >= (1 << i)) {
			u = parent[u][i];
		}
	}

	if (u == v) return u;

	for (int i = 19; i >= 0; i--) {
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	return parent[u][0];
}
