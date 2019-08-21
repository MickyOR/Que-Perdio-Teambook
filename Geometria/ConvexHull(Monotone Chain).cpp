
vector<point> hull(vector<point> p)
{
	vector<point> h;
	sort(p.begin(), p.end());
	int n = p.size();
	fore(i, 0, n)
	{
		while(h.size() >= 2 && ((h.back() - h[h.size()-2]) ^ (p[i] - h[h.size()-2])) >= 0) h.pop_back();
		h.pb(p[i]);
	}
	h.pop_back();
	int k = h.size();
	for(int i = n-1; i > -1; i--)
	{
		while(h.size() >= k + 2 && ((h.back() - h[h.size()-2]) ^ (p[i] - h[h.size()-2])) >= 0) h.pop_back();
		h.pb(p[i]);
	}
	h.pop_back();
	return h;
}
