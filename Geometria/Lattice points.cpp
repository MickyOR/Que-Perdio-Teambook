//calculates number of integer points (x ; y) such for 0 ≤ x < n and 0 < y ≤ ⌊k * x + b⌋
int count_lattices(double k, double b, long long n) {
    auto fk = floor(k);
    auto fb = floor(b);
    auto cnt = 0LL;
    if (k > 1 - EPS || b > 1 -EPS) {
        cnt += (fk * (n - 1) + 2 * fb) * n / 2;
        k -= fk;
        b -= fb;
    }
    auto t = k * n + b;
    auto ft = floor(t);
    if (ft > 1 - EPS) {
        cnt += count_lattices(1 / k, (t - floor(t)) / k, floor(t));
    }
    return cnt;
}
pair<double, double> kb(point a, point b)
{
	return mp((b.y - a.y) / (b.x - a.x), (a.y * b.x - a.x * b.y) / (b.x - a.x));
}
