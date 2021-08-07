// codeforces 622f
// evaluar un "polinomio interpolado" en o(nlogMOD) 
// debe cumplir xi+1 - xi = xj+1 - xj for all i, j < n\
// recibe vector de ys tal que f(i) = y[i]
ll eval(vll ys, ll x)
{
	int n = ys.size();
	if(x < n) return ys[x];
	ll res = 0, up = 1, dow = 1;
	fore(i, 1, n)
		dow = dow * (MOD - i) % MOD,
		up = up * (x - i) % MOD;
	fore(i, 1, n)
	{
		up = up * (x - i + 1) % MOD * pot(x - i, MOD - 2) % MOD;
		dow = dow * i % MOD * pot(MOD - (n - i), MOD - 2) % MOD;
		res = (res + ys[i] * up % MOD * pot(dow, MOD - 2) % MOD) % MOD;
	}
	return res;
}
