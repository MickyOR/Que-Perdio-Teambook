struct item{
    int key, siz;
    bool lef;
    item *l, *r, *p;
    item() {}
    item(int key) : key(key), siz(1), l(0), r(0), p(0) {}
};
typedef item* pitem;
int sz(pitem t)
{
    return (t?t->siz:0);
}
void up_sz(pitem t)
{
    if(t) t->siz = sz(t->l) + 1 + sz(t->r);
}
void rotate(pitem t)
{
	if(t->lef)
	{
		t->p->l = t->r;
		if(t->r)
			t->r->p = t->p, t->r->lef = true;
		t->r = t->p;
	}
	else
	{
		t->p->r = t->l;
		if(t->l)
			t->l->p = t->p, t->l->lef = false;
		t->l = t->p;
	}
	swap(t->lef, t->p->lef);
	t->p->lef ^= 1;
	pitem ax = t->p->p;
	t->p->p = t;
	up_sz(t->p);
	up_sz(t);
	t->p = ax;
}
void splay(pitem t)
{
	while(t->p)
	{
		if(t->p->p)
		{
			if(t->lef == t->p->lef)
				rotate(t->p);
			else
				rotate(t);
		}
		rotate(t);
	}
}
pitem search(pitem t, int val)
{
	if(val > t->key && t->r)
		return search(t->r, val);
	if(val < t->key && t->l)
		return search(t->l, val);
	splay(t);
	return t;
}
void split(pitem t, pitem &l, pitem &r, int val)
{
	if(!t) {l = r = 0; return;}
	t = search(t, val);
	if(t->key >= val)
	{
		l = t->l;
		t->l = 0;
		r = t;
		if(l) l->p = 0;
	}
	else
	{
		r = t->r;
		t->r = 0;
		l = t;	
		if(r) r->p = 0;
	}
	up_sz(l);
	up_sz(r);
}
void merge(pitem &t, pitem l, pitem r)
{
	if(!l || !r) t = l ? l : r;
	else
	{
		t = search(l, MOD);
		r->p = t;
		r->lef = false;
		t->r = r;
	}
	up_sz(t);
}
void erase(pitem t)
{
    if(t)
    {
        erase(t->l);
        erase(t->r);
        delete t;
    }
}
void print(pitem t)
{
    if(t)
    {
    	cout<<'(';
        print(t->l);
        cout<<t->key<<' ';
        print(t->r);
        cout<<')';
    }
}
