#include <iostream>

using namespace std;

const int tam = 1000;

int BIT[tam][tam];
int n, m;

void update(int row, int col, int val)
{
	row++; col++;
	for (int i = row; i <= n; i += (i & -i))
	{
		for (int j = col; j <= m; j += (j & -j))
		{
			BIT[i][j] += val;
		}
	}
}

int query(int row, int col)
{
	int res = 0;
	row++; col++;
	for (int i = row; i > 0; i -= (i & -i))
	{
		for (int j = col; j > 0; j -= (j & -j))
		{
			res += BIT[i][j];
		}
	}
	return res;
}
