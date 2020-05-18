
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
/*
a = 25, b = 18
extendedEuclid(25, 18) produces x = −5, y = 7, d = 1; or 25 × (−5) + 18 × 7 = 1.
Multiply the left and right hand side of the equation above by 839/gcd(25, 18) = 839:
25 × (−4195) + 18 × 5873 = 839.
Thus x = −4195 + (18/1)n and y = 5873 − (25/1)n.
Since we need to have non-negative x and y (non-negative number of apples and oranges),
we have two more additional constraints:
−4195 + 18n ≥ 0 and 5873 − 25n ≥ 0, or
4195/18 ≤ n ≤ 5873/25, or
233.05 ≤ n ≤ 234.92.
*/
