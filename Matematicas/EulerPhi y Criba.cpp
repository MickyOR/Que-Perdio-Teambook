bitset<100000> bi;
vi primos;
vector<ll> pric;
void criba()
{
	bi.set();
	for(int i=2;i<100000;i++)
		if(bi[i])
		{
			for(int j=i+i;j<100000;j+=i)
				bi[j]=0;
			primos.push_back(i);
			pric.push_back((ll)i*(ll)i);
		}
}
int euler(int n)
{
	int res=n;
	for(int i=0;pric[i]<=n;i++)
	{
		if(n%primos[i]==0)
		{
			res-= res/primos[i];
			while(n%primos[i]==0) n/=primos[i];
		}
	}
	if(n!=1) res-=res/n;
	return res;
}