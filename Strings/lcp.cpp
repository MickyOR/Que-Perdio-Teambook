vector<int> lcp(string &s, vector<int> &sa)
{
	int n = s.size(), k, z = 0;
	vector<int> sa1(n), lcp(n);
	fore(i, 0, n) sa1[sa[i]] = i;
	fore(i, 0, n)
	{
		k = sa1[i];
		if(k < n)
			while(s[i + z] == s[sa[k+1] + z])
				z++;
		lcp[k] = z;
		z = max(z-1, 0);
	}
	return lcp;
}
