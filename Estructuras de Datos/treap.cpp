#include <bits/stdc++.h>

using namespace std;
struct node{
    int key, pri, siz;
    node *l, *r;
};
typedef node* pnode;
int sz(pnode t)
{
    return (t?t->siz:0);
}
void up_sz(pnode t)
{
    if(t) t->siz = sz(t->l) + 1 + sz(t->r);
}
void split(pnode t, pnode &l, pnode &r, int val)
{
    if(!t) r = l = NULL;
    else if(t->key <= val) split(t->r, t->r, r, val), l = t;
    else split(t->l, l, t->r, val), r = l;
    up_sz(t);
}
void merge(pnode &t, pnode l, pnode r)
{
    if(!l || !r) t=(l?l:r);
    else if(l->pri >= r->pri) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l),t=r;
    up_sz(t);
}
void insert(pnode &t, pnode it)
{
    if(!t) t = it;
    else if(it->pri > t->pri) split(t, it->l, it->r, it->key), t = it;
    else insert((t->key <= it->key?t->l:t->r), it);
    up_sz(t);
}
void erase(pnode &t, int val)
{
    if(!t) return;
    else if(t->key == val) {pnode temp = t; merge(t, t->l, t->r); free(temp);}
    else erase((t->key <= val?t->l:t->r),val);
    up_sz(t);
}
pnode init(int val)
{
    pnode ret = (pnode)malloc(sizeof(node));
    ret->key = val, ret->siz = 1, ret -> pri = rand(), ret->l = ret->r = NULL;
    return ret;
}
