/*
Basado en problema: Minimo costo de cortar una barra en K lugares pre-definidos
                    Costo de corte: largo de la barra que se esta cortando
                    
A[i] -> posicion del i-esimo corte, A[0] = 0, A[n-1] = Largo total
DP[i][j] = min( DP[i][k] + DP[k][j] ) + C[i][j], para i < k < j donde C[i][j] es el largo de la barra A[i] <-> A[j]
K[i][j-1] <= K[i][j] <= K[i+1][j]
*/

// Cambiar C[i][j] a una funcion de costo si pre-calcular todos los valores es muy costoso

fore(sz, 0, n)
{
  for (int i = 0; i + sz < n; i++)
  {
    int j = i+sz;
    // CASOS BASE
    if (sz <= 1) // Barra inexistente o con cero cortes en medio
    {
      DP[i][j] = 0;
      continue;
    }
    if (sz == 2) // Barra con un solo corte posible en medio
    {
      K[i][j] = i+1;
      DP[i][j] = C[i][j];
      continue;
    }
    int KL = K[i][j-1];
    int KR = K[i+1][j];
    DP[i][j] = INF;
    for (int k = KL; k <= KR; k++)
    {
      int newVal = DP[i][k] + DP[k][j] + C[i][j];
      if (newVal < DP[i][j])
      {
        K[i][j] = k;
        DP[i][j] = newVal;
      }
    }
  }
}
