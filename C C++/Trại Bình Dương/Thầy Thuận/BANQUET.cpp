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
const int N = (int) 3e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, k, a[N];
ii(ll, ll) dp[N][2];

ii(ll, ll) solve(ll x) {
    dp[1][0] = {0, 0};
    dp[1][1] = {a[1] - x, 1};
    For(i, 2, n, 1) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(make_pair(dp[i - 1][1].fi + a[i], dp[i - 1][1].se),
                       make_pair(dp[i - 1][0].fi + a[i] - x, dp[i - 1][0].se + 1));
    }
    return max(dp[n][0], dp[n][1]);
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("BANQUET.INP", "r", stdin);
    //freopen("BANQUET.OUT", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> k;
    int sl_duong = 0;
    For(i, 1, n, 1) {
        cin >> a[i];
        sl_duong += ((a[i] >= 0) ? 1 : 0);
    }
    minimize(k, sl_duong);

    ll l = 0, r = 1e18, ans = 0;
    while (l <= r) {
        ll m = l + r >> 1;
        if (solve(m).se >= k) {
            maximize(ans, m);
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << 1ll * ans * k + solve(ans).fi;

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
