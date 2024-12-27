#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
#define bk back
#define fr front
#define pb pop_back
#define pf pop_front
#define pub push_back
#define puf push_front
#define sz(x) (ll)(x.size())
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define biti(i, x) ((1ll << (i)) & (x))
#define boolbit(i, x) (biti(i, x) != 0)
#define optm(v) v.resize(unique(all(v)) - v.begin())
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define vec(kdl) vector <kdl>
#define ii pair<int,int>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1, kdl2>, kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1, kdl2>, kdl3>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define forr(i, l, r) for (int i = l; i <= r; i++)
#define fodd(i, l, r) for (int i = l; i >= r; i--)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ll n, m, a[N], dp[1007][5007];

ll ltbinary(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b) {
        if (b & 1) res = ((res % MOD) * (res % MOD)) % MOD;
        a = ((a % MOD) * (a % MOD)) % MOD;
        b >>= 1;
    }
    return (res % MOD);
}

ll kCn(ll k, ll n) {
    if (k > n) return 0;
    ll res = 1;
    For(i, 1, k, 1) res = res * (n - i + 1) % MOD * ltbinary(i, MOD - 2) % MOD;
    return res;
}

void add(ll &x, ll y) {
    x += y;
    x -= ((x >= MOD) ? MOD : 0);
}

void sub1(void) {
    dp[0][0] = 1;
    For(i, 1, n, 1) Rep(j, m + 1) if (j >= a[i]) {
        add(dp[i][j], dp[i][j - a[i]]);
        add(dp[i][j], dp[i - 1][j - a[i]]);
    }
    cout << dp[n][m];
}

void sub2(void) {
    cout << kCn(n - 1, m - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    For(i, 1, n, 1) cin >> a[i];

    if (n <= 1e3)
        sub1();
    else
        sub2();

    return 0;
}
