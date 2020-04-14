vector<vector<ll> > mat;
vector<vector<ll> > ans;
const ll MOD=1e9+7;
void mult(vector<vector<ll> > m1, vector<vector<ll> > m2)
{
  if(m1[0].size()!=m2.size())  
    assert(false);
  ans.clear();
  ll answer=0;
  forr(i,0,m1.size())
  {
    vector<ll> fila;
    forr(j,0,m2[0].size())
    {
      answer=0;
      forr(k,0,m2.size())
      {
        answer = (answer + m1[i][k] * m2[k][j]) % MOD;
      }
      fila.pb(answer);
    }
    ans.pb(fila);
  }
}
void pot(vector<vector<ll> > base,ll exp)
{
  
  vector<vector<ll> > res(4,vector<ll>(4,0));
  forr(i,0,4)
  res[i][i]=1;
  while(exp)
  {
    if (exp&1)
    {
      mult(res,base);
      res=ans;
    }
    mult(base,base);
    base=ans;
    exp/=2;
  }
  ans=res;
}
