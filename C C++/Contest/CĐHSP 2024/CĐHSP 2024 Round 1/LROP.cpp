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
const int N = (int) 5e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

ll n, a[N], b[N];
vec(ll) luu;

void add(ll &x, ll y) { x += y; }

void sub1(void) {
    ll ans = 0;
    For(i, 1, n, 1) add(ans, 1ll * a[i] * b[i]);
    For(l, 1, n, 1) For(r, 1, n, 1) {
        //Init
        luu.clear();
        For(i, l, r, 1) {
            luu.pub(a[i]);
            a[i] = b[l + r - i] - a[i];
        }

        //Calc
        ll res = 0;
        For(i, 1, n, 1) add(res, 1ll * a[i] * b[i]);
        maximize(ans, res);

        //Restore
        int idx = 0;
        For(i, l, r, 1) a[i] = luu[idx++];
    }
    cout << ans;
}

ll pre[N], suf[N], res[N][N];

void sub2(void) {
    ll ans = 0;
    For(i, 1, n, 1) add(ans, 1ll * a[i] * b[i]);
    For(i, 1, n, 1) {
        add(pre[i], pre[i - 1]);
        add(pre[i], 1ll * a[i] * b[i]);
    }
    Ford(i, n, 1, 1) {
        add(suf[i], suf[i + 1]);
        add(suf[i], 1ll * a[i] * b[i]);
    }

    Ford(l, n, 1, 1) {
        For(r, l + 1, n, 1) {
            add(res[l][r], res[l + 1][r - 1]);
            add(res[l][r], 1ll * b[l] * (b[r] - a[l]));
            add(res[l][r], 1ll * b[r] * (b[l] - a[r]));
            maximize(ans, pre[l - 1] + suf[r + 1] + res[l][r]);
            res[l][l] = 1ll * b[l] * (b[l] - a[l]);
            maximize(ans, pre[l - 1] + suf[l + 1] + res[l][l]);
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("LROP.INP", "r", stdin);
    freopen("LROP.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) cin >> a[i];
    For(i, 1, n, 1) cin >> b[i];

    if (n <= 100)
        sub1();
    else
        sub2();

    //cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
