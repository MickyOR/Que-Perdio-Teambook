struct node
{
  int val;
};
node join(node a, node b)
{
  a.val += b.val;
  return a;
}
int ar[tam];
node t[4 * tam];
void init(int b, int e, int node)
{
	if(b == e)
	{
		t[node].val = ar[b];
		return;
	}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = join(t[l], t[r]);
}
node query(int b, int e, int node, int i, int j)
{
	if(b >= i && e <= j)
		return t[node];
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid < i)
		return query(mid + 1, e, r, i, j);
	if(mid >= j)
		return query(b, mid, l, i, j);
	return join(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
void update(int b, int e, int node, int pos, int val)
{
	if(b == e) {t[node].val = val;return;}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid < pos)
		update(mid + 1, e, r, pos, val);
	else
		update(b, mid, l, pos, val);
	t[node] = join(t[l], t[r]);
}
