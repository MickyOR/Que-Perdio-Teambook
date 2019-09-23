struct quemin
{
	stack<pair<int,int>> bo, to;
	void push(int n)
	{
		if(bo.empty())
			bo.push(mp(n, n));	
		else
			bo.push(mp(n, min(bo.top().s, n)));
	}
	void pop()
	{
		if(to.empty())
		{
			while(!bo.empty())
			{
				if(to.empty())
					to.push(mp(bo.top().f, bo.top().f));
				else
					to.push(mp(bo.top().f, min(bo.top().f, to.top().s)));
				bo.pop();
			}
		}
		to.pop();
	}
	int mini()
	{
		int mini = MOD;
		if(!bo.empty())
			mini = bo.top().s;
		if(!to.empty())
			mini = min(mini, to.top().s);
		return mini;
	}
};

struct quemin
{
	pair<int,int> bo[100010], to[100010];
	int boto = -1, toto = -1, ax;
	void push(int n)
	{
		ax = boto + 1;
		if(boto == -1)
			bo[ax] = mp(n, n);	
		else
			bo[ax] = mp(n, min(bo[boto].s, n));
		boto++;
	}
	void pop()
	{
		if(toto == -1)
		{
			while(boto > -1)
			{
				ax = toto + 1;
				if(toto == -1)
					to[ax] = mp(bo[boto].f, bo[boto].f);
				else
					to[ax] = mp(bo[boto].f, min(bo[boto].f, to[toto].s));
				toto++;
				boto--;
			}
		}
		if(toto > -1)
			toto--;
	}
	int mini()
	{
		int mini = MOD;
		if(boto > -1)
			mini = bo[boto].s;
		if(toto > -1)
			mini = min(mini, to[toto].s);
		return mini;
	}
};
