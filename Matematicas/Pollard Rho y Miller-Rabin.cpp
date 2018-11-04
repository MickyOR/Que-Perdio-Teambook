ll mulmod(ll a, ll b, ll c) //multiplicacion modular binaria
{
	ll x =0, y = a % c;
	while(b > 0)
	{
		if(b % 2 == 1) x = (x + y) % c;
		y = (y * 2) % c;
		b /= 2;
	}
	return x % c;
}
ll gcd(ll a, ll b) {return (b==0? a : gcd(b,a%b));}
ll poll(ll n) //numoro grande p = a*b devuelve a  (a y b primos)
{
	srand (time(NULL));
	ll x = rand()%(n-2) + 2, y = x, c = rand()%(n-1) + 1, d = 1;
	while(d==1)
	{
		x = (mulmod(x, x, n) + c) % n;
		y = (mulmod(y, y, n) + c) % n;
		y = (mulmod(y, y, n) + c) % n;
		d = gcd((x>y?x-y:y-x),n);
		if(d == n) return poll(n);
	}
	return d;
}
ll modpow(ll b, ll e, ll m)
{
	if(e == 0) return 1;
	//return (modpow((b*b) % m, e/2, m) * (e & 1? b : 1)) % m;
	return mulmod(modpow(mulmod(b,b,m), e/2, m), (e & 1? b : 1), m);
}
bool mill(ll n, int k) //k = 10 es seguro 
{
	ll p = n - 1;
	int r = 0;
	bool pp;
	while(p % 2 == 0)
	{
		p /= 2;
		r++;
	}
	for(int i =0; i < k; i++)
	{
		ll a = rand()%(n-4) + 2;
		ll exp = modpow(a,p,n);
		if(exp == 1 || exp == n-1) return true;
		pp = false;
		for(int j = 0; j < r; j++)
		{
			exp = mulmod(exp, exp, n);
			if(exp == 1) return false;
			if(exp == n-1) {pp = true; break;}
		}
		if(!pp) return false;
	}

	return true;
}