string asd;
bool cmp(int a, int b)
{
	return asd[a] < asd[b];
}
// el table es para comparar substrings memoria nlogn
vector<vector<int>> table;
vector<int> suffixa(string &s)
{
	int n = s.size(), cc, ax;
	vector<int> sa(n), sa1(n), col(n), col1(n), head(n);
	fore(i, 0, n) sa[i] = i;
	asd = s;
	stable_sort(sa.begin(), sa.end(), cmp);
	head[0] = col[sa[0]] = cc = 0;
	fore(i, 1, n)
	{
		if(s[sa[i]] != s[sa[i-1]])
			cc++, head[cc] = i;
		col[sa[i]] = cc;
	}
	table.pb(col);
	for(int k = 1; k < n; k *= 2)
	{
		fore(i, 0, n)
		{
			ax = (sa[i] - k + n) % n;
			sa1[head[col[ax]]++] = ax;
		}
		swap(sa, sa1);
		col1[sa[0]] = head[0] = cc = 0;
		fore(i, 1, n)
		{
			if(col[sa[i]] != col[sa[i - 1]] || col[(sa[i] + k) % n] != col[(sa[i - 1] + k) % n])
				cc++, head[cc] = i;
			col1[sa[i]] = cc;
		}
		col = col1;
		table.pb(col);
	}
	return sa;
}

pair<int, int> query(int b, int e)
{
	int lev = 31 - __builtin_clz(e - b + 1);	
	return mp(table[lev][b], table[lev][e - (1 << lev) + 1]);	
}
int siz;
bool comp(int b1, int e1, int b2, int e2)
{ 
	siz = min(e1 - b1, e2 - b2);
	le = query(b1, b1 + siz), ri = query(b2, b2 + siz);
	if(le == ri)
		return e1 - b1 < e2 - b2;
	return le < ri;
}
