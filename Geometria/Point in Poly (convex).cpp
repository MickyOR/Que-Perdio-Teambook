// lineal 
bool ins(vector<point> &pol, point p)
{
	fore(i, 0, pol.size()-1)
		if(!p.left(pol[i], pol[i + 1])
			return false;
	return true;
}
// logaritmico counterclockwise
bool inslog(vector<point> &pol, point p)
{
	int lo = 1, hi = pol.size() - 2, mid;
	if(p.left(pol[1], pol[0]) || p.left(pol[0], pol[hi])) return false;
	while(lo < hi - 1)
	{
		mid = (lo + hi) / 2;
		if(p.left(pol[0], pol[mid]))
			lo = mid;
		else
			hi = mid;
	}
	return p.left(pol[lo], pol[hi]);
}
