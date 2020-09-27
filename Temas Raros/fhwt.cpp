// copiado del vasito
ll c1[tam+9],c2[tam+9];  // tam must be power of 2 !!
void fhwt(ll* p, int n, bool inv){
	for(int l = 1; 2 * l <= n; l *= 2)
	for(int i = 0; i < n; i += 2 * l)
	fore(j, 0, l)
	{
		ll u = p[i + j], v = p[i + l + j];
		if(!inv) p[i + j] = u + v, p[i + l + j] = u - v; // XOR
		else p[i + j] = (u + v) / 2,p[i + l + j] = (u - v) / 2;
		//if(!inv) p[i + j] = v, p[i + l + j] = u + v; // AND
		//else p[i + j] = -u + v, p[i + l + j] = u;
		//if(!inv) p[i + j] = u + v, p[i + l + j] = u; // OR
		//else p[i + j] = v, p[i + l + j] = u - v;
	}
}
// like polynomial multiplication, but XORing exponents
// instead of adding them (also ANDing, ORing)
vector<ll> multiply(vector<ll>& p1, vector<ll>& p2){
	int n = 1<<(32-__builtin_clz(max(sz(p1), sz(p2)) - 1));
	fore(i, 0, n) c1[i] = 0, c2[i] = 0;
	fore(i, 0, sz(p1)) c1[i] = p1[i];
	fore(i, 0, sz(p2)) c2[i] = p2[i];
	fhwt(c1, n, false); fhwt(c2, n, false);
	fore(i, 0, n) c1[i] *= c2[i];
	fhwt(c1, n, true);
	return vector<ll>(c1, c1 + n);
}

void fhwt(vector<ll>& p, bool inv)
{
    fore(i, 0, sz(p)) c1[i] = p[i];
    fhwt(c1, sz(p), inv);
    fore(i, 0, sz(p)) p[i] = c1[i];
}
