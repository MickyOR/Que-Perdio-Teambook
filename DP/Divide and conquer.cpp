/*
DP[i][j] = min( DP[i-1][k] + C[k][j] )
K[i][j] <= K[i][j+1]
*/

ll lastDP[tam], DP[tam];
int C[tam][tam]; // Cambiar a una funcion de costo si pre-procesar ocupa mucha memoria

void DC(int b, int e, int KL, int KR)
{
	int mid = (b + e) / 2;
	pair<ll, int> best = mp(-1, KL);

	for (int k = KL; k < min(mid, KR+1); k++)
	{
		best = max( best, mp(lastDP[k] + C[k+1][mid], k) );
	}

	DP[mid] = best.first;
	int K = best.second;

	if (b <= mid-1)
		DC(b, mid-1, KL, K);
	if (mid+1 <= e)
		DC(mid+1, e, K, KR);
}
