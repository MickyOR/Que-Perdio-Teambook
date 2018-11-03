
int n;
vector<int> grafo[tam];
int hijos[tam],padre[tam];bool marcado[tam];
void dfshijos(int num,int pad)
{
    //<<num<<endl;
    hijos[num]=1;
    padre[num]=pad;
    int num2;
    for (int i = 0; i < grafo[num].size(); ++i)
    {
        num2=grafo[num][i];
        if (num2==pad|| marcado[num2]==true)continue;
        dfshijos(num2,num);
        hijos[num]+=hijos[num2];
    }
}
void operaciones(int num,int compsize);
void descomponer(int num)
{
    dfshijos(num,num);
    queue<int> cola;
    cola.push(num);
    int maxx,minn,centroide,num2,auxnum;
    minn=hijos[num];centroide=num;
    int compsize=0;
    while(!cola.empty())
    {   compsize++;
        auxnum=cola.front();cola.pop();
        maxx=hijos[num]-hijos[auxnum];
        for (int i = 0; i < grafo[auxnum].size(); ++i)
        {
            num2=grafo[auxnum][i];
            if (padre[auxnum]==num2|| marcado[num2]==1)continue;
            maxx=max(maxx,hijos[num2]);
            cola.push(num2);
        }
        if (minn>maxx)
        {
            minn=maxx;
            centroide=auxnum;
        }
    }
    //cout<<centroide<<" "<<compsize<<endl; para revisar
    operaciones(centroide,compsize);
    marcado[centroide]=1;
    for (int i = 0; i < grafo[centroide].size(); ++i)
    {
        num2=grafo[centroide][i];
        if (marcado[num2]==1)continue;
        descomponer(num2);
    }
}
// memset(marcado,false,sizeof marcado);
