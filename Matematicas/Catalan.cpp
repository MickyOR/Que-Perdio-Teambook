// Catalan, parentesis balanceados, arboles binarios, triangulacion poligono convexto de n + 2 lados, caminos en grilla sin atravesar diagonal
// Cat[n] = C(2n, n) / (n + 1)
// C(n, k) es el coeficiente binomial
Cat[0] = 1;
Cat[n+1] = Cat[n] * 2 * (2 * n + 1) / (n + 2);
Cat[n] = Cat[n-1] * 2 * (2 * n - 1) / (n + 1);

// Convolucion Catalan, paréntesis balanceados en k cajas
// Catk[n] = C(2n + k - 1, n) * k / (n + k)
Catk[0] = 1;
Catk[n + 1] = Catk[n] * (2 * n + k) * (2 * n + 1 + k) / (n + 1) / (n + k + 1);
Catk[n] = Catk[n - 1] * (2 * n + k - 1) * (2 * n + k - 2) / n / (n + k);

int main()
{
	// count the number of plane trees with a given set of leaves, 
	// the number of ways of inserting parentheses into a sequence, 
	// and the number of ways of dissecting a convex polygon into smaller polygons by inserting diagonals
	ll scat[26];//super catalan
	scat[0]=scat[1]=1;
	for(int i=2;i<26;i++)
		scat[i]=(3*(2*i-1)*scat[i-1]-(i-2)*scat[i-2])/(i+1);
	ll cat[26];
	for(int i=0;i<26;i++)
		cat[i]=cata(i);
	return 0;
}
