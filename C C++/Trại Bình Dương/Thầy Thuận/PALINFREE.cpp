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
#define For(i, l, r, up) for (long long i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

ll a, b, dp[20][12][12][2];

ll Try(int pos, int last, int lastt, int lw, string x) {
    if (pos == x.length()) return 1;
    if (dp[pos][last][lastt][lw] != -1) return dp[pos][last][lastt][lw];
    int tmp = 9;
    if (lw == 1) tmp = x[pos] - '0';
    ll ans = 0;
    Rep(i, tmp + 1) {
        if (i == last || i == lastt) continue;
        int new_lw = 0, tlast, tlastt;
        if (last == 10) {
            if (i != 0 || pos + 1 == x.length()) { tlast = i; tlastt = 10; }
            else { tlast = 10; tlastt = 10; }
        }
        else { tlast = i; tlastt = last; }
        if (i == tmp && lw == 1) new_lw = 1;
        ans += Try(pos + 1, tlast, tlastt, new_lw, x);
    }
    dp[pos][last][lastt][lw] = ans;
    return ans;
}

ll solve(ll x) {
    memset(dp, -1, sizeof(dp));
    return Try(0, 10, 10, 1, to_string(x));
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PALINFREE.INP", "r", stdin);
    freopen("PALINFREE.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> a >> b;
    cout << solve(b) - solve(a - 1);

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
