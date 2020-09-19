struct node
{
	int siz, tam;
	char ch;
	node *link;
	map<char, node*> child;
	node(int siz, char ch) : siz(siz), link(0), ch(ch) {}
};
typedef node* pnode;
pnode nodes[tam], ce, meu;
void create(string s)
{
	meu = new node(-1, '#');
	ce = new node(0, '%');
	meu->link = ce->link = meu;
	pnode act = meu, suf;
  char po;
	fore(i, 0, s.size())
	{
		while(act->siz == i || s[i - act->siz - 1] != s[i])
			act = act->link;
		po = s[i];
		if(!act->child.count(po))
		{
			act->child[po] = new node(act->siz + 2, s[i]);
			suf = act->link;
			act = act->child[po];
			while(s[i - suf->siz - 1] != s[i])
				suf = suf->link;
			act->link = act->siz == 1 ? ce : suf->child[po];
			act->tam = act->link->tam + 1;
		}
		else
			act = act->child[po];
		nodes[i] = act;
	}
}
