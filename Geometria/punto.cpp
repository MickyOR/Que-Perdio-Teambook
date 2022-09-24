/*typedef double T;
typedef complex<T> pt;
#define x real()
#define y imag()*/

//typedef long long ll;
//typedef long double ll;

struct point
{
	ll x, y;
	point() {}
	point(ll x, ll y): x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	point operator +(point p) {return point(x + p.x, y + p.y);}
	ll sq() {return x * x + y * y;}
	double abs() {return sqrt(sq());}
	ll operator ^(point p) {return x * p.y - y * p.x;}
  	ll operator *(point p) {return x * p.x + y * p.y;}
  	point operator *(ll a) {return point(x * a, y * a);}
	bool operator <(const point& p) const {return x == p.x ? y < p.y : x < p.x;}
	bool left(point a, point b) {return ((b - a) ^ (*this - a)) >= 0;}
	ostream& operator<<(ostream& os) {
		return os << "("<< x << "," << y << ")";
	}

};

void polarSort(vector<point>& v) {
  sort(v.begin(), v.end(), [] (point a, point b) {
    const point origin{0, 0};
    bool ba = a < origin, bb = b < origin;
    if (ba != bb) { return ba < bb; }
    return (a^b) > 0;
  });
}
