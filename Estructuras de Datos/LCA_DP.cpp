#include <bits/stdc++.h>
#define PI                acos(-1)
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
const int INF = int(1e9 + 7);

const int tam = 1010; // Max Nodos
const int Log2Tam = (log(tam)/log(2)) + 3;

vector< vi > g;
int dp[tam][Log2Tam], depth[tam];
int n, m, root; // nodos, aristas, raiz del arbol

void initDFS(int v, int p, int d)
{
	dp[v][0] = p; // padre inmediato
	depth[v] = d;
	for (int u : g[v])
	{
		if (u == p) continue;
		initDFS(u, v, d+1);
	}
}

void initLCA()
{
	clr(dp, -1);
	initDFS(root, -1, 0);
	for (int pot = 1; pot < Log2Tam; pot++)
	{
		for (int v = 0; v < n; v++)
		{
			if (dp[v][pot-1] == -1) continue;
			dp[v][pot] = dp[ dp[v][pot-1] ][pot-1];
		}
	}
}

int LCA(int a, int b)
{
	// b siempre debajo o al mismo nivel que a
	if (depth[a] > depth[b]) swap(a, b);
	
	int diff = depth[b] - depth[a];
	for (int pot = Log2Tam-1; pot >= 0; pot--)
	{
		if ( ( diff & (1 << pot) ) )
		{
			b = dp[b][pot];
		}
	}
	if (a == b) return a;
	while (dp[a][0] != dp[b][0])
	{
		int pot = 0;
		while (dp[a][pot+1] != dp[b][pot+1]) pot++;
		a = dp[a][pot];
		b = dp[b][pot];
	}
	int lca = dp[a][0];
	return lca;
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    /*
        Iniciar el arbol en el grafo g
        Asignar la raiz en la variable root
        
        Llamar initLCA() luego de crear el arbol
        LCA(a, b) devuelve el LCA de los nodos a y b
    */
    return 0;
}
// PLUS ULTRA!
