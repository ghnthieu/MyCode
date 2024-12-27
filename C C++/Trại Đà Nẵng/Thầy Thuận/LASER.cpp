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
const ll MOD = (ll) 1e9 + 7;
const int N = (int) 2e3 + 7;
const int M = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n;
bool can[N][N];
ll dp[N][N][2];

ll ltbinary(ll a, ll b) {
    a %= MOD; ll res = 1;
    while (b) {
        if (b & 1) res = ((res % MOD) * (a % MOD)) % MOD;
        a = ((a % MOD) * (a % MOD)) % MOD;
        b >>= 1;
    }
    return (res % MOD);
}

void add(ll &x, ll y) {
    x += y;
    x -= ((x >= MOD) ? MOD : 0);
}

void solve(void) {
    int cnt = 0;
    For(i, 1, n, 1) For(j, 1, n, 1) cnt += (can[i][j]);
    /*For(i, 1, n, 1) {
        For(j, 1, n, 1) cout << can[i][j] << " ";
        cout << '\n';
    }*/
    //cout << cnt << '\n';
    ll inv = ltbinary(2, MOD - 2); //cout << inv << '\n';
    dp[0][0][0] = dp[0][0][1] = ltbinary(2, cnt);
    //cout << dp[0][0][0] << " " << dp[0][0][1] << '\n';
    Rep(i, n + 1) Rep(j, n + 1) {
        //cout << i << " " << j << '\n';
        if (i > 0) {
            //cout << dp[i - 1][j][0] << " ";
            add(dp[i][j][0], dp[i - 1][j][0]);
            //cout << dp[i][j][0] << '\n';
            //cout << dp[i - 1][j][1] * inv % MOD << '\n';
            if (can[i][j]) add(dp[i][j][0], dp[i - 1][j][1] * inv % MOD);
        }
        //cout << dp[i][j][0] << " " << dp[i][j][1] << '\n';

        if (j > 0) {
            add(dp[i][j][1], dp[i][j - 1][1]);
            if (can[i][j]) add(dp[i][j][1], dp[i][j - 1][0] * inv % MOD);
        }
        //cout << dp[i][j][0] << " " << dp[i][j][1] << '\n';
    }
    cout << (dp[n][n][0] + dp[n][n][1]) % MOD;
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("LASER.inp", "r", stdin);
    //freopen("LASER.out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) For(j, 1, n, 1) {
        char ch; cin >> ch;
        if (ch == '.') can[i][j] = true;
        else can[i][j] = false;
    }

    solve();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
