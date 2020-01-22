#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define pb                emplace_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i, b, e)	  for (int i = (int)b; i < (int)e; i++)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);
const double EPS = 1e-9;
const double PI = acos(-1);

const int tam = 110;

struct Edge
{
	int to, rev;
	int flow, cap;
	int cost;
};
vector<Edge> G[tam];

void addEdge(int s, int t, int cap, int cost)
{
	Edge a = {t, (int)G[t].size(), 0, cap, cost};
	Edge b = {s, (int)G[s].size(), 0, 0, -cost};
	G[s].pb(a);
	G[t].pb(b);
}

int n, m;

int S, T;
vector<int> dist;
int pot[tam], curFlow[tam], prevNode[tam], prevEdge[tam];

ii MinCostMaxFlow()
{
	// Falta Bellmand - Ford para cuando hay aristas negativas
	int flow = 0;
	int flowCost = 0;
	while (true) // always a good start for an algorithm :v
	{
		set<ii> s;
		s.insert( mp(0, S) );
		dist.assign(n, INF);
		dist[S] = 0;
		curFlow[S] = INF;
		while (s.size() > 0)
		{
			int u = s.begin() -> second;
			int actDist = s.begin() -> first;
			s.erase(s.begin());
			if (actDist > dist[u]) continue;
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge &e = G[u][i];
				int v = e.to;
				if (e.cap <= e.flow) continue;
				int newDist = actDist + e.cost + pot[u] - pot[v];
				if (newDist < dist[v])
				{
					dist[v] = newDist;
					s.insert( mp(newDist, v) );
					prevNode[v] = u;
					prevEdge[v] = i;
					curFlow[v] = min(curFlow[u], e.cap - e.flow);
				}
			}
		}
		if (dist[T] == INF) 
			break;
		for (int i = 0; i < n; i++)
			pot[i] += dist[i];
		int df = curFlow[T];
		flow += df;
		for (int v = T; v != S; v = prevNode[v])
		{
			Edge &e = G[prevNode[v]][prevEdge[v]];
			e.flow += df;
			G[v][e.rev].flow -= df;
			flowCost += df * e.cost;
		}
	}
	return mp(flow, flowCost);
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin >> n >> m;
    S = 0, T = n-1;
    fore(i, 0, m)
    {
    	int a, b, cap, cost;
    	cin >> a >> b >> cap >> cost;
    	a--; b--;
    	addEdge(a, b, cap, cost);
    }
    cout << MinCostMaxFlow().S << '\n';
    return 0;
}
// PLUS ULTRA!
