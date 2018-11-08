#include <bits/stdc++.h>

using namespace std;

const int tam = 1000010;
const int logTam = 21;

int logTable[tam];
int sparseTable[logTam][tam];
int a[tam], n; // a[] es el arreglo original. n es el tamaño del arreglo.

void makeSparseTable()
{
	logTable[0] = logTable[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		logTable[i] = logTable[ i >> 1 ] + 1;
	}

	for (int i = 0; i < n; i++)
	{
		sparseTable[0][i] = i;
	}

	for (int k = 1; (1 << k) < n; k++)
	{
		for (int i = 0; i + (1 << k) <= n; i++)
		{
			int x = sparseTable[k-1][i];
			int y = sparseTable[k-1][i - (1 << (k-1))];
			sparseTable[k][i] = a[x] <= a[y] ? x : y;
		}
	}
}

int queryST(int i, int j)
{
	int k = logTable[j - i];
	int x = sparseTable[k][i];
	int y = sparseTable[k][j - (1 << k) + 1];
	return a[x] <= a[y] ? x : y;
}

int main()
{
  return 0;
}
