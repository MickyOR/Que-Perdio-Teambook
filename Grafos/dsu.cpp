#define tam 1<<21
#define offset 200056
 
const ll MOD=1e9+7;
vector<int> g[tam];
int viz[tam],vder[tam],vtree[tam],depth[tam],csize[tam],cant[tam],vpa[tam];
int cuniv;
void dfs0(int num)
{
    vtree[cuniv]=depth[num];    //.-.
    viz[num]=cuniv++;
    csize[num]=1;
    for(int v:g[num])
    {
        if (depth[v]==-1){
            vpa[v]=num;
            depth[v]=depth[num]+1,dfs0(v),csize[num]+=csize[v];
        }
    }
    vder[num]=cuniv;
}
int amax,apos;
int answer[tam];
void dsu(int num,bool keep)
{
    int maxx,bigchild;
    maxx=bigchild=-1;
    for(int v:g[num])
    {
        if (v==vpa[num])continue;
        if (csize[v]>maxx)
        {
            maxx=csize[v];
            bigchild=v;
        }
    }
    
    for(int v:g[num])
    {
        if (v==vpa[num]|| v==bigchild)continue;
        dsu(v,0);
    }
    if (bigchild!=-1)
        dsu(bigchild,1);
    
    int posini=viz[num];
    cant[vtree[posini]]++;

    if (cant[vtree[posini]]>=amax)
        amax=cant[vtree[posini]],apos=vtree[posini];
    for(int v:g[num])
    {
        if (v==vpa[num]|| v==bigchild)continue;
        forr(i,viz[v],vder[v])
        {
            cant[vtree[i]]++;
            if (cant[vtree[i]]>amax)
                amax=cant[vtree[i]],apos=vtree[i];
            else if (cant[vtree[i]]==amax)
                apos=min(vtree[i],apos);
        }
    }
    answer[num]=apos;
    if (keep==0)
    {
        forr(i,viz[num],vder[num])
        {
            cant[vtree[i]]=0;
        }
        apos=amax=0;
    }
}
 
