
struct point
{
	double x,y;
	point() {x=y=0;}
	point(double X, double Y): x(X), y(Y) {}
};
double dist(point a, point b)
{
	return hypot(a.x-b.x,a.y-b.y);
}
point tovec(point a, point b)
{
	return point(b.x-a.x, b.y-a.y);
}
double cross(point a, point b)
{
	return a.x*b.y - a.y*b.x;
}
bool coolinear(point a, point b, point c)
{
	return fabs(cross(tovec(a,b), tovec(a,c))) < EPS;
}
bool ccw(point a, point b, point c)
{
	return cross(tovec(a,b),tovec(a,c)) >= 0;
}
point pivot;
bool anComp(point a, point b)
{
	if(coolinear(pivot, a, b))
		return dist(pivot, a) < dist(pivot, b);
	a = tovec(pivot, a), b = tovec(pivot, b);
	return atan2(a.y,a.x) < atan2(b.y,b.x);
}
vector<point> ch(vector<point> p)
{
	int n = p.size(), i , j;
	if(n<=3) 
	{
		if(p[0].x!=p[n-1].x||p[0].y!=p[n-1].y) p.pb(p[0]);
		return p;
	}
	int in=0;
	for(int i = 0; i< n; i++)
		if(p[i].y < p[in].y || p[i].x < p[in].x && p[i].y == p[in].y)
			in = i;
	pivot = p[in];
	for(int i = 0; i<n;i++)
	{
		cout<<p[i].x<<' '<<p[i].y<<endl;
	}
	cout<<endl;
	swap(p[0],p[in]);
	cout<<pivot.x<<'#'<<pivot.y<<endl;
	sort(++p.begin(), p.end(),anComp);
	for(int i = 0; i<n;i++)
	{
		cout<<p[i].x<<' '<<p[i].y<<endl;
	}
	cout<<endl;
	i = 2;
	vector<point> s = {p[n-1], p[0], p[1]};
	while(i < n && s.size()>0)
	{
		j = s.size();
		if(ccw(s[j-2],s[j-1],p[i]) || j == 2)
		{
			s.pb(p[i]);
			i++;
		}
		else
			s.pop_back();
	}
	return s;
}