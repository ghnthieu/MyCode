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
const ll INF = (ll) 1e16 + 7ll;
const int N = (int) 1e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, dc, point[N][N];
bool check[N][N];

void update(ii(ll, ll) &updte, ll val) {
    if (updte.fi < val) {
        updte.se = updte.fi;
        updte.fi = val;
    }
    else
        maximize(updte.se, val);
}

ll dp[N][N][32];
void sub1(void) {
    memset(dp, -0x3f, sizeof(dp));
    For(i, 1, m, 1) dp[1][i][0] = point[1][i];

    Rep(k, dc + 1) {
        For(i, 1, n - 1, 1) For(j, 1, m, 1) For(ij, j - 1, j + 1, 1) if (ij >= 1 && ij <= m)
            maximize(dp[i + 1][ij][k], dp[i][j][k] + point[i + 1][ij]);

        if (k < dc) {
            ii(ll, ll) updte;
            updte.fi = -INF; updte.se = -INF;
            For(i, 1, n, 1) For(j, 1, m, 1) if (check[i][j])
                update(updte, dp[i][j][k]);
            For(i, 1, n, 1) For(j, 1, m, 1) if (check[i][j]) {
                if (dp[i][j][k] == updte.fi)
                    maximize(dp[i][j][k + 1], updte.se + point[i][j]);
                else
                    maximize(dp[i][j][k + 1], updte.fi + point[i][j]);
            }
        }
    }

    ll ans = -INF;
    For(i, 1, m, 1) Rep(k, dc + 1)
        maximize(ans, dp[n][i][k]);
    cout << ans;
}

void sub2(void) {
    ll ans = -INF, last_1 = 0, last_2 = 0, mx = -INF;
    Rep(k, 11) {
        int new_k = k % 2;
        For(i, 1, n, 1) For(j, 1, m, 1) {
            if (i == 1 && new_k == 0)
                dp[i][j][0] = 1ll * point[i][j];
            else {
                maximize(dp[i][j][new_k], dp[i - 1][j - 1][new_k] + point[i][j]);
                maximize(dp[i][j][new_k], dp[i - 1][j][new_k] + point[i][j]);
                maximize(dp[i][j][new_k], dp[i - 1][j + 1][new_k] + point[i][j]);
            }
            if (check[i][j]) {
                maximize(dp[i][j][new_k], point[i][j] + mx);
                if (k == 9) maximize(last_1, dp[i][j][new_k]);
                if (k == 10) maximize(last_2, dp[i][j][new_k]);
            }
            if (i == n) maximize(ans, dp[i][j][new_k]);
        }
        mx = -INF;
        For(i, 1, n, 1) For(j, 1, m, 1) if (check[i][j])
            maximize(mx, dp[i][j][new_k]);
    }
    cout << ans + (last_2 - last_1) * (dc - 10);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("mdoor.inp", "r", stdin);
    //freopen("mdoor.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> dc;
    For(i, 1, n, 1) For(j, 1, m, 1) {
        int x; cin >> x;
        check[i][j] = ((x == 1) ? 1 : 0);
    }
    For(i, 1, n, 1) For(j, 1, m, 1) cin >> point[i][j];

    if (dc <= 20)
        sub1();
    else
        sub2();

    return 0;
}
