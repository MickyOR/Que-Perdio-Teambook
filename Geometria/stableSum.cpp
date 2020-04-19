struct stableSum {
  int cnt = 0;
  vector<double> v, prefs{0};
  void operator += (double a) {
    assert(a >= 0);
    int s = ++cnt;
    while(s % 2 == 0) {
      a += v.back();
      v.pop_back(), pref.pop_back();
      s /= 2;
    }
    v.pb(a);
    pref.pb(pref.back() + a);
  }
  double val() {return pref.back();}
};
