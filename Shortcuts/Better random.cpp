mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 para 64 bits
cout << rng() << endl;

vi permutation(10);
fore(i, 0, 10) permutation[i] = i;
	shuffle(permutation.begin(), permutation.end(), rng);
fore(i, 0, 10) cout << permutation[i] << ' ';
