int bit[tam];
int query(int pos)
{
	int res = 0;
	for(int i = pos; i > 0; i -= i & -i)
		res += bit[i];
	return res;
}
void update(int pos, int val)
{
	for(int i = pos; i < tam; i += i & -i)
		bit[i] += val;
}
