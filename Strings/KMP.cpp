vector<int> kmp(string s)
{
	int n = s.size();
	vector<int> pi(n, 0);
	for(int i = 1; i < n; i++)
	{
    	int j = pi[i-1];
    	while(j > 0 && s[j] != s[i])
      		j = pi[j-1];
    	if(s[j] == s[i])
      		j++;
    	pi[i] = j;
  	}
  	return pi;
}
