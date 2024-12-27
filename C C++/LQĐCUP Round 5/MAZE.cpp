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
const ll INF = (ll) 1e15 + 7;
const int N = (int) 3e5 + 7;
const int M = (int) 19;

/*-----------------------------------------------------------------------------------------------------------------*/

int n;
vii(int, int) inp[N];
ll res[N], mx[N][3];

void update(int u, ll val) {
    if (mx[u][0] < val) {
        mx[u][2] = mx[u][1];
        mx[u][1] = mx[u][0];
        mx[u][0] = val;
    }
    else if (mx[u][1] < val) {
        mx[u][2] = mx[u][1];
        mx[u][1] = val;
    }
    else if (mx[u][2] < val)
        mx[u][2] = val;
}

void dfs(int u, int par) {
    Rep(i, 3) mx[u][i] = 0;
    for (ii(int, int) v : inp[u]) if (v.fi != par) {
        dfs(v.fi, u);
        update(u, mx[v.fi][0] + v.se);
    }
}

ll gt(ll x, ll y, ll z) {
    ll res = max({(x + y) * z, (x + z) * y, (y + z) * x});
    maximize(res, max({x * y, x * z, y * z}));
    return res;
}

void dfss(int u, int par, ll val) {
    res[u] = gt(mx[u][0], mx[u][1], max(val, mx[u][2]));
    for (ii(int, int) v : inp[u]) if (v.fi != par) {
        if (mx[u][0] - v.se == mx[v.fi][0])
            dfss(v.fi, u, max(val, mx[u][1]) + v.se);
        else
            dfss(v.fi, u, max(val, mx[u][0]) + v.se);
    }
}

void solve(void) {
    dfs(1, 0); dfss(1, 0, -INF);
    ll ans = 0;
    For(i, 1, n, 1) maximize(ans, res[i]);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MAZE.inp", "r", stdin);
    freopen("MAZE.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n - 1, 1) {
        int x, y, w; cin >> x >> y >> w;
        inp[x].pub({y, w});
        inp[y].pub({x, w});
    }

    solve();

    return 0;
}
