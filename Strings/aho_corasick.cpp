struct vertex
{
	int p, super = -1, link = -1;
	map<char, int> next, go;
	char pch;
	vector<int> leaf;
	vertex(int p = -1, char pch = '$') : p(p), pch(pch) {};
};
vector<vertex> t;
void aho_init()
{
	t.clear(); t.pb(vertex());
}
void add_string(string &s, int in)
{
	int v = 0;
	for(char ch : s)
	{
		if(!t[v].next.count(ch))
		{
			t[v].next[ch] = t.size();
			t.emplace_back(v, ch);
		}
		v = t[v].next[ch];
	}
	t[v].leaf.pb(in);
}
int go(int v, char c);
int suff(int v)
{
	if(t[v].link != -1) return t[v].link;
	if(v == 0 || t[v].p == 0)
		return t[v].link = 0;
	return t[v].link = go(suff(t[v].p), t[v].pch);
}
int go(int v, char c)
{
	if(!t[v].go.count(c))
		if(t[v].next.count(c)) t[v].go[c] = t[v].next[c];
		else t[v].go[c] = go(suff(v), c);
	return t[v].go[c];
}
