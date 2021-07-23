typedef vector<int> poly;
void normalize(poly &p)
{
	while(p.size() > 1 && p.back() == 0) p.pop_back();
}
poly derivate(poly v)
{
	fore(i, 0, v.size() - 1)
		v[i] = 1ll * v[i + 1] * (i + 1) % MOD;
	v.pop_back();
	return v;
}
poly sum(poly a, poly b)
{
	if(a.size() < b.size())
		swap(a, b);
	fore(i, 0, b.size())
		a[i] = (a[i] + b[i]) % MOD;
	return a;
}
//input : B = b0 + b1x + ... + bnx^n with b0, bn != 0 and an integer d ≥ 0
//output: First d + 1 terms of 1 / B(x), it is: q0 + q1x + . . . + qdx^d
poly invert(poly b, int d)
{
	if(d == 0) return {pot(b[0], MOD - 2)};
	poly c = invert(b, d / 2);
	b.resize(sz(c) * 2);
	poly q = multiply(c, b);
	q[0] = (q[0] + MOD - 2) % MOD;
	fore(i, 0, q.size())
		q[i] = (-q[i] % MOD + MOD) % MOD;
	q = multiply(c, q);
	q.resize(d + 1);
	return q;
}

//input : A(x) and B(x) polynomials of degree m and n
//output: {Q, R} the quotient and remainder of dividing A by B

pair<poly,poly> divslow(poly &a, poly &b){
	poly q, r = a;
	while(sz(r) >= sz(b)){
		q.pb(1ll * r.back() * pot(b.back(), MOD - 2) % MOD);
		if(q.back()) fore(i, 0, sz(b)){
			r[sz(r) - i - 1] = (r[sz(r)-i-1] + MOD - 1ll * q.back() * b[sz(b) - i - 1] % MOD) % MOD;
		}
		r.pop_back();
	}
	reverse(all(q));
	return {q, r};
}

pair<poly, poly> divide(poly a, poly b)
{
	int m = sz(a), n = sz(b), magic = 750;
	if(m < n) return {{0}, a};
	if(min(m - n, n)< magic) return divslow(a, b);
	reverse(all(a));
	reverse(all(b));
	poly q = invert(b, m - n);
	q = multiply(a, q);
	q.resize(m - n + 1, 0);
	reverse(all(q));
	reverse(all(a));
	reverse(all(b));
	poly r = multiply(b, q);
	if(r.size() < a.size())
		r.resize(a.size());
	fore(i, 0, a.size())
		r[i] = ((a[i] - r[i]) % MOD + MOD) % MOD;
	normalize(r);
	return {q, r};
}

//input : A(x) of degree m and a n-uple x = (x1, . . . , xn)
//output: (A(x1), A(x2), . . . , A(xn))
vector<poly> init(poly &x)
{
	int n = sz(x);
	vector<poly> t(2 * n);
	fore(i, n, 2 * n) t[i] = {MOD - x[i - n], 1};
	for(int i = n - 1; i > 0; i--) t[i] = multiply(t[i<<1], t[i<<1|1]);
		return t;
}
poly evaluate(poly a, poly x)
{
	int n = x.size();
	vector<poly> tree = init(x), ans(2 * n);
	ans[1] = divide(a, tree[1]).s;
	fore(i, 2, 2 * n) 
		ans[i] = divide(ans[i>>1], tree[i]).s;
	poly r; 
	fore(i, 0, n) r.pb(ans[i + n][0]);
	return r;
}
// interpola ps n + 1 puntos para polinomio de grado n
poly interpol(poly x, poly y)
{
	int n = x.size();
	vector<poly> tree = init(x), tree1(2 * n);
	poly d = evaluate(derivate(tree[1]), x);
	fore(i, n, 2 * n)
		tree1[i] = {(int)(1ll * y[i - n] * pot(d[i - n], MOD - 2) % MOD)};
	for(int i = n - 1; i > 0; i--) 
		tree1[i] = sum(multiply(tree[i<<1], tree1[i<<1|1]), multiply(tree1[i<<1], tree[i<<1|1]));
	return tree1[1];
}
	

//para meter sin fft (ineficientes)
// n^2
poly evaluate1(poly a, poly b)
{
	poly res(b.size());
	fore(i, 0, b.size())
	{
		ll x = 1;
		res[i] = 0;
		fore(j, 0, a.size())
		{
			res[i] = (res[i] + a[j] * x) % MOD;
			x = 1ll * x * b[i] % MOD;
		}
		res[i] = (res[i] %	MOD + MOD) % MOD;
	}
	return res;
}
//interpolar n^4  creo
poly polo(poly p, int ind, int ini)
{
	poly res = {ini}, a;
	fore(i, 0, p.size())
	{
		if(i != ind)
		{
			a = {MOD - p[i], 1};
			res = multiply(res, a);
		}
	}
	return res;
}
poly interpol1(poly x, poly y)
{
	poly d = polo(x, -1, 1);
	d = derivate(d);
	d = evaluate1(d, x);
	poly res, a;
	fore(i, 0, y.size())
	{
		a = polo(x, i, 1ll * y[i] * pot(d[i], MOD - 2) % MOD);
		res = sum(res, a);
	}
	return res;
}
