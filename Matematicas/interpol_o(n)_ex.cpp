// codeforces 622f
// evaluar un "polinomio interpolado" en o(n)
// debe cumplir xi+1 - xi = xj+1 - xj for all i, j < n
#include <bits/stdc++.h>
#define fore(i, b, e)	for(int i = b; i < e; i++)

using namespace std;

typedef long long 		ll;
const int tam = 1000010;
const int MOD = 1000000007;
ll pot(ll b, ll e)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b % MOD;
		b = b * b % MOD;
		e /= 2;
	}
	return res;
}
ll ys[tam];
int main()
{
	ll n, k;
	cin>>n>>k;
	if(n < k + 2)
	{
		ll res = 0;
		fore(i, 1, n + 1)
			res = (res + pot(i, k)) % MOD;
		cout<<res<<'\n';
	}
	else
	{
		ys[0] = 0;
		fore(i, 1, k + 2)
			ys[i] = (ys[i - 1] + pot(i, k)) % MOD;
		ll res = 0, up = 1, dow = 1;
		fore(i, 1, k + 2)
			dow = dow * (MOD - i) % MOD,
			up = up * (n - i) % MOD;
		fore(i, 1, k + 2)
		{
			up = up * (n - (i - 1)) % MOD * pot(n - i, MOD - 2) % MOD;
			dow = dow * i % MOD * pot(MOD - (k + 1 - i + 1), MOD - 2) % MOD;
			res = (res + ys[i] * up % MOD * pot(dow, MOD - 2) % MOD) % MOD;
		}
		cout<<res<<'\n';
	}
	return 0;
}
