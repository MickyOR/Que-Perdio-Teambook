struct point
{
	double x, y;
	point() {}
	point(double x, double y) : x(x), y(y){}
};
double dist(point a, point b)
{
	return hypot(a.x - b.x, a.y - b.y);
}
double cross2(point a, point b)
{
	return a.x*b.y - a.y*b.x;
}
point tovec(point a, point b)
{
	return point(b.x - a.x, b.y - a.y);
}
double cross(point a, point b, point c)
{
	return cross2(tovec(a, b), tovec(a, c));
}
bool eq(double a, double b)
{
	return fabs(a-b) < EPS;
}
point mini;
bool comp(point a, point b)
{
	point ta = tovec(mini, a);
	point tb = tovec(mini, b);
	double ana = atan2(ta.y, ta.x), anb = atan2(tb.y, tb.x);
	if(eq(ana, anb))
		return dist(a, mini) < dist(b, mini);
	return ana < anb - EPS;
}
//no hay 3 puntos colineales
vector<point> hull(vector<point> p)
{
	for(int i = 1; i < p.size(); i++)
	{
		if(eq(p[i].y, p[0].y) )
		{
			if(p[i].x < p[0].x - EPS)
				swap(p[i], p[0]);
		}
		else
		{
			if(p[i].y < p[0].y - EPS)
				swap(p[i], p[0]);
		}
	}
	mini = p[0];
	sort(++p.begin(), p.end(), comp);
	p.pb(p[0]);
	vector<point> res;
	res.pb(p[0]);
	res.pb(p[1]);
	for(int i = 2; i < p.size(); i++)
	{
		while(cross(res[res.size()-2], res.back(), p[i]) < EPS)
		{	
			res.pop_back();
		}
		res.pb(p[i]);
	}
	return res;
}
