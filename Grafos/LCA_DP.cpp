#include <bits/stdc++.h>
#define clr(a,h)          memset(a, (h), sizeof(a))

using namespace std;

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
	for (int pot = Log2Tam-1; pot >= 0; pot--)
	{
		if (dp[a][pot] != dp[b][pot])
		{
			a = dp[a][pot];
			b = dp[b][pot];
		}
	}
	int lca = dp[a][0];
	return lca;
}

int main()
{
    /*
        Iniciar el arbol en el grafo g
        Asignar la raiz en la variable root
        
        Llamar initLCA() luego de crear el arbol
        LCA(a, b) devuelve el LCA de los nodos a y b
    */
    return 0;
}
// PLUS ULTRA!
