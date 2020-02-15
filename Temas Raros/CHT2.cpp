bool Q = 0;
struct Line {
    mutable ll m, b, x;

    // Maximo: m < ot.m
    // Minimo: m > ot.m
    bool operator < (const Line ot) const {
        return Q ? x < ot.x : m < ot.m;
    }
};

ll ceil (ll a, ll b) {
    if (a < 0 != b < 0) return a / b;
    return (abs(a) + abs(b) - 1) / abs(b);
}

ll intersection (const Line &p, const Line &q) {
    return ceil(q.b - p.b, p.m - q.m);
}

struct Hull : multiset<Line> {
    bool valid (multiset<Line>::iterator  it) {
        if (it == begin()) {
            auto sig = it;
            sig++;
            if (sig != end()) sig->x = intersection(*it, *sig);
            return it->x = -inf;
        }

        auto ant = it, sig = it;
        ant--, sig++;

        if (sig == end()) {
            it->x = intersection(*it, *ant);
            return 1;
        }

        ll x = intersection(*it, *ant);
        ll y = intersection(*it, *sig);

        if (x > y) return 0;
        it->x = x, sig->x = y;
        return 1;
    }

    void add (ll m, ll b) {
        auto it = lower_bound({m, b, -inf});

        if (it != end() && it->m == m) {
            //Maximo: it->b > b
            //Minimo: it->b < b
            if (it->b > b) return;
            it->b = b;
        } else {
            it = insert({m, b, -inf});
        }

        if (!valid(it)) {
            erase(it);
            return;
        }

        auto ant = it;
        while (ant != begin()) {
            if (valid(--ant)) break;
            erase(ant);
            if (it == begin()) { it->x = -inf; break; }
            ant = it;
        }

        auto sig = it;
        sig++;
        while (sig != end() && !valid(sig))
            erase(sig++);
    }

    ll query (ll x) {
        if (empty()) return 0;

        Q = 1;
        auto it = upper_bound({0, 0, x});
        it--;
        Q = 0;
        return x * it->m + it->b;
    }
};

