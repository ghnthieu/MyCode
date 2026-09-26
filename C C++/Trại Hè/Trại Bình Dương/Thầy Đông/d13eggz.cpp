#include <bits/stdc++.h>
//#include "egg.h"
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
const int INF = (int) 2e9;
const int N = (int) 1e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

ll dp[N + 7][N + 7], luu[N + 7][N + 7];

int solve(int e, int n) {
    memset(dp, 0, sizeof(dp));
    For(i, 1, n, 1) dp[i][0] = INF;
    For(j, 1, e, 1) { dp[1][j] = 1; luu[1][j] = 1; }
    For(i, 2, n, 1) For(j, 1, e, 1) {
        dp[i][j] = INF;
        For(k, 1, i - 1, 1) {
            int res = max(dp[k - 1][j - 1], dp[i - k][j]) + 1;
            if (res < dp[i][j]) {
                dp[i][j] = res;
                luu[i][j] = k;
            }
        }
    }
    int te = e, tn = n, ans = 0;
    while (tn > 0) {
        int k = luu[tn][te];
        if (drop(ans + k)) {
            ans += k;
            tn -= k;
        }
        else {
            tn = k - 1;
            --te;
        }
    }
    return ans;
}
