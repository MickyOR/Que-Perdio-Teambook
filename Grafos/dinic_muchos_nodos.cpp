const int tam = 20010;

int S, T;
int n, m;
int dist[tam], q[tam], work[tam];

struct Edge {
	int to, rev;
	int f, cap;
};

vector<Edge> G[tam];

void addEdge(int s, int t, int cap)
{
	Edge a = {t, (int)G[t].size(), 0, cap};
	Edge b = {s, (int)G[s].size(), 0, 0};
	G[s].pb(a);
	G[t].pb(b);
}

bool dinic_BFS(){
	fill(dist, dist + 2*n + 2, -1);
	dist[S] = 0;
	int qt = 0;
	q[qt++] = S;
	for (int qh = 0; qh < qt; qh++)
	{
		int u = q[qh];
		for (int j = 0; j < G[u].size(); j++)
		{
			Edge &e = G[u][j];
			int v = e.to;
			if (dist[v] < 0 && e.f < e.cap)
			{
				dist[v] = dist[u] + 1;
				q[qt++] = v;
			}
		}
	}
	return dist[T] >= 0;
}

int dinic_DFS(int u, int f)
{
	if (u == T || f == 0) return f;
	for (int &i = work[u]; i < G[u].size(); i++)
	{
		Edge &e = G[u][i];
		if (e.cap <= e.f) continue;
		int v = e.to;
		if (dist[v] == dist[u] + 1)
		{
			int df = dinic_DFS(v, min(f, e.cap - e.f));
			if (df > 0)
			{
				e.f += df;
				G[v][e.rev].f -= df;
				return df;
			}
		}
	}
	return 0;
}

int maxFlow()
{
	int flow = 0;
	while ( dinic_BFS() )
	{
		fill(work, work + 2*n + 2, 0);
		while (true)
		{
			int df = dinic_DFS(S, INF);
			if (df == 0) break;
			flow += df;
		}
	}
	return flow;
}
