#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb pop_back
#define pub push_back
#define __Trung_Hieu___ signed main()
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 3e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, a[N][N];
ll dp[N][N][4];

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("MATRIX3.INP", "r", stdin);
    freopen("MATRIX3.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    For(i, 1, n, 1) For(j, 1, m, 1) cin >> a[i][j];

    memset(dp, -0x3f, sizeof(dp));
    dp[1][1][0] = a[1][1];
    //dp[1][1][1] = dp[1][1][2] = -1e18;
    For(i, 1, n, 1) For(j, 1, m, 1) {
        if (i == 1 && j == 1) continue;
        //For(k, 0, 2, 1) dp[i][j][k] = -1e18;
        if (j - 1 >= 1) For(k, 0, 2, 1)
            maximize(dp[i][j][0], dp[i][j - 1][k] + a[i][j]);
        if (i - 1 >= 1) For(k, 0, 2, 1)
            maximize(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][j]);
    }
    cout << max({dp[n][m][0], dp[n][m][1], dp[n][m][2]});

    return 0;
}
