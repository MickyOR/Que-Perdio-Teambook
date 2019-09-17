const ll mod = 998244353; // c*2^k + 1 = 119*2^23 + 1
// 3 es raiz primitiva de mod, root = 3^c % mod = 3^119 % mod
const ll root = 15311432;
// root_1 = root^-1
const ll root_1 = 469870224;
// 2^k
const ll root_pw = 1 << 23;
 
ll modPow(ll b, ll e)
{
	if (e == 0) return 1;
	ll res = modPow(b, e/2);
	if (e%2 == 1)
		return (1LL * (b * res % mod) * res % mod) % mod;
	else 
		return (1LL * res * res % mod) % mod;
}
 
void fft(vector<ll> & a, bool invert) {
    ll n = a.size();
 
    for (ll i = 1, j = 0; i < n; i++) {
        ll bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if (i < j)
            swap(a[i], a[j]);
    }
 
    for (ll len = 2; len <= n; len <<= 1) {
        ll wlen = invert ? root_1 : root;
        for (ll i = len; i < root_pw; i <<= 1)
            wlen = (ll)(1LL * wlen * wlen % mod);
 
        for (ll i = 0; i < n; i += len) {
            ll w = 1;
            for (ll j = 0; j < len / 2; j++) {
                ll u = a[i+j], v = (ll)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (ll)(1LL * w * wlen % mod);
            }
        }
    }
 
    if (invert) {
        ll n_1 = modPow(n, mod-2);
        for (ll & x : a)
        {
        	x = (ll)(1LL * x * n_1 % mod);
        }
    }
}
 
vector<ll> fftMul(vector<ll> & a, vector<ll> & b)
{
	vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	ll n = 1;
	while (n < a.size() + b.size())
		n <<= 1;
	fa.resize(n);
	fb.resize(n);
 
	fft(fa, false);
	fft(fb, false);
 
	for (ll i = 0; i < n; i++)
		fa[i] = (1LL * (ll)fa[i] * (ll)fb[i] % mod);
	fft(fa, true);
 
	return fa;
}
