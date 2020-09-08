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

const int tam = 1e5 + 10;
int aut[tam][26];

void genAut(string &s) {
    clr(aut, 0);
    vi pi = kmp(s);
    int n = s.size();
    fore(i, 0, n) {
        aut[i][s[i]-'a'] = i+1;
    }
    fore(i, 0, n+1) {
        for (int c = 0; c < 26; c++) {
            if (aut[i][c]) continue;
            if (i < n && s[i] == 'a' + c) aut[i][c] = i+1;
            else if (i > 0) aut[i][c] = aut[pi[i-1]][c];
            else aut[i][c] = 0;
        }
    }
}
