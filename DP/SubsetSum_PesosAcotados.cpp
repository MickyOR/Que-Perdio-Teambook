// Solucion a Subset Sum Problem del paper Linear Time Algorithms for Knapsack Problems with Bounded Weights
// Si w_i <= W para todo i, la complejidad es O(n*W) en tiempo y O(n+W) en espacio
// Se asume que sum(w_i) > C y que w_i <= C
struct balsub {
  int n;    // cantidad de elementos
  vi w;     // lista de pesos
  int c;    // capacidad maxima
  int maxW; // peso del maximo elemento

  int wBreak;       // peso en el break solution
  int breakPoint;   // b, el break solution usa [1,b-1]
  vi s;             // maximo s para cada {t, mu}
  vi lastS;         // en cada paso solo nos importa t y t-1
  int minMu, maxMu; // C-W+1 a C+W

  // w se pasa con 0-index, pero la solucion usa 1-index despues
  int init(int n, vi &w, int c) {
    this->n = n;
    this->w = w;
    this->c = c;
    maxW = 0;
    for (int x : w) {
      maxW = max(maxW, x);
    }
    minMu = c - maxW + 1;
    maxMu = c + maxW;
    s.resize    (maxMu - minMu + 1);
    lastS.resize(maxMu - minMu + 1);
    wBreak = 0;
    for (int i = 0; i < n; ++i) {
      breakPoint = i+1;
      if (wBreak + w[i] > c) break;
      wBreak += w[i];
    }
  }

  int solve() {
    for (int mu = c - maxW + 1; mu <= c; ++mu) {
      lastS[mu-minMu] = 0;
    }
    for (int mu = c+1; mu <= c + maxW; ++mu) {
      lastS[mu-minMu] = 1;
    }
    lastS[wBreak-minMu] = breakPoint;
    for (int t = breakPoint; t <= n; ++t) {
      for (int mu = c - maxW + 1; mu <= c + maxW; ++mu) {
        s[mu-minMu] = lastS[mu-minMu];
      }
      for (int mu = c - maxW + 1; mu <= c; ++mu) {
        int muPrime = mu + w[t-1];
        s[muPrime-minMu] = max(s[muPrime-minMu], lastS[mu-minMu]);
      }
      for (int mu = c + w[t-1]; mu >= c+1; --mu) {
        for (int j = s[mu-minMu]-1; j >= lastS[mu-minMu]; --j) {
          int muPrime = mu - w[j-1];
          s[muPrime-minMu] = max(s[muPrime-minMu], j);
        }
      }
      for (int mu = c - maxW + 1; mu <= c + maxW; ++mu) {
        lastS[mu-minMu] = s[mu-minMu];
      }
    }
    int z = 0;
    for (int mu = c - maxW + 1; mu <= c; ++mu) {
      if (s[mu-minMu] > 0) {
        z = max(z, mu);
      }
    }
    return z;
  }
};
