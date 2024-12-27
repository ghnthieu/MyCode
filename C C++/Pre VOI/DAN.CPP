#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pub push_back
#define pb pop_back
#define mask(i) (1ll << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1, kdl2>, kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1, kdl2>, kdl3>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n  = (n); i < _n; ++i)
template <typename T1, typename T2> bool maximize(T1 &x, T2 y) { if (x < y) { x = y; return true; } return false; }
template <typename T1, typename T2> bool minimize(T1 &x, T2 y) { if (x > y) { x = y; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;

int n, k, a[N];

namespace sub1 {

    bool check_dk(void) {
        return (n <= 20);
    }

    ll ans = LLONG_MAX;

    void backtrack(int i, vec(int) &luu) {
        if (luu.size() == 2 * k) {
            ll sum = 0;
            For(j, 1, luu.size() - 1, 2) sum += luu[j] - luu[j - 1];
            minimize(ans, sum);
            return;
        }

        For(j, i + 1, n, 1) {
            luu.pub(a[j]);
            backtrack(j, luu);
            luu.pb();
        }
    }

    void solve(void) {
        sort(a + 1, a + n + 1);
        vec(int) tmp;
        backtrack(0, tmp);
        cout << ans;
    }
}

namespace sub2 {

    bool check_dk(void) {
        return (n <= 2e3);
    }

    ll dp[5007][5007];

    void solve(void) {
        sort(a + 1, a + n + 1);
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        For(i, 1, n, 1)  For(j, 0, k, 1) {
            dp[i][j] = dp[i - 1][j];
            if (i > 1) minimize(dp[i][j], dp[i - 2][j - 1] + a[i] - a[i - 1]);
        }
        cout << dp[n][k];
    }
}

namespace sub3 {

    vec(int) luu;

    void solve(void) {
        sort(a + 1, a + n + 1);
        For(i, 2, n, 1) luu.pub(a[i] - a[i - 1]);
        sort(all(luu));
        ll ans = 0;
        For(i, 1, k, 1) ans += luu[i - 1];
        cout << ans;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("DAN.INP", "r", stdin);
    freopen("DAN.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> k;
    For(i, 1, n, 1) cin >> a[i];

    if (sub1::check_dk()) sub1::solve();
    else if (sub2::check_dk()) sub2::solve();
    else sub3::solve();

    return 0;
}
