cin>>a>>b>>c>>d;
extendedEuclid(b, d);
mul = b / g * d;
b /= g;
d /= g;
cout<<(mulmod(x, mulmod(b, c, mul), mul) + mulmod(y, mulmod(d, a, mul), mul)) % mul<<' '<<mul<<'\n'; 
