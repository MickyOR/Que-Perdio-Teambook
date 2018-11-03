struct point{
	double x,y;
	point(){x=y=0;}
	point(double X, double Y): x(X), y(Y) {}
	point operator+(point a) const
	{
		a.x+=x;
		a.y+=y;
		return a;
	}
	bool operator<(point a) const
	{
		return (a.x == x? a.y < y : a.x < x);
	}
};
double dist(point a, point b)
{
	return hypot(a.x-b.x, a.y-b.y);
}
point tovec(point a, point b)
{
	return point(b.x-a.x,b.y-a.y);
}
double norm(point a)
{
	return hypot(a.x,a.y);
}
double dot(point a, point b)
{
	return a.x*b.x + a.y*b.y;
}
double cross(point a, point b)
{
	return a.x*b.y - a.y*b.x;
}
bool ccw(point a, point b, point c)
{
	return cross(tovec(a,b),tovec(a,c)) >= 0; //depende si se acepta colinear o no
}
double an(point a, point b, point c)
{
	a = tovec(b,a), b = tovec(b,c);
	return acos(dot(a,b)/(norm(a)*norm(b)));
}
double perimeter(const vector<point> &p)
{
	double result = 0.0;
	for(int i = 0; i<p.size()-1; i++)
	{
		result += dist(p[i],p[i+1]);
	}
	return result;
}
double area(const vector<point> &p)
{
	double result = 0.0;
	for(int i=0;i<p.size()-1;i++)
	{
		result += p[i].x*p[i+1].y - p[i].y*p[i+1].x;;
	}
	return fabs(result)/2.0;
}
point lineIntersectSeg(point p, point q, point A, point B) 
{
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x * A.y - A.x * B.y;
	double u = fabs(a * p.x + b * p.y + c);
	double v = fabs(a * q.x + b * q.y + c);
	return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); 
}
vector<point> cutPolygon(point a, point b, const vector<point> &Q) 
{
	vector<point> P;
	for (int i = 0; i < (int)Q.size(); i++) {
		double left1 = cross(tovec(a, b), tovec(a, Q[i])), left2 = 0;
		if (i != (int)Q.size()-1) left2 = cross(tovec(a, b), tovec(a, Q[i+1]));
		if (left1 > -EPS) P.push_back(Q[i]); // Q[i] is on the left of ab ; left1 < EPS para la derecha
		if (left1 * left2 < -EPS) // edge (Q[i], Q[i+1]) crosses line ab
			P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
	}
	if (!P.empty() && (P.back().x != P.front().x || P.back().y != P.front().y))
		P.push_back(P.front()); // make P’s first point = P’s last point
	return P;
}
bool isConvex(const vector<point> &p)
{
	int sz = p.size();
	if(sz<=3) return false;
	bool left = ccw(p[0],p[1],p[2]);
	cout<<left<<endl;
	for(int i = 1; i < sz - 1; i++)
	{
		cout<<i<<' '<<ccw(p[i],p[i+1],p[((i+2)==sz)? 1:i+2])<<endl;
		if(ccw(p[i],p[i+1],p[((i+2)==sz)? 1:i+2])!=left)
			return false;
	}
	return true;
}
bool isIn(const vector<point> &p, point a)
{
	double ang = 0;
	int sz = p.size();
	if(sz == 0) return false;
	for(int i = 0; i<sz-1;i++)
	{
		if(ccw(a,p[i],p[i+1]))
			ang += an(p[i],a,p[i+1]);
		else
			ang -= an(p[i],a,p[i+1]);
	}
	cout<<ang<<endl;
	return fabs(ang - 2.0*PI) < EPS;
}