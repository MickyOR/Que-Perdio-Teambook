struct st
{
	int val;
	st* r;
	st* l;
	st() {r = l = NULL; val = 0;}
	st(int v) {r = l = NULL; val = v;}
	st(st* L, st* R) {l = L; r = R, val = l->val + r->val;}
};
int ar[tam];
typedef st* pst;
pst init(int b, int e)
{
	if(b == e)
		return new st(ar[b]);
	int mid = (b + e) / 2;
	return new st(init(b, mid), init(mid + 1, e));
}
pst update(pst t, int b, int e, int pos, int val)
{
	if(b == e)
		return new st(t->val + val);
	int mid = (b + e) / 2;
	if(mid >= pos)
		return new st(update(t->l, b, mid, pos, val), t->r);
	return new st(t->l, update(t->r, mid + 1, e, pos, val));
}
int query(pst t, int b, int e, int i, int j)
{
	if(b >= i && e <= j)
		return t->val;
	int mid = (b + e) / 2;
	if(mid >= j)
		return query(t->l, b, mid, i, j);
	if(mid < i)
		return query(t->r, mid +1, e, i, j);
	return query(t->l, b, mid, i, j) + query(t->r, mid +1, e, i, j);
}
