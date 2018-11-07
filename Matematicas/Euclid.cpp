
ll gcd(ll a, ll b){return b==0? a:gcd(b,a%b);}

int x, y, d;
void extendedEuclid(int a, int b)//ecuacion diofantica ax + by = 1
{
	if(b==0) {x=1; y=0; d=a; return;}
	extendedEuclid(b,a%b);
	int x1=y;
	y = x-(a/b)*y;
	x=x1;
}