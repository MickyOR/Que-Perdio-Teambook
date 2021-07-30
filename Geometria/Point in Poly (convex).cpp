// lineal 
bool ins(vector<point> &pol, point p)
{
	fore(i, 0, pol.size()-1)
		if(!p.left(pol[i], pol[i + 1])
			return false;
	return true;
}
// logaritmico counterclockwise
bool inpol(poly &pol, point p)
{
	int n = pol.size();
	if(((pol[1] - pol[0]) ^ (p - pol[0])) < 0 || ((pol[n - 1] - pol[0]) ^ (p - pol[0])) > 0)
		return 0;
	int lo = 1, hi = n - 2, mid, res;
	while(lo <= hi)
	{
		mid = (lo + hi) / 2;
		if(((pol[mid] - pol[0]) ^ (p - pol[0])) >= 0)
			res = mid, lo = mid + 1;
		else
			hi = mid - 1;
	}
	return ((pol[res + 1] - pol[res]) ^ (p - pol[res])) >= 0;
}
