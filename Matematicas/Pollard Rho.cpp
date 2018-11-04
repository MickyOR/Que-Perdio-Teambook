#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef unsigned long long 		ll;
typedef pair<int, int>	ii;
typedef vector<int>		vi;
bitset<100000> bi;
vector<ll> primos;
vector<ll> pricu;
void criba()
{
	bi.set();
	bi[0]=bi[1]=0;
	for(int i = 2; i<100000; i++)
	{
		if(bi[i])
		{
			for(int j = i + i;j<100000;j+=i)
				bi[j]=0;
			primos.push_back(i);
			pricu.push_back((ll)i*(ll)i);
		}
	}
}

ll mulmod(ll a, ll b, ll c)
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
ll poll(ll n)
{
	srand (time(NULL));
	ll x = rand()%(n-2) + 2, y = x, c = rand()%(n-1) + 1, d = 1;
	while(d==1)
	{
		x = (mulmod(x, x, n) + c) % n;
		y = (mulmod(y, y, n) + c) % n
		;
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
bool mill(ll n, int k)
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
ll prif(ll n)
{
	int in = 0, si = primos.size();
	bool t = false;
	ll res=1,con;
	while(pricu[in] <= n && in < si)
	{
		if(n%primos[in] == 0)
		{
			con=1;
			while(n%primos[in]==0)
			{
				con++;
				n/=primos[in];
			}
			res*=con;
		}
		in++;
	}
	if(n!=1)
	{
		if(n<10000000000)
			return res*2ll;
		else
			if(mill(n,15))
				return res*2ll;
			else
			{
				ll a = poll(n), b = n/a;
				return res*4ll;
			}
	}
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("asd", "w", stdout);
	criba();
	ll nu;
		cin>>nu;
		if(nu == 1)
			cout<<1<<endl;
		else
			cout<<prif(nu)<<endl;
	return 0;
}