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
const int N = (int) 4e2 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

ll n, m, k, a[N][N], pre[N][N];

void sub1(void) {
    For(i, 1, n, 1) For(j, 1, m, 1)
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];

    ll ans = 0;
    For(h1, 1, n, 1) For(c1, 1, m, 1) For(h2, h1, n, 1) For(c2, c1, m, 1) {
        ll tmp = pre[h2][c2] - pre[h2][c1 - 1] - pre[h1 - 1][c2] + pre[h1 - 1][c1 - 1];
        if (tmp % k == 0) {
            ++ans;
            //cout << h1 << " " << c1 << " " << h2 << " " << c2 << '\n';
        }
    }
    cout << ans;
}

void sub2(void) {
    For(i, 1, n, 1) For(j, 1, m, 1)
        pre[i][j] = pre[i - 1][j] + a[i][j];

    ll ans = 0;
    For(h1, 1, n, 1) For(h2, h1, n, 1) {
        unordered_map <ll, ll> cnt; cnt[0] = 1;

        ll prefix = 0;
        For(j, 1, m, 1) {
            ll sum = pre[h2][j] - pre[h1 - 1][j]; prefix += sum;
            ll mod = ((prefix % k) + k) % k; ans += cnt[mod];
            ++cnt[mod];
        }
    }
    cout << ans;
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("TABLE24.INP", "r", stdin);
    freopen("TABLE24.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> k;
    For(i, 1, n, 1) For(j, 1, m, 1) cin >> a[i][j];

    if (n <= 70 && k <= 20)
        sub1();
    else
        sub2();

    return 0;
}
