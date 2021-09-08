struct bin_coef {
  vector<vi> dp;
  int mod;
  bin_coef(int maxN, int maxK, int mod) : dp(maxN+1, vi(maxK+1, -1)), mod(mod) {}
  int nck(int n, int k) {
    if (n < k) return 0;
    if (n == k || k == 0) return 1;
    if (k == 1) return n; // n>=mod ?
    int &res = dp[n][k];
    if (res != -1) return res;
    res = nck(n-1, k) + nck(n-1, k-1);
    res = (res >= mod ? res-mod : res);
    return res;
  }
};
