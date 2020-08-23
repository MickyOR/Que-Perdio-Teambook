void MODUL(int &a,int mod)
{
	while(a>=mod)
		a-=mod;
}
ll pot(ll base,ll exp,ll mod)
{
	ll res=1;base%=mod;
	while(exp)
	{
		if (exp&1)res*=base,res%=mod;
		base*=base,base%=mod;
		exp>>=1LL;
	}
	return res;
}
struct NTT
{
	const int mod = 998244353; // c*2^k + 1 = 119*2^23 + 1
	// 3 es raiz primitiva de mod, root = 3^c % mod = 3^119 % mod
	const int Root = 15311432;
	// root_1 = root^-1
	const int Root_1 = 469870224;
	// 2^k
	const int root_pw = 1 << 23;
	
	vector<int> Rc,Vexp;

	void crear(int root,int n)
	{
		int m= root_pw; // 2^k => k
		ll valRc=root%this->mod,pot=1;
		while(m>n)
		{
			valRc*=valRc;
			valRc%=this->mod;
			pot*=2;
			m/=2;
		}
		Rc.clear(),Vexp.clear();

		ll actRc=1;
		forr(i,0,n)
		{
			Rc.pb(actRc),Vexp.pb(pot*i);
			actRc*=valRc;
			actRc%=this->mod;
		}
	}
	void fft(vector<int> &A,int depth)
	{
		if (A.size()==1)
		{
			 return;
		}
		vector<int> Aeven,Aodd;
		int len=A.size(),exp,expnext,posnext;

		forg(i,0,len,2)
			Aeven.pb(A[i]);
		forg(i,1,len,2)
			Aodd.pb(A[i]);

		 fft(Aeven,depth+1);
		 fft(Aodd,depth+1);

		int saltos=1<<depth;
		forr(i,0,len)
		{
			expnext=(1LL*Vexp[saltos*i]*2LL);
			MODUL(expnext,this->root_pw);
			posnext=expnext/(Vexp[1]*(1<<(depth+1)));
			A[i]=(Aeven[posnext]+1LL*Rc[saltos*i]*Aodd[posnext])%(this->mod);
		}

		
	}
	vector<int> getMul(vector<int> &a,vector<int> &b)
	{
		vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
		int n = 1;
		while (n < a.size() + b.size())
			n <<= 1;

		fa.resize(n);
		fb.resize(n);
	 	
	 	
	 	crear(Root,n);
		fft(fa, 0);
		fft(fb, 0);

		for (int i = 0; i < n; i++)
			fa[i] = (int)(1LL * fa[i] * fb[i] % this->mod);
		crear(Root_1, n);
		fft(fa,0);

		int n_1 = pot(n, this->mod-2,this->mod);
		for(int &x :fa)
		{
			x= (1LL*n_1*x)%(this->mod);
		}
		return fa;
	}
};
