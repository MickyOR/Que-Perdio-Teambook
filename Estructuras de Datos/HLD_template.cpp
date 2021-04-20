template<int SZ> struct segTree {
    // Codigo de segment tree
};

template<int V> struct HeavyLight {
    segTree<V> st;
    vi parent, depth, heavy, head, pos;
    int cur_pos;
    int n;
    // Si queremos el k-esimo ancestro
    vector<vi> up;
    vi anc;

    int dfs(int v, vector<vi> const&g) {
        for (int i = anc.size()-1, j = 1; i >= 0; i -= j, j*=2) {
            up[v].pb(anc[i]);
        }
        int size = 1;
        int maxSz = 0;
        for (int u : g[v]) {
            if (u != parent[v]) {
                parent[u] = v, depth[u] = depth[v]+1;
                anc.push_back(v);
                int uSz = dfs(u, g);
                anc.pop_back();
                size += uSz;
                if (uSz > maxSz) {
                    maxSz = uSz;
                    heavy[v] = u;
                }
            }
        }
        return size;
    }

    void decompose(int v, int h, vector<vi> const&g) {
        head[v] = h, pos[v] = cur_pos++;
        if (heavy[v] != -1) decompose(heavy[v], h, g);
        for (int c : g[v]) {
            if (c != parent[v] && c != heavy[v]) decompose(c, c, g);
        }
    }

    void init(vector<vi> const&g, const int &root) {
        n = g.size();
        parent = vi(n);
        depth = vi(n);
        heavy = vi(n, -1);
        head = vi(n);
        pos = vi(n);
        up.assign(n, vi());
        cur_pos = 0;
        dfs(root, g);
        decompose(root, root, g);
        st.init(0, n-1, 0);
    }

    int kthUp(int v, int k) {
        k = min(k, depth[v]);
        for (int p = 24; p >= 0 && k > 0; --p) {
            if (k&(1<<p)) {
                assert(up[v].size() > p);
                v = up[v][p];
                k &= ~(1<<p);
            }
        }
        return v;
    }

    // Se puede cambiar por queries
    void updatePath(int a, int b, int delta) {
        for (; head[a] != head[b]; b = parent[head[b]]) {
            if (depth[a] > depth[b]) swap(a, b);
            st.update(0, n-1, 0, pos[head[b]], pos[b], delta);
        }
        if (depth[a] > depth[b]) swap(a, b);
        st.update(0, n-1, 0, pos[a], pos[b], delta);
    }
};

const int tam = 1e5+10;
HeavyLight<tam> hld;
