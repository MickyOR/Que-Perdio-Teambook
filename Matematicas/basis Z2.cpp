const int N=905;
struct Gaus
{
    bitset<N> basis[N];
    bool val[N];
    int cmp;
    bool pos;
    Gaus(){
        cmp=0;
        pos=1;
    }
    void ad(bitset<N> nuevo,bool ult)
    {
        for(int i=N-1;i>=0;i--)
        {
            if (nuevo[i])
            {
                if (basis[i][i])
                    nuevo^=basis[i],ult^=val[i];
                else
                {
                    basis[i]=nuevo,val[i]=ult;
                    cmp++;
                    return;
                }
            }
        }
        if (ult)
            pos=0;
    }

};  
