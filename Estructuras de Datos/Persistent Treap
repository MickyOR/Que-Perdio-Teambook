#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define pitem item*
#define tam 203456
#define tamN 30000000
using namespace std;
typedef long long ll;
struct item
{
    ll tot;
    int key,cnt;
    pitem l;
    pitem r;    
    item(){l=r=NULL;}
    item(int key):key(key),l(0),r(0){
        tot=key;
        cnt=1;
    }
};
int cnt(pitem t){return t?t->cnt:0;}
ll gtot(pitem t){return t?t->tot:0;}
void upd_cnt(pitem t)
{
    if (!t)return;
    t->cnt=cnt(t->l)+cnt(t->r)+1;
    t->tot=t->key+gtot(t->l)+gtot(t->r);
}
void splitat(pitem newT,pitem t,pitem &l,pitem &r,int key)
{
    if (!t)
        return void(l=r=NULL);
    (*newT)=(*t);//.-.
    int cur_at=cnt(t->l);
    if (cur_at>key)
        newT->l=new item(),splitat(newT->l,t->l,l,newT->l,key),r=newT;
    else
        newT->r=new item(),splitat(newT->r,t->r,newT->r,r,key-cur_at-1),l=newT;
    upd_cnt(newT);
}
void merge(pitem &newT,pitem l,pitem r)//.-.
{
    if (!l && !r)   return void(newT=NULL);
    if (!l||!r)
        return void((*newT)=l?(*l):(*r));

    int prior=rand()%(cnt(l)+cnt(r));//andrew_part
    if (prior<cnt(l))
        (*newT)=(*l),newT->r=new item(),merge(newT->r,l->r,r);
    else
        (*newT)=(*r),newT->l=new item(),merge(newT->l,l,r->l);
    upd_cnt(newT);
}
ll query(pitem t,int iz,int der,int &riz,int &rder)
{
    if (!t)return 0;
    if (iz>rder|| der<riz)return 0;
    if (iz>=riz&& der<=rder)
        {
            return t->tot;
        }
    return query(t->l,iz,cnt(t->l)+iz,riz,rder)+
            query(t->r,cnt(t->l)+iz+1,der,riz,rder)+(((cnt(t->l)+iz>=riz&& cnt(t->l)+iz<=rder)?t->key:0));
}
