// devuelve horario
vector<point> hull(vector<point> p)
{
	int n = p.size();
	vector<point> h;
	sort(all(p));
	fore(i, 0, n)
	{
		while(h.size() >= 2 && p[i].left(h[sz(h) - 2], h.back())) h.pop_back();
		h.push_back(p[i]);
	}
	h.pop_back();
	int k = h.size();
	for(int i = n-1; i > -1; i--)
	{
		while(h.size() >= k + 2 && p[i].left(h[sz(h) - 2], h.back())) h.pop_back();
		h.pb(p[i]);
	}
	h.pop_back();
	return h;
}
