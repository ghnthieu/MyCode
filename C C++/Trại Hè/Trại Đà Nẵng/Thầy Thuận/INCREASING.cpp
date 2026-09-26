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
const int N = (int) 25e4 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q, a[N];
ll pw[67];

void solve(int l, int r) {
    vec(ll) luu;
    For(i, l, r, 1) luu.pub(a[i]);
    int ans = 0;
    For(i, 1, luu.size() - 1, 1) {
        ll last = luu[i - 1];
        int l = 0, r = 64, res = 67;
        while (l <= r) {
            int m = l + r >> 1;
            if (luu[i] * pw[m] >= last) {
                r = m - 1;
                minimize(res, m);
            }
            else
                l = m + 1;
        }
        luu[i] *= pw[res];
        ans += res;
    }

    //for (ll x : luu) cout << x << " ";
    //cout << '\n';
    cout << ans << '\n';
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    pw[0] = 1;
    For(i, 1, 64, 1) pw[i] = pw[i - 1] * 2ll;

    cin >> n >> q;
    For(i, 1, n, 1) cin >> a[i];

    Rep(query, q) {
        int l, r; cin >> l >> r;
        solve(l, r);
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
