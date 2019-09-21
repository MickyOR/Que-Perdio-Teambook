int s, t;
int gp[110][110], usados[110], lev[110];
vector<int> g[110];
bool bfs()
{
    int node;
    queue<int> que;
    que.push(s);
    memset(lev,-1,sizeof(lev));
    lev[s]=0;
    while(!que.empty())
    {
        node = que.front();
        que.pop();
        for(int i=0;i<g[node].size();i++)
        {
            if(lev[g[node][i]]==-1 && gp[node][g[node][i]]>0)
            {
                que.push(g[node][i]);
                lev[g[node][i]]= lev[node] + 1;
            }
        }
    }
    return lev[t]!=-1;
}
int dfs(int node, int f)
{
    if(node==t) return f;
    for(;usados[node]<g[node].size();usados[node]++)
    {
        int u = g[node][usados[node]];
        if(lev[u]!=lev[node]+1 || gp[node][u] <= 0 ) continue;
        int flow = dfs(u,min(gp[node][u],f));
        if(flow>0) {
            gp[node][u]-=flow;
            gp[u][node]+=flow;
            return flow;
        }
    }
    return 0;
}
int maxFlow()
{
    int flujo=0,ax;
    while(bfs())
    {
        memset(usados,0,sizeof(usados));
        while(ax=dfs(s,INT_MAX))
        {
            flujo+=ax;
        }
    }
    return flujo;
}
