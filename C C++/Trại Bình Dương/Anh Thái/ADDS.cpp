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
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

ll a, b, mod;

void sub1(void) {
    ll ans = 0;
    For(i, a, b, 1) ans = ((ans % mod) + (1ll * i * i) % mod) % mod;
    cout << ans % mod;
}

ll nhan(ll a, ll b, ll mod) {
    if (b == 1) return a % mod;
    if (b == 0) return 0;
    ll tmp = nhan(a, b / 2, mod);
    if (b & 1) return ((tmp + tmp) % mod + a) % mod;
    return (tmp + tmp) % mod;
}

ll solve(ll n, ll mod) {
    if (n == -1) return 0;
    ll a = n, b = n + 1, c = 2 * n + 1;
    if (a % 2 == 0) a /= 2;
    else if (b % 2 == 0) b /= 2;
    else if (c % 2 == 0) c /= 2;
    if (a % 3 == 0) a /= 3;
    else if (b % 3 == 0) b /= 3;
    else if (c % 3 == 0) c /= 3;
    return nhan(a % mod, nhan(b % mod, c % mod, mod), mod);
}

void sub2(void) {
    cout << (solve(b, mod) - solve(a - 1, mod) + mod) % mod;
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> a >> b >> mod;

    if (a <= 1e3 && b <= 1e3 && mod <= 1e3)
        sub1();
    else
        sub2();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
