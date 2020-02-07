// Cat[n] = C(2n, n) / (n + 1)
// Cat[n+1] = Cat[n] * 2 * (2 * n + 1) / (n + 2)
// Cat[n] = Cat[n-1] * 2 * (2 * n - 1) / (n + 1)

ll cata(int n)
{
	ll bino[n+1];
	memset(bino,0ll,sizeof(bino));
	bino[0]=1;
	for(int i=1;i<=2*n;i++)
		for(int j=min(i,n);j>0;j--)
			bino[j]+=bino[j-1];
	return bino[n]/(n+1);
}

int main()
{
	ll scat[26];//super catalan
	scat[0]=scat[1]=1;
	for(int i=2;i<26;i++)
		scat[i]=(3*(2*i-1)*scat[i-1]-(i-2)*scat[i-2])/(i+1);
	ll cat[26];
	for(int i=0;i<26;i++)
		cat[i]=cata(i);
	return 0;
}
