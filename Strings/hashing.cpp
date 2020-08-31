
ll pot(ll b, ll e , ll m);
struct Hash
{
	int p = 997, m[2], in[2];
	vector<int> h[2], inv[2];
	Hash(string s)
	{
		m[0] = 998244353, m[1] = 1000000009;
		fore(i, 0, 2)
		{
			in[i] = pot(p, m[i]-2, m[i]);
			h[i].resize(s.size() + 1);
			inv[i].resize(s.size() + 1);
			ll acu = 1;
			h[i][0] = 0, inv[i][0] = 1;
			fore(j, 0, s.size())
			{
				h[i][j + 1] = (h[i][j] + acu * s[j]) % m[i];
				inv[i][j + 1] = (1ll * inv[i][j] * in[i]) % m[i];
				acu = (acu * p) % m[i];
			}
		}
	}
	ll get(int b, int e)
	{
		ll ha[2];
		fore(i, 0, 2)
			ha[i] = ((((h[i][e] - h[i][b]) * (ll)inv[i][b]) % m[i]) + m[i]) % m[i];
		return((ha[0] << 32) | ha[1]) ;
	}
};
