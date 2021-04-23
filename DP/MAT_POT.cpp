
typedef vector<vector<ll>> mat;
mat ans;
void mult(mat m1, mat m2)
{
	assert(m1[0].size() == m2.size());
	ans.clear();
	ll answer = 0;
	fore(i, 0, m1.size())
	{
		vector<ll> fila;
		fore(j, 0, m2[0].size())
		{
			answer = 0;
			fore(k, 0, m2.size())
				answer = (answer + m1[i][k] * m2[k][j]) % MOD;
			fila.pb(answer);
		}
		ans.pb(fila);
	}
}
void pot(mat base, ll exp)
{
	mat res(base.size(), vector<ll>(base.size(), 0));
	fore(i, 0, base.size())
	res[i][i] = 1;
	while(exp)
	{
		if(exp & 1)
		{
			mult(res, base);
			res = ans;
		}
		mult(base, base);
		base = ans;
		exp /= 2;
	}
	ans = res;
}
