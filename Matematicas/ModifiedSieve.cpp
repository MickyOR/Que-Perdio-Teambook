
int phi[2000001]; //eulerphi
void criba()
{
	for(int i=0;i<2000001;i++) phi[i]=i;
	for(int i=2;i<2000001;i++)
		{
			if(phi[i]==i)
				for(int j=i;j<2000001;j+=i)
					phi[j]-=phi[j]/i;
		}
}
int crib[1000001]; //number of prime factors
void criba()
{
	memset(crib,0,sizeof(crib));
	for(int i=2;i<1000001;i++)
		if(crib[i]==0)
			for(int j=i;j<1000001;j+=i)
				crib[j]++;
}