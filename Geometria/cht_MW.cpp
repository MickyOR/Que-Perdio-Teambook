//Implementacion de Machine Works

pair<pair<ll, ll>, pair<ll, ll>> ar[100010];
ll n, c, d;
ll cal(pair<ll, pair<ll, ll>> pa, ll d)
{
	return pa.s.f + (d - pa.s.s) * pa.f;
}
ld supe(pair<ll, pair<ll, ll>> pa, pair<ll, pair<ll, ll>> pe)
{
	pe.s.f -= pe.f * pe.s.s;
	pa.s.f -= pa.f * pa.s.s;
	return ((ld)pe.s.f - pa.s.f) / ((ld)pa.f - pe.f);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int cas = 0;
	while(1)
	{
		cin>>n>>c>>d;
		if(n + c + d == 0) break;
		fore(i, 0, n) cin>>ar[i].f.f>>ar[i].f.s>>ar[i].s.f>>ar[i].s.s;
		sort(ar, ar + n);
		ll res = c, mon = c;
		set<pair<ll, pair<ll, ll>>> st;
		set<pair<ll, pair<ll, ll>>>::iterator it1, it2;
		pair<ll, pair<ll, ll>> pa;
		fore(i, 0, n)
		{
			it1 = st.begin();
			while(st.size() >= 2)
			{
				it2 = st.begin();
				it2++;
				if(cal(*it2, ar[i].f.f - 1) >= cal(*it1, ar[i].f.f - 1))
				{
					st.erase(it1);
					it1 = st.begin();
				}
				else
					break;
			}
			if(st.size())
				mon = max(mon, cal(*it1, ar[i].f.f - 1));
			if(mon >= ar[i].f.s)
			{
				pa = (mp(ar[i].s.s, mp(mon - ar[i].f.s + ar[i].s.f, ar[i].f.f)));
				it1 = st.lower_bound(mp(pa.f, mp(-1e18, -1e18)));
				if(it1 != st.end())
				{
					if((*it1).f == pa.f)
					{
						if(cal(*it1, pa.s.s) >= pa.s.f)
							continue;
						else
						st.erase(it1);	
					}
				}
				it1 = st.lower_bound(pa);
				if(it1 != st.begin() && it1 != st.end())
				{
					it2 = it1;
					it2--;
					if(supe(*it2, pa) >= supe(pa, *it1))
						continue;
				}
				if(it1 != st.end())
				{
					it2 = it1;
					it2++;
					while(it2 != st.end())
					{
						if(supe(pa, *it1) < supe(*it1, *it2))
							break;
						st.erase(it1);
						it1 = st.lower_bound(pa);
						it2 = it1;
						it2++;
					}
				}
				it1 = st.lower_bound(pa);
				if(it1 != st.begin())
				{
					it1--;
					while(it1 != st.begin())
					{
						it2 = it1;
						it2--;
						if(supe(*it2, *it1) < supe(*it1, pa))
							break;
						st.erase(it1);
						it1 = st.lower_bound(pa);
						it1--;
					}
				}
				st.insert(pa);

			}
		}
		for(auto a : st)
		{
			res = max(res, cal(a, d));
		}
		cas++;
		cout<<"Case "<<cas<<": "<<res<<'\n';
	}
	return 0;
}
