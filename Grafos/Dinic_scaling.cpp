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

bool dinic_BFS(int f){
    fill(dist, dist + n + 2, -1);
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
            if (dist[v] < 0 && f < =e.cap-e.f)
            {
                dist[v] = dist[u] + 1;
                q[qt++] = v;
            }
        }
    }
    return dist[T] >= 0;
}

bool dinic_DFS(int u, int f)
{
    if (f==0)
        return 0;
    if (u==T)
        return 1;
    for (int &i = work[u]; i < G[u].size(); i++)
    {
        Edge &e = G[u][i];
        if (e.cap <= e.f) continue;
        int v = e.to;
        if (dist[v] == dist[u] + 1 && e.cap-e.f>=f)
        {
            int df = dinic_DFS(v, f);
            if (df > 0)
            {
                e.f += f;
                G[v][e.rev].f -= f;
                return df;
            }
        }
    }
    return 0;
}

int maxFlow()
{
    int flow = 0;
    for(int scaling=30;scaling>=0;scaling--)
    {
        while (dinic_BFS(1<<scaling))
        {
            fill(work, work + n + 2, 0);
            while(true)
            {
                int df=dinic_DFS(S,1<<scaling);
                if (df==0)break;
                flow+=(1<<scaling);
            }
        }        
    }
    return flow;
}