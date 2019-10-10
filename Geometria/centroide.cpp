// calcula el centro de masa de un poligono antihorario
point cen(vector<point> p)
{
	double x = 0, y = 0, area = 0, ax;
	int n = p.size()-1;
	fore(i, 0, n)
	{
		ax = (p[i] ^ p[i+1]) / 2;
		area += ax;
		x += ax * (p[i].x + p[i+1].x) / 3;
		y += ax * (p[i].y + p[i+1].y) / 3;
	}
	return point(x / area, y / area);
}
