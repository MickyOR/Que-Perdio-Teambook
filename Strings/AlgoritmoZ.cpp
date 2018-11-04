typedef vector<ll>      vll;
vector<int> alz(string a)
{
	int n = a.size();
	vi res(n);
	int left=0,right=0;
	for(int k=1;k<n;k++)
	{
		if(right<k)
		{
			right=left=k;
			while(right<n&&a[right]==a[right-left])
				right++;
			res[k] = right - left;
			right--;
		}
		else
		{
			int k1 = k - left;
			if(res[k1]< right - k + 1)
				res[k] = res[k1];
			else
			{
				left=k;
				while(right<n&&a[right] == a[right-left])
					right++;
				res[k] = right - left;
				right--;
			}
		}
	}
	return res;
}
int main()
{
	string a,b;
	cin>>a>>b;
	vector<int> v = alz(b+'$'+a);
	int ta = a.size();
	int tb = b.size();
	ta = ta + tb + 1;
	for(int i=tb+1;i<ta;i++)
	{
		if(v[i]==tb)
			cout<<i-tb-1<<endl;
	}
	return 0;
}