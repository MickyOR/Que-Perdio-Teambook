    #include <bits/stdc++.h>
    //#include <ext/pb_ds/assoc_container.hpp>
    //#include <ext/pb_ds/tree_policy.hpp>
    #define mp              make_pair
    #define pb              push_back
    #define all(a)          (a).begin(), (a).end()
    #define sz(a)           a.size()
    #define srt(a)          sort(all(a))
    #define mem(a, h)       memset(a, (h), sizeof(a))
    #define f               first
    #define s               second
    #define forr(i, b, e)   for(int i = b; i < e; i++)
    #define forg(i, b, e, m)    for(int i = b; i < e; i+=m)
    //int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
     
    using namespace std;
    //using namespace __gnu_pbds;
     
    typedef long long       ll;
    typedef unsigned long long      ull;
    typedef pair<int, int>  ii;
    typedef vector<int>     vi;
    typedef vector<ii>      vii;
    typedef vector<ll>      vll;
    //typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
    //find_by_order kth largest  order_of_key <
    const int tam = 1200;
    const int MOD = 1e9+7;
    const int MOD1 = 988244535;
    const double EPS = 1e-9;
    const double PI = acos(-1);
    #define forite(it,a,b) for(auto it=a;it!=b;it++)
    vector<int> g[tam],ginv[tam];
     
    int n,m;
    int neg(int num)
    {
        if (num>n)
            return num-n;
        return num+n;
    }
     
    void add(int iz,int der)
    {
        g[iz].pb(der);
        g[neg(der)].pb(neg(iz));
     
        ginv[der].pb(iz);
        ginv[neg(iz)].pb(neg(der));
    }
    bool vis[tam],valor[tam];vector<int> orden;
    void dfs0(int num)
    {
        vis[num]=1;
        for(int hijo:g[num])
        {
            if (!vis[hijo])
                dfs0(hijo);
        }
        orden.pb(num);
    }
    int componente[tam],scc;
    void dfs1(int num)
    {
        vis[num]=1;
        componente[num]=scc;
        for(int hijo: ginv[num])
        {
            if (!vis[hijo])
            dfs1(hijo);       
        }
    }
    int main()
    {
        ios::sync_with_stdio(0); cin.tie(0);
        
        cin>>n>>m;
        int iz,der,peso;
        forr(i,0,m)
        {
            cin>>iz>>der>>peso;
            if (peso==1)
            {
                add(iz,der);
                add(der,iz);
            }
            else
            {
                add(neg(iz),der);
                add(iz,neg(der));
            }
        }
        memset(vis,0,sizeof vis);
        forr(i,1,2*n+1)
        {
            if (!vis[i])
                dfs0(i);
        }
        memset(vis,0,sizeof vis);
        scc=0;
     
        forr(i,0,orden.size())
        {
            iz=orden[orden.size()-1-i];
            if (!vis[iz]){
                scc++;
                dfs1(iz);
            }
        }
        bool invalid=false;
        vector<int> respuesta;
        for(int i=1;i<=n;i++)
        {
            //cout<<componente[i]<<' '<<componente[i+n]<<endl;
            if (componente[i]==componente[i+n])
                invalid=1;
            if (componente[i]>componente[i+n])
            {
                respuesta.pb(i);
                valor[i]=1;
            }
            else valor[i]=0;
        }
        if (invalid==false)
        {
            cout<<respuesta.size()<<endl;
            for(int num:respuesta)
                cout<<num<<" ";
        }
        else
        {
            cout<<"Impossible\n";
        }
    }
    // read the question correctly (is y a vowel? what are the exact constraints?)
    // look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2
