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
const int N = (int) 1e6 + 7;
const int M = (int) 19;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, par[N][M + 1], high[N];
viii(int, int, int) inp[N];
ll sumw = 0;

void sub1(void) {
    cout << sumw;
}

map <ii(int, int), ii(int, int)> wedge;
vec(int) stopo;

void dfs_lca(int u) {
    for (iii(int, int, int) v : inp[u]) if (v.fi.fi != par[u][0]) {
        par[v.fi.fi][0] = u;
        high[v.fi.fi] = high[u] + 1;
        dfs_lca(v.fi.fi);
    }
    stopo.pub(u);
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

ll cnt[N];

void sub2(void) {
    dfs_lca(1);
    For(j, 1, M, 1) For(i, 1, n, 1)
        par[i][j] = par[par[i][j - 1]][j - 1];
    high[0] = -1;

    For(i, 1, n - 1, 1) {
        int tpar = lca(i, i + 1);
        ++cnt[i]; ++cnt[i + 1];
        cnt[tpar] -= 2;
    }
    for (int x : stopo) cnt[par[x][0]] += cnt[x];

    ll ans = 0;
    for (auto it : wedge) {
        int x = it.fi.fi, y = it.fi.se, w1 = it.se.fi, w2 = it.se.se;
        if (par[x][0] == y)
            ans += min(1ll * cnt[x] * w1, 1ll * w2);
        else
            ans += min(1ll * cnt[y] * w1, 1ll * w2);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("FRIEND.inp", "r", stdin);
    freopen("FRIEND.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    bool dk_sub1 = true;
    Rep(edge, n - 1) {
        int u, v, w1, w2; cin >> u >> v >> w1 >> w2;
        inp[u].pub({{v, w1}, w2});
        inp[v].pub({{u, w1}, w2});
        wedge[{u, v}] = {w1, w2};
        if (w1 != w2) dk_sub1 = false;
        sumw += w1;
    }

    if (dk_sub1)
        sub1();
    else
        sub2();

    return 0;
}
