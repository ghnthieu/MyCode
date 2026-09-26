#include <bits/stdc++.h>
using namespace std;

#define NAME ""
#define fi first
#define se second
#define fr front
#define bk back
#define pf pop_front
#define pb pop_back
#define puf push_front
#define pub push_back
#define NOT 18446744073709551615
#define __Trung_Hieu___ signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define vec(kdl) vector <kdl>
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1,kdl2>,kdl3>>
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
typedef long double lde;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

int testcase, n;
ll dp[mask(16) + 7];

ll ltbinary(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void init(void) {
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i=1; i<=mask(16); ++i) {
        for (int b=2; b<=8; ++b) {
            int a = 0;
            while (i - ltbinary(a, b) >= 0) {
                minimize(dp[i], dp[i - ltbinary(a, b)] + b);
                ++a;
            }
        }
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("HOCMAY.INP", "r", stdin);
    freopen("HOCMAY.OUT", "w", stdout);

    init();

    cin >> testcase;
    while (testcase--) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
