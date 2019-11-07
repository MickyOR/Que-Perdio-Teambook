struct item{
    int key, pri, siz;
    item *l, *r;
    item() {}
    item(int key) : key(key), siz(1), pri(rand()) {}
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
void split(pitem t, pitem &l, pitem &r, int val)
{
    if(!t) r = l = NULL;
    else if(t->key < val) split(t->r, t->r, r, val), l = t;
    else split(t->l, l, t->l, val), r = t;
    up_sz(t);
}
void merge(pitem &t, pitem l, pitem r)
{
    if(!l || !r) t=(l?l:r);
    else if(l->pri >= r->pri) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l),t=r;
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
        print(t->l);
        cout<<t->key<<' ';
        print(t->r);
    }
}
