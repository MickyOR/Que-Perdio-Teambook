typedef vector<point> poly;
void norm(poly &pol)
{
	int pos = 0;
	fore(i, 0, pol.size())
	{
		if(pol[i] < pol[pos])
			pos = i;
	}
	rotate(pol.begin(), pol.begin() + pos, pol.end());
}
poly minkos(poly &a, poly &b)
{
	norm(a);
	norm(b);
	int posa = 0, posb = 0, ta = a.size(), tb = b.size();
	poly res;
	ll cro;
	while(posa < ta || posb < tb)
	{
		res.pb(a[(posa) % ta] + b[(posb) % tb]);
		cro = (a[(posa + 1) % ta] - a[posa % ta]) ^ (b[(posb + 1) % tb] - b[posb % tb]);
		if(cro == 0)
			posa++, posb++;
		else if(cro < 0)
			posb++;
		else posa++;
	}
	return res;
}
