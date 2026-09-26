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
const int N = (int) 2e2 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int tcase;
ll a[N], b[N], dp[N][N][N];
string s;

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BALLOON.INP", "r", stdin);
    freopen("BALLOON.OUT", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> tcase;
    Rep(test_case, tcase) {
        cin >> s;
        int len = s.length(); s = "c" + s;
        int cnt = 1, cs = 0;
        For(i, 2, len, 1) {
            if (s[i] == s[i - 1]) ++cnt;
            else {
                a[++cs] = cnt;
                cnt = 1;
                b[cs] = s[i - 1] - 'A';
            }
        }
        ++cs;
        a[cs] = cnt;
        cnt = 1;
        b[cs] = s[len] - 'A';

        memset(dp, -0x3f, sizeof(dp));
        For(i, 1, cs, 1) For(j, 0, len, 1) if (j + a[i] >= 2)
            dp[i][i][j] = (j + a[i]) * (j + a[i]);
        For(le, 2, cs, 1) For(r, le, cs, 1) {
            int l = r - le + 1;
            Rep(k, len + 1) {
                if (k + a[l] >= 2) maximize(dp[l][r][k], (k + a[l]) * (k + a[l]) + dp[l + 1][r][0]);
                For(i, l + 1, r, 1) if (b[l] == b[i])
                    maximize(dp[l][r][k], dp[l + 1][i - 1][0] + dp[i][r][k + a[l]]);
            }
        }

        cout << max(0ll, dp[1][cs][0]) << '\n';
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
