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
