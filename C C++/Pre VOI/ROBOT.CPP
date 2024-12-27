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
const int N = (int) 4e2 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, q;

namespace sub1 {
    bool check_dk(void) {
        return (n <= 4e1 && m <= 4e1);
    }

    int a[N][N];
    ll dp[N][N];

    void input(void) {
        For(i, 1, n, 1) For(j, 1, m, 1) cin >> a[i][j];
    }

    void solve(void) {
        input();

        Rep(query, q) {
            int x, y; cin >> x >> y;
            memset(dp, -0x3f, sizeof(dp));
            dp[1][1] = a[1][1];
            For(i, 1, n, 1) For(j, 1, m, 1) {
                if (i == x && j == y) continue;
                if (i + 1 != x || j != y) maximize(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
                if (i != x || j + 1 != y) maximize(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
            }
            cout << dp[n][m] << '\n';
        }
    }
}

namespace sub2 {
    bool check_dk(void) {
        return (n <= 4e2 && m <= 4e2);
    }

    int a[N][N];
    ll dpx[N][N], dpn[N][N];

    void input(void) {
        For(i, 1, n, 1) For(j, 1, m, 1) cin >> a[i][j];
    }

    void solve(void) {
        input();

        For(i, 1, n, 1) For(j, 1, m, 1) dpx[i][j] = max(dpx[i - 1][j], dpx[i][j - 1]) + a[i][j];
        Ford(i, n, 1, 1) Ford(j, m, 1, 1) dpn[i][j] = max(dpn[i + 1][j], dpn[i][j + 1]) + a[i][j];

        Rep(query, q) {
            int x, y; cin >> x >> y;
            ll ans = LLONG_MIN;
            For(i, x + 1, n, 1) maximize(ans, dpx[i][y - 1] + dpn[i][y]);
            For(j, y + 1, m, 1) maximize(ans, dpx[x - 1][j] + dpn[x][j]);
            cout << ans << '\n';
        }
    }
}

namespace sub3 {
    vec(vec(int)) a;
    vec(vec(ll)) dpx, dpn, dpr, dpc;

    void input(void) {
        a.resize(n + 5, vec(int) (m + 5, 0));
        For(i, 1, n, 1) For(j, 1, m, 1) cin >> a[i][j];
    }

    void init(void) {
        dpx.resize(n + 5, vec(ll) (m + 5, 0));
        dpn.resize(n + 5, vec(ll) (m + 5, 0));
        dpr.resize(n + 5, vec(ll) (m + 5, 0));
        dpc.resize(n + 5, vec(ll) (m + 5, 0));

        For(i, 1, n, 1) For(j, 1, m, 1) dpx[i][j] = max(dpx[i - 1][j], dpx[i][j - 1]) + a[i][j];
        Ford(i, n, 1, 1) Ford(j, m, 1, 1) dpn[i][j] = max(dpn[i + 1][j], dpn[i][j + 1]) + a[i][j];
        For(i, 1, n - 1, 1) For(j, 1, m, 1) dpr[i][j] = max(dpr[i][j - 1], dpx[i][j] + dpn[i + 1][j]);
        For(i, 1, n, 1) For(j, 1, m - 1, 1) dpc[i][j] = max(dpc[i - 1][j], dpx[i][j] + dpn[i][j + 1]);
    }

    void solve(void) {
        input();
        init();

        Rep(query, q) {
            int x, y; cin >> x >> y;

            ll ans1 = 0, ans2 = 0;
            if (x != 1 && y != m) ans1 = dpc[x - 1][y];
            if (x != n && y != 1) ans2 = dpr[x][y - 1];

            cout << max(ans1, ans2) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> q;

    if (sub1::check_dk()) sub3::solve();
    else if (sub2::check_dk()) sub3::solve();
    else sub3::solve();

    return 0;
}
