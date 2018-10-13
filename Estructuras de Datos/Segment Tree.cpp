int T[4*tam], A[tam];
struct node
{
  int x;
  node(int X) : x(X){}
};
node join(node a, node b)
{
  a.x += b.x;
  return  a;
}
void init(int b, int e, int n)
{
  if(b==e) {A[b] = node(A[e]); return;}
  int mid = (b + e) / 2, iz = n * 2 + 1, de = iz + 1;
  init(b, mid, iz);
  init(mid + 1, e, de);
  T[n] = join(T[iz], T[de]);
}
