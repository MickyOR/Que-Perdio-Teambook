struct line
{
  double a, b, c;
  line(point p, point q)
  {
    a = p.y - q.y;
    b = q.x - p.x;
    c = -a * p.x - b * p.y;
  };
  void setOrigin(point p) { c += a * p.x + b * p.y; } //trasladar linea como si p fuera el origen
};

double det(double a, double b, double c, double d)
{
	return a * d - b * c;
}

point intersec(line a, line b) //primero estar seguro si no son paralelas
{
	double d = -det(a.a, a.b, b.a, b.b);
	return point(det(a.c, a.b, b.c, b.b) / d, det(a.a, a.c, b.a, b.c) / d);
}
