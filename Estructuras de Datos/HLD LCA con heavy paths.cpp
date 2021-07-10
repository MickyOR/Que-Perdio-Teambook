/*
Nota:
- el segment tree no esta implementado, solo HLD

Uso:
- poner grafo en G
- correr init(N)
- para cada nodo v -> segBase[pos[v]] = val[v] (segBase es un nuevo arreglo)
- inicializar segment tree para [0, N-1]
- implementar la funcion segQuery(int l, int r)
*/
vector<vi> G;
vi parent, depth, heavy, head, pos;
int curPos;

int dfs(int v) {
    int size = 1;
    int maxChildrenSize = 0;
    for (int c : G[v]) {
        if (c == parent[v]) continue;
        parent[c] = v;
        depth[c] = depth[v] + 1;
        int cSize = dfs(c);
        size += cSize;
        if (cSize > maxChildrenSize) {
            maxChildrenSize = cSize;
            heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h) {
    head[v] = h;
    pos[v] = curPos++;
    if (heavy[v] != -1) {
        decompose(heavy[v], h);
    }
    for (int c : G[v]) {
        if (c != parent[v] && c != heavy[v]) {
            decompose(c, c);
        }
    }
}

void init(int nodes) {
    parent.assign(nodes, -1);
    depth.resize(nodes);
    heavy.assign(nodes, -1);
    head.resize(nodes);
    pos.resize(nodes);
    curPos = 0;
    // Raiz 0
    dfs(0);
    decompose(0, 0);
}

int segQuery(int l, int r);

int hldQuery(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]]) {
            swap(a, b);
        }
        int pathMax = segQuery(pos[head[b]], pos[b]);
        res = max(pathMax, res);
    }
    if (depth[a] > depth[b]) swap(a, b);
    int lastPath = segQuery(pos[a], pos[b]);
    res = max(res, lastPath);
    return res;
}
