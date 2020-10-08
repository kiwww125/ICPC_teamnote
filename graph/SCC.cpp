//strongly connected component
//with stack(Tarjan Algorithm)
//1-based

const int MAXN = 200001;

int dn, n, m, idx;
vector<int> adj[MAXN];
vector<int> dfsn, scc, outdeg, ans;
vector<vector<int>> sset;
stack<int> S;

void init() {
	for (int i = 0; i < MAXN; i++) adj[i].clear();
	dfsn = scc = vector<int>(n, -1);
	sset = vector<vector<int>>();
	dn = 0, idx = 0;
}

//one component by one dfs
int dfs(int curr) {
	int res = dfsn[curr] = dn++;
	S.push(curr);

	for (int next : adj[curr]) {
		if (dfsn[next] == -1) res = min(res, dfs(next));
		else if (scc[next] == -1) res = min(res, dfsn[next]);
	}

	if(res == dfsn[curr]){
		int v;
		sset.emplace_back(vector<int>());
		while (1){
			v = S.top();
			S.pop();
			sset.back().emplace_back(v);
			scc[v] = idx;
			if (v == curr) break;
		}
		idx++;
	}

	return res;
}

int main(){
  cin >> n >> m;
	init();
  
}
