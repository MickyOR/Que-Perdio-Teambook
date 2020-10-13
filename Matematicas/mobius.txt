int mu[ tam] , is_prime [ tam]; 
void mobius(ll n)
{
	forr(i,0,n)	mu[i]=is_prime[i]=1; 
  
	for ( ll i =2; i<=n;++ i ) if ( is_prime [ i ] ) {
		for ( ll j=i ; j<n ; j += i ) {
			if ( j > i ) is_prime[j] = 0;
			if (j%(i*1LL*i)==0)mu[j]=0;
			mu[j]=-mu[j];

		}
	}
}
