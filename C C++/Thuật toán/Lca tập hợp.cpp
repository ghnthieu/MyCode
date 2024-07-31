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
const int N = (int) 1e5 + 7;
const int M = (int) 19;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q, par[N][M + 1], high[N];
vec(int) inp[N];

void dfs_lca(int u) {
    for (int v : inp[u]) {
        if (v != par[u][0]) {
            par[v][0] = u;
            high[v] = high[u] + 1;
            dfs_lca(v);
        }
    }
}

int lca(int u, int v) {
    if (high[v] > high[u]) return lca(v, u);
    Ford (i, M, 0, 1) if (high[par[u][i]] >= high[v])
        u = par[u][i];
    if (u == v) return u;
    Ford(i, M, 0, 1) if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

int tree[4 * N];

void build(int id, int l, int r) {
    if (l == r)
        tree[id] = l;
    else {
        int m = l + r >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        tree[id] = lca(tree[id << 1], tree[id << 1 | 1]);
    }
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return -1;
    if (l >= u && v >= r) return tree[id];
    int m = l + r >> 1;
    int tmp1 = get(id << 1, l, m, u, v), tmp2 = get(id << 1 | 1, m + 1, r, u, v);
    if (tmp1 == -1) return tmp2;
    if (tmp2 == -1) return tmp1;
    return lca(tmp1, tmp2);
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("lca2.inp", "r", stdin);
    //freopen("lca2.out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    Rep(edge, n - 1) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
    }

    dfs_lca(1);
    For(j, 1, M, 1) For(i, 1, n, 1)
        par[i][j] = par[par[i][j - 1]][j - 1];
    high[0] = -1;

    build(1, 1, n);

    Rep(query, q) {
        int l, r; cin >> l >> r;
        cout << get(1, 1, n, l, r) << '\n';
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
