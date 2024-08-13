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
const ll INF = (ll) 1e16 + 7;
const int N = (int) 3e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, node[N];
vec(int) inp[N];
ll dp[N][2][2], sum[2][2];

void dfs(int u, int par) {
    for (int v : inp[u]) if (v != par)
        dfs(v, u);

    dp[u][0][0] = 0;
    dp[u][1][1] = -INF;
    dp[u][1][0] = node[u];
    dp[u][0][1] = -node[u];
    for (int v : inp[u]) if (v != par) {
        Rep(i, 2) Rep(j, 2) {
            sum[i][j] = dp[u][i][j];
            dp[u][i][j] = -INF;
        }

        Rep(i, 2) Rep(j, 2) Rep(k, 2) Rep(ij, 2) {
            if (i && k || j && ij) continue;
            maximize(dp[u][i || k][j || ij], dp[v][k][ij] + sum[i][j]);
        }

        Rep(i, 2) Rep(j, 2) maximize(dp[u][i][j], dp[v][1][1] + sum[i][j]);
    }
}

void solve(void) {
    dfs(1, -1);
    cout << dp[1][1][1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("SOUTH.INP", "r", stdin);
    freopen("SOUTH.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) cin >> node[i];
    Rep(edge, n - 1) {
        int u, v; cin >> u >> v;
        inp[u].pub(v);
        inp[v].pub(u);
    }

    solve();

    return 0;
}
