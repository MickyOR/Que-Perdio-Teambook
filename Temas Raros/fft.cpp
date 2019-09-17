typedef complex<double> cd;
double mul;
vector<cd> fft(vector<cd> a)
{
    int n = a.size();
    if(n==1) return a;
    double theta = 2.0*acos(-1)/(double)n;
    cd w = 1,
    cd wn = cd(cos(theta), mul*sin(theta));
    vector<cd> y(n), aEven(n/2), aOdd(n/2);
    for(int i=0;i<n/2;i++)
    {
        aEven[i] = a[2*i];
        aOdd[i] = a[2*i+1];
    }
    aEven = fft(aEven);
    aOdd = fft(aOdd);
    for(int i=0;i<n/2;i++)
    {
        a[i] = aEven[i] + w*aOdd[i];
        a[n/2+i] = aEven[i] - w*aOdd[i];
        w*=wn;
    }
    return a;
}
vector<cd> ffmul(vector<cd> a, vector<cd> b) //tamaño de a debe ser >= al tamaño de b
{
    int n = 2*a.size();
    while(__builtin_popcount(n)>1) n+= (n&-n);
    while(a.size()<n) a.push_back(0);
    while(b.size()<n) b.push_back(0);
    mul = 1;
    a = fft(a);
    b = fft(b);
    for(int i=0;i<n;i++)
        a[i] = a[i]*b[i];
    mul = -1;
    a = fft(a);
    for(int i=0;i<n;i++)
        a[i]/=n;
    return a;
}
