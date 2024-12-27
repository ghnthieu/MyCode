#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define bk back
#define fr front
#define pb pop_back
#define pf pop_front
#define pub push_back
#define puf push_front
#define __Trung_Hieu___ signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1, kdl2>, kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1, kdl2>, kdl3>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const ll INF = (ll) 1e18 + 7ll;
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, s, q, h, a[N], tmp[N];
vii(int, int) inp[N];
ii(int, int) que[N];

struct Data {
    int u, v, w;
} edge[N];

struct IT {
    ll tree[4 * N], lazy[4 * N];

    void fix(int id) {
        tree[id << 1] += lazy[id];
        tree[id << 1 | 1] += lazy[id];
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, ll val) {
        if (l > v || u > r) return;
        if (l >= u && v >= r) {
            tree[id] += val;
            lazy[id] += val;
            return;
        }
        fix(id); int m = l + r >> 1;
        update(id << 1, l, m, u, v, val);
        update(id << 1 | 1, m + 1, r, u, v, val);
        tree[id] = min(tree[id << 1], tree[id << 1 | 1]);
    }

    ll get(int id, int l, int r, int u, int v) {
        if (l > v || u > r) return INF;
        if (l >= u && v >= r) return tree[id];
        fix(id); int m = l + r >> 1;
        return min(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }

    void update(int l, int r, ll val) {
        update(1, 1, n, l, r, val);
    }

    ll get(int l, int r) {
        return get(1, 1, n, l, r);
    }
} it;

ll duong[N], ans[N];
int timee, tin[N], tout[N], id[N], ide[N], par[N];
vec(int) sm[N], bg[N];

bool dk(int u, int v) {
    return (tin[u] >= tin[v] && tout[u] <= tout[v]);
}

void dfs(int u, int pr) {
    tin[u] = ++timee;
    for (ii(int, int) v : inp[u]) if (v.fi != pr) {
        id[v.fi] = v.se;
        ide[v.se] = v.fi;
        par[v.fi] = u;
        duong[v.fi] = duong[u] + edge[v.se].w;
        dfs(v.fi, u);
    }
    tout[u] = timee;
}

void dfssm(int u, int par) {
    for (ii(int, int) v : inp[u]) if (v.fi != par) {
        it.update(1, n, edge[v.se].w);
        it.update(tin[v.fi], tout[v.fi], -2ll * edge[v.se].w);
        dfssm(v.fi, u);
        it.update(tin[v.fi], tout[v.fi], 2ll * edge[v.se].w);
        it.update(1, n, -edge[v.se].w);
    }

    for (int x : sm[u]) {
        int v = que[x].fi;
        v = ide[v]; if (dk(h, v)) ans[x] = -1;
        else {
            ll tp = it.get(tin[v], tout[v]);
            if (tp >= 1e15) ans[x] = -2;
            else ans[x] = tp;
        }
    }

    for (int x : bg[u]) {
        int v = que[x].fi;
        v = ide[v]; if (!dk(h, v)) ans[x] = -1;
        else {
            ll tp = min(it.get(1, tin[v] - 1), it.get(tout[v] + 1, n));
            if (tp >= 1e15) ans[x] = -2;
            else ans[x] = tp;
        }
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> s >> q >> h;
    For(i, 1, n - 1, 1) {
        int x, y, w; cin >> x >> y >> w;
        inp[x].pub({y, i});
        inp[y].pub({x, i});
        edge[i] = {x, y, w};
    }
    For(i, 1, s, 1) { cin >> a[i]; tmp[a[i]] = 1; }
    For(i, 1, q, 1) { cin >> que[i].fi >> que[i].se; }
    dfs(1, 0);
    For(i, 1, n, 1) {
        if (tmp[i]) it.update(tin[i], tin[i], duong[i]);
        else it.update(tin[i], tin[i], INF);
    }
    For(i, 1, q, 1) {
        int dele = que[i].fi, u = que[i].se; int v = ide[dele];
        if (dk(u, v)) sm[u].pub(i);
        else bg[u].pub(i);
    }
    dfssm(1, 0);
    For(i, 1, q, 1) {
        if (ans[i] == -1) cout << "escaped" << '\n';
        else if (ans[i] == -2) cout << "oo" << '\n';
        else cout << ans[i] << '\n';
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
