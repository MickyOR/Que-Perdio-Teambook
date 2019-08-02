vector<int> lcp(string &s, vector<int> &sa)
{
	int n = s.size(), k, z = 0;
	vector<int> sa1(n), lcp(n);
	fore(i, 0, n)
		sa1[sa[i]] = i;
	fore(i, 0, n)
	{
		k = sa1[i];
		if(k < n-1)
		{
			lcp[k] = z;
			while(s[sa[k] + lcp[k]] == s[sa[k+1] + lcp[k]])
				lcp[k]++;
		}
		z = max(0, lcp[k] - 1);
	}
	return lcp;
}
