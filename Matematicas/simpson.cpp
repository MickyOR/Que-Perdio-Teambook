double simpson(double f(double), double a, double b)
{
	int n = 100000;
	double s = f(a) + f(b);
	double h = (b - a) / n;
	fore(i, 1, n)
		s += ((i & 1) ? 4  : 2) * f(a + h * i);
	return s * (h / 3);
}
