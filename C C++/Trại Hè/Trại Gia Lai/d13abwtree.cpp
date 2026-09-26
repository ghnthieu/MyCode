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
const int MOD = (int) 1e9 + 9;
const int N = (int) 1e6 + 7;
const int M = (int) 19;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, a[N], b[N], par[N][M + 1], high[N];
vec(int) inp[N];

void dfs_lca(int u) {
    for (int v : inp[u]) if (v != par[u][0]) {
        par[v][0] = u;
        high[v] = high[u] + 1;
        dfs_lca(v);
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

void add(ll &x, ll y) {
    x += y;
    x -= ((x >= MOD) ? MOD : 0);
}

ll ans = 0;

void solve(int i, vec(int) luu) {
    if (luu.size() == n + 1) return;
    if (!luu.empty()) {
        int res = luu[0];
        For(i, 1, luu.size() - 1, 1) {
            res = lca(res, luu[i]);
            if (res == 1) break;
        }

        ll ress = a[luu[0]]; For(i, 1, luu.size() - 1, 1) ress = 1ll * ((ress % MOD) * (a[luu[i]] % MOD)) % MOD;
        add(ans, 1ll * ((ress % MOD) * (b[res] % MOD)) % MOD);
    }

    For(j, i + 1, n, 1) {
        luu.pub(j);
        solve(j, luu);
        luu.pb();
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) cin >> a[i];
    For(i, 1, n, 1) cin >> b[i];
    For(i, 1, n - 1, 1) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
    }

    dfs_lca(1);
    For(j, 1, M, 1) For(i, 1, n, 1)
        par[i][j] = par[par[i][j - 1]][j - 1];
    high[0] = -1;

    vec(int) tmp;
    solve(0, tmp);
    cout << ans;

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
