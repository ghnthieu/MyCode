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
const int N = (int) 1e5 + 7;
const int M = (int) 19;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, par[N][M + 1], high[N];
vec(int) inp[N];
bool vit[N];
ll duong[N];

void dfs(int u) {
    vit[u] = true;
    for (int v : inp[u]) {
        if (!vit[v]) {
            duong[v] = duong[u] + 1;
            dfs(v);
        }
    }
}

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

ll get_sum(int u, int v) {
    return duong[u] + duong[v] - (duong[lca(u, v)] * 2);
}

ll ans = 0;

void add(ll &x, int y) {
    x += 1ll * y;
    x -= ((x >= MOD) ? 1 : 0);
}

void sinh(vec(int) tmp) {
    if ((int) tmp.size() == n) {
        //Rep(i, n) cout << tmp[i] << " ";
        //cout << '\n';
        int mx = 0;
        For(i, 1, n, 1) For(j, i, n, 1) if (tmp[i - 1] == tmp[j - 1])
            maximize(mx, get_sum(i, j));
        add(ans, mx);
        //cout << mx << " ";
        return;
    }

    tmp.pub(1);
    sinh(tmp);
    tmp.pb();
    tmp.pub(0);
    sinh(tmp);
    tmp.pb();
}

void sub1(void) {
    vec(int) tmp;
    sinh(tmp);
    cout << ans % MOD;
}

ll ltbinary(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b) {
        if (b & 1)
            res = ((res % MOD) * (a % MOD)) % MOD;
        a = ((a % MOD) * (a % MOD)) % MOD;
        b >>= 1;
    }
    return (res % MOD);
}

void sub2(void) {
    if (n == 1) { cout << 1; return; }
    if (n == 2) { cout << 2; return; }
    cout << 2ll * ltbinary(2, n) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("PAINT.INP", "r", stdin);
    freopen("PAINT.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    bool check = true;
    For(i, 1, n - 1, 1) {
        int x, y; cin >> x >> y;
        if (x != 1) check = false;
        inp[x].pub(y);
        inp[y].pub(x);
    }

    //Init
    dfs(1);
    dfs_lca(1);
    For(j, 1, M, 1) For(i, 1, n, 1)
        par[i][j] = par[par[i][j - 1]][j - 1];
    high[0] = -1;

    if (check)
        sub2();
    else
        sub1();

    return 0;
}
