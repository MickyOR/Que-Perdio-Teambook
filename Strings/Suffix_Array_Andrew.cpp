string asd;
bool cmp(int a, int b)
{
	return asd[a] < asd[b];
}
vector<int> suffixa(string& s){ // O(n logn)
	int n = s.size(), cc = 0;
	asd = s;
	vector<int> sa(n), sa1(n), col(n, -1), col1(n), head(n);
	fore(i,0,n)
	{
		sa[i] = i;
		col[i] = s[i];
	}
	sort(col.begin(), col.end());
	stable_sort(sa.begin(), sa.end(), cmp);
	col[sa[0]] = head[0] = cc = 0;
	fore(i,1,n)
	{
		if(s[sa[i]] != s[sa[i - 1]])
		{
			cc++;
			head[cc] = i;
		}
		col[sa[i]] = cc;
	}
	for(int k=1;k<n;k*=2){
		fore(i, 0, n)
			sa1[head[col[(sa[i] - k + n) % n]]++] = (sa[i] - k + n) % n;
		sa = sa1;
		col1[sa[0]] = head[0] = cc = 0;
		fore(i,1,n)
		{
			if(col[sa[i]] != col[sa[i - 1]] || col[(sa[i] + k) % n] != col[(sa[i - 1] + k) % n])
			{
				cc++;
				head[cc] = i;
			}
			col1[sa[i]]=cc;
		}
		col = col1;
	}
	return sa;
}
