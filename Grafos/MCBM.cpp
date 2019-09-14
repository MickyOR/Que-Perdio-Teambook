// Maximum Cardinality Bipartite Matching
// O(VE)

const int tam = 500;
vector<int> G[tam];
int match[tam];
bool vis[tam];

int aug(int l)
{
	if (vis[l]) return 0;
	vis[l] = true;
	for (int i = 0; i < G[l].size(); i++)
	{
		int r = G[l][i];
		if (match[r] == -1 || aug(match[r]))
		{
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

int MCBC(int n, int m) // L, R
{
	fill(match, match+n+m, -1);
	int res = 0;
	for (int i = 0; i < n; i++) // L
	{
		fill(vis, vis + n, false);
		res += aug(i);
	}
	return res;
}
