// stir[n][k] cantidad de formas de paritcionar un conjunto de n elementos en k conjuntos
// bell[n] cantidad de formas de particionar un conjunto
ll stir[tam][tam];
ll bell[tam];
void stirBell()
{
  fore(i, 1, tam)
  {
    stir[i][1] = 1;
    fore(j, 2, 1010)
    {
      stir[i][j] = (j * stir[i - 1][j] % MOD + stir[i - 1][j - 1]) % MOD;
    }
  }
  fore(i, 1, tam)
  {
    fore(j, 1, i + 1)
      bell[i] = (bell[i] + stir[i][j]) % MOD;
  }
}
