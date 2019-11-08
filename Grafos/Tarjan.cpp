int n;
vector<vector<int>> adj;

vector<bool> visited;
vector<int> tin, low;
int timer;
vector<vectotr<int>> comps; // componentes biconexos
stack<int> stk;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    stk.push(v);
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v])
            {
            	if (p != -1) IS_CUTPOINT(v);

            	comps.push_back({v});
            	while (comps.back().back() != to)
            	{
            		comps.back().push_back(stk.top());
            		stk.pop();
            	}

            }
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
