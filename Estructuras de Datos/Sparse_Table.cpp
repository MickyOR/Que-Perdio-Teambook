const int tam = 1000010;
const int logTam = 21;
int n; 
int ar[tam], table[logTam][tam];
void inispar()
{
	fore(i, 0, n) table[0][i] = ar[i];
	for(int k = 0; (1 << k) < n; k++)
		for(int i = 0; i + (1 << k) < n; i++)
			table[k + 1][i] = min(table[k][i], table[k][i + (1 << k)]);
}
int query(int b, int e)
{
	int lev = 31 - __builtin_clz(e - b + 1);	
	return min(table[lev][b], table[lev][e - (1 << lev) + 1]);	
}
