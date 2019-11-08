void dfs0(int num,int pa)
{
    int v;
    chijos[num]=1;arrpa[num]=pa;
    lista.push_back(num);csize++;
    forr(i,0,g[num].size())
    {
        v=g[num][i];
        if (marcado[v]==1|| v==pa)continue;
        dfs0(v,num);
        chijos[num]+=chijos[v];
    }
    
}

void go(int nodo)
{

    csize=0;
    lista.clear();
    dfs0(nodo,nodo);
    
    int minn,centroide,canthijos;
    minn=csize;centroide=nodo;
    for(int num:lista)
    {
        canthijos=(csize-chijos[num]);
        for(int v:g[num])
        {
            if (v==arrpa[num]|| marcado[v])continue;
            canthijos=max(canthijos,chijos[v]);
        }
        if (minn>canthijos)
        {
            minn=canthijos;
            centroide=num;
        }
    }

    operaciones(centroide,csize); //operaciones
        marcado[centroide]=1;
    
    for(int v:g[centroide])
    {
        if (marcado[v])continue;
        go(v);
    }
}
