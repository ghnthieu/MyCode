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
const int N = (int) 5e5 + 7;
const int M = (int) 19;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q;
vii(int, int) inp[N];
bool onl[N], vit[N];
ll duong[N];

void dfs(int u) {
    vit[u] = true;
    for (ii(int, int) v : inp[u]) {
        if (!vit[v.fi]) {
            duong[v.fi] = duong[u] + v.se;
            dfs(v.fi);
        }
    }
}

ll duong_sum[N];

void sub1(void) {
    memset(duong_sum, 0, (n + 1) * sizeof(ll));
    For(i, 1, n, 1) if (onl[i]) {
        memset(vit, false, (n + 1) * sizeof(bool));
        memset(duong, 0, (n + 1) * sizeof(ll));
        dfs(i);
        For(j, 1, n, 1) duong_sum[j] += duong[j];
    }

    ll ans = LLONG_MAX;
    For(i, 1, n, 1) minimize(ans, duong_sum[i]);
    cout << ans << '\n';
}

int par[N][M + 1], high[N];

void dfs_lca(int u) {
    for (ii(int, int) v : inp[u]) {
        if (v.fi != par[u][0]) {
            par[v.fi][0] = u;
            high[v.fi] = high[u] + 1;
            dfs_lca(v.fi);
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

ll get_sum(int u, int v) {
    return duong[u] + duong[v] - (duong[lca(u, v)] * 2);
}

void sub2(int u, int v) {
    cout << get_sum(u, v) << '\n';
}

void sub3(int u, int v, int c) {
    int par_12 = lca(u, v), par_13 = lca(u, c), par_23 = lca(v, c);
    ll ans = LLONG_MAX;
    minimize(ans, get_sum(u, par_12) + get_sum(v, par_12) + get_sum(c, par_12));
    minimize(ans, get_sum(u, par_13) + get_sum(v, par_13) + get_sum(c, par_13));
    minimize(ans, get_sum(u, par_23) + get_sum(v, par_23) + get_sum(c, par_23));
    cout << ans << '\n';
}

int num[N];
ll f[N];

void dfs_4f(int u) {
    vit[u] = true;
    num[u] = ((onl[u]) ? 1 : 0);
    for (ii(int, int) v : inp[u]) {
        if (!vit[v.fi]) {
            dfs_4f(v.fi);
            f[u] += f[v.fi] + 1ll * num[v.fi] * v.se;
            num[u] += num[v.fi];
        }
    }
}

int m4;
ll t[N];

void dfs_4t(int u) {
    vit[u] = true;
    for (ii(int, int) v : inp[u]) {
        if (!vit[v.fi]) {
            ll sum = t[u] - f[v.fi] - 1ll * num[v.fi] * v.se;
            t[v.fi] = f[v.fi] + sum + 1ll * (m4 - num[v.fi]) * v.se;
            dfs_4t(v.fi);
        }
    }
}

void sub4() {
    cin >> m4;
    Rep(node, m4) {
        int idx; cin >> idx;
        onl[idx] = true;
    }

    memset(vit, false, (n + 1) * sizeof(bool));
    dfs_4f(1);
    memset(vit, false, (n + 1) * sizeof(bool));
    t[1] = f[1];
    dfs_4t(1);
    ll ans = LLONG_MAX;
    For(i, 1, n, 1) minimize(ans, t[i]);
    cout << ans;
}

void sub5() {}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("WIRELESS.inp", "r", stdin);
    freopen("WIRELESS.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    Rep(edge, n - 1) {
        int x, y, w; cin >> x >> y >> w;
        inp[x].pub({y, w});
        inp[y].pub({x, w});
    }

    //Init
    dfs(1);
    dfs_lca(1);
    For(j, 1, M, 1) For(i, 1, n, 1)
        par[i][j] = par[par[i][j - 1]][j - 1];
    high[0] = -1;

    //Sub 4
    if (q == 1) {
        sub4();
        return 0;
    }

    Rep(query, q) {
        int m; cin >> m;

        //Sub 2
        if (n > 5e2 && q > 5e2 && m == 2) {
            int u, v; cin >> u >> v;
            sub2(u, v);
            continue;
        }

        //Sub 3
        if (n > 5e2 && q > 5e2 && m == 3) {
            int u, v, c; cin >> u >> v >> c;
            sub3(u, v, c);
            continue;
        }

        //Init
        memset(onl, false, (n + 1) * sizeof(bool));
        Rep(tram_onl, m) {
            int idx; cin >> idx;
            onl[idx] = true;
        }

        if (n <= 5e2 && q <= 5e2)
            sub1();
        else
            sub5();
    }

    return 0;
}
