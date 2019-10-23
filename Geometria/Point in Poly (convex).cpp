// lineal 
bool ins(vector<point> &pol, point p)
{
	fore(i, 0, pol.size()-1)
	{
		if(((pol[i+1] - pol[i]) ^ (p - pol[i])) > 0)
			return false;
	}
	return true;
}
// logaritmico clockwise
bool inslog(vector<point> &pol, point p)
{
	int lo = 1, hi = pol.size() - 2, mid;
	if(p.left(pol[0], pol[1]) || p.left(pol[hi], pol[0])) return false;
	while(lo < hi - 1)
	{
		mid = (lo + hi) / 2;
		if(p.left(pol[0], pol[mid]))
			hi = mid;
		else
			lo = mid;
	}
	return p.left(pol[hi], pol[lo]);
}
