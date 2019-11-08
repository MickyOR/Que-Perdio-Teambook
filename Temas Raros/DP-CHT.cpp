
struct sol{
    ll ganancia,media,dia;
    sol(){}
    ll get(ll diaf)//review
    {
        return ganancia+(diaf-dia)*media;
    }
    bool operator <(const sol &otro)const
    {
        return mp(media,0)<mp(otro.media,0);
    }
 
    ll overpass(sol &izq)
    {
        
        ll iz=max(izq.dia,dia)+1,der=iz,mid;
 
        while(get(der-1)>izq.get(der-1)){
            der*=2;
        }
 
        while(iz+1<der)
        {
            mid=(iz+der)/2;
            if (get(mid-1)<=izq.get(mid-1))
                der=mid;
            else
                iz=mid;
        }
        return der;
    }
};
multiset<sol> sols;

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("work.out","w",stdout);
    ll n,c,d;
    int caso=1;
    while(cin>>n>>c>>d && n)
    {
        sols.clear();
        ll dia,precio,resale,media;
    map<ll,vector<iii> > v;
    forr(i,0,n)
    {
        cin>>dia>>precio>>resale>>media;
        v[dia].pb(mp(precio,mp(resale,media)));
        
    }
    
    //multiset<sol> sols;
    multiset<sol>:: iterator ite1;
    multiset<sol>:: iterator ite2;
    sol otro1,otro2,nuevo;
    ll acosto;
    forit(it,v)
    {
        dia=it->F;
        while (sols.size()>=2)
        {
            ite1=sols.begin();
            ite2=ite1;ite2++;
            otro1=(*ite1);
            otro2=(*ite2);
            if (otro1.get(dia-1LL)<=otro2.get(dia-1LL)){
 
                sols.erase(ite1);
            }
            else
                break;
        }
        acosto=c;
        otro1=(*sols.begin());
        if (sols.size()>0)
            acosto=max(c,otro1.get(dia-1));
 
 
        forr(i,0,it->S.size())
        {
            //cout<<"m1";
            precio=it->S[i].F;
            resale=it->S[i].S.F;
            media=it->S[i].S.S;
            if (precio>acosto){
                
                continue;
                
            }
            nuevo.ganancia=acosto-precio+resale;
            nuevo.media=media;
            nuevo.dia=dia;
            bool nowork=false;
            while(sols.size()>0)
            {
                ite1=sols.upper_bound(nuevo);
                if (ite1==sols.begin())break;
                ite1--;
                otro1=(*ite1);
                if (otro1.media==nuevo.media)
                {
                    if (nuevo.get(dia)>=otro1.get(dia))
                        sols.erase(ite1);
                    else{
                        nowork=1;
                        break;
                    }
                }
                else break;
            }
            if (nowork)continue;
            ite1=sols.upper_bound(nuevo);
            if (ite1!=sols.begin() && ite1!=sols.end())
            {
                ite2=ite1;ite2--;
                otro1=(*ite1);
                otro2=(*ite2);
                if (otro2.overpass(nuevo)>=nuevo.overpass(otro1)){
                    continue;
                }
            }       
 
            while(sols.size()>1 )
            {
                ite1=sols.upper_bound(nuevo);
                ite2=ite1;ite2++;
                if (ite2!=sols.end() && ite1!=sols.end())
                {
                    otro1=(*ite1);
                    otro2=(*ite2);
                    if (nuevo.overpass(otro1)<=otro1.overpass(otro2))
                        break;
                    sols.erase(ite1);
                }
                else
                    break;
            }
            
            while(sols.size()>1)
            {
                ite1=sols.upper_bound(nuevo);
                if (ite1==sols.begin())break;
                ite1--;
                ite2=ite1;ite2--;
                if (ite1==sols.begin())break;
                otro1=(*ite1);
                otro2=(*ite2);
                if (otro2.overpass(otro1)<otro1.overpass(nuevo))
                    break;
                else{
                    sols.erase(ite1);
                }
            }
            sols.insert(nuevo);
        }
 
    }
    ll maxx=c;
    forit(ite,sols)
    {
        nuevo=(*ite);
        //if (nuevo.dia!=d)
        maxx=max(maxx,nuevo.get(d));
    }
    cout<<"Case "<<caso++<<": ";
    cout<<maxx<<endl;
    }
    
}
// PLUS ULTRA!
