#include <bits/stdc++.h>
#define clr(a,h)          memset(a, (h), sizeof(a))

using namespace std;

/*
Cambiar:
	- Valor que se guarda en cada nodo en HLD
	- Operador en Segment Tree
	- Operador en queryUp y query
Inicializar:
	- root para LCA
	- chainNo = 0 para HLD
	- Llenar chainHead[] con -1 para HLD
	- actPosInBase = 0 para Segment Tree
*/

const int tam = 10010;
const int Log2Tam = ( log(tam)/log(2) ) + 3;

vector< vi > g;
//HLD
int chainNo, chainPos[tam], chainIdx[tam], chainHead[tam], chainSize[tam];
//DFS
int dp[tam][Log2Tam], depth[tam], subTreeSize[tam];
int n, m, root;
//SegTree
int segTree[tam*4], posInBase[tam], baseArray[tam], actPosInBase;


void DFS(int v, int p, int d)
{
	dp[v][0] = p;
	depth[v] = d;
	subTreeSize[v] = 1;
	for (int u : g[v])
	{
		if (u == p) continue;
		DFS(u, v, d+1);
		subTreeSize[v] += subTreeSize[u];
	}
}

void HLD(int v, int p)
{
	if (chainHead[chainNo] == -1) chainHead[chainNo] = v;
	chainIdx[v] = chainNo;
	chainPos[v] = chainSize[chainNo];
	chainSize[chainNo]++;
	posInBase[v] = actPosInBase;
	baseArray[actPosInBase++] = v; // Aqui guardamos lo que queremos trabajar
								   // con el Segment Tree

	int bestChild = -1, maxSize = -1;
	for (int u : g[v])
	{
		if (u == p) continue;
		if (subTreeSize[u] > maxSize)
		{
			maxSize = subTreeSize[u];
			bestChild = u;
		}
	}

	if (bestChild != -1) HLD(bestChild, v);

	for (int u : g[v])
	{
		if (u == p || u == bestChild) continue;
		chainNo++;
		HLD(u, v);
	}
}

void initLCA()
{
	clr(dp, -1);
	DFS(root, -1, 0);
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

void initSegTree(int b, int e, int nodo)
{
	int L = 2 * nodo + 1, R = L + 1, mid = (b + e) / 2;
	if (b == e)
	{
		segTree[nodo] = baseArray[b];
		return;
	}
	initSegTree(b, mid, L);
	initSegTree(mid+1, e, R);

	// Funcion del Segment Tree que queremos hacer sobre el arbol
	segTree[nodo] = max(segTree[L], segTree[R]);
}

void updateSegTree(int b, int e, int nodo, int pos, int val)
{
	int L = 2 * nodo + 1, R = L + 1, mid = (b + e) / 2;
	if (b == e)
	{
		segTree[nodo] = val;
		return;
	}
	if (pos <= mid) updateSegTree(b, mid, L, pos, val);
	else updateSegTree(mid+1, e, R, pos, val);
	
	segTree[nodo] = max( segTree[L], segTree[R] );
}

int querySegTree(int b, int e, int nodo, int i, int j)
{
	int L = 2 * nodo + 1, R = L + 1, mid = (b + e) / 2;
	if (i <= b && e <= j) return segTree[nodo];
	if (j <= mid) return querySegTree(b, mid, L, i, j);
	else if (i > mid) return querySegTree(mid+1, e, R, i, j);
	else
	{
		int r1 = querySegTree(b, mid, L, i, j);
		int r2 = querySegTree(mid+1, e, R, i, j);
		return max(r1, r2);
	}
}

int queryUp(int u, int v)
{
	int uChain, vChain = chainIdx[v], ans = -1;
	while (true)
	{
		uChain = chainIdx[u];
		if (uChain == vChain)
		{
			int queryAns = querySegTree(0, actPosInBase-1, 0, posInBase[v], posInBase[u]);
			if (queryAns > ans)
			{
				ans = queryAns;
				break;
			}
		}
		int queryAns = querySegTree(0, actPosInBase-1, 0, posInBase[ chainHead[uChain] ], posInBase[u]);
		if (queryAns > ans) ans = queryAns;
		u = chainHead[uChain];
		u = dp[u][0];
	}
	return ans;
}

int query(int a, int b)
{
	int lca = LCA(a, b);
	int r1, r2;
	r1 = queryUp(a, lca);
	r2 = queryUp(b, lca);
	return max(r1, r2);
}

int main()
{
    return 0;
}
// PLUS ULTRA!
