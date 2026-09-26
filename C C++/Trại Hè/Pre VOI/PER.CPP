#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pub push_back
#define pb pop_back
#define mask(i) (1ll << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n  = (n); i < _n; ++i)
template <typename T1, typename T2> bool maximize(T1 &x, T2 y) { if (x < y) { x = y; return true; } return false; }
template <typename T1, typename T2> bool minimize(T1 &x, T2 y) { if (x > y) { x = y; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 3e5 + 8;

int n, q, a[N], b[N];

struct Data {
    int x, y, u, v;
} que[N];

namespace sub1 {

    bool check_dk(void) {
        bool check = true;
        For(i, 1, q, 1) if (que[i].x != que[i].u && que[i].y != que[i].v) {
            check = false;
            break;
        }
        return (n <= 100 && check);
    }

    bool tt[N];

    void solve(void) {
        For(i, 1, q, 1) {
            int l = que[i].x, r = que[i].v, ans = 0;
            For(j, l, r, 1) {
                tt[a[j]] = false;
                tt[b[j]] = false;
            }
            For(j, l, r, 1) {
                if (tt[a[j]]) ++ans;
                else tt[a[j]] = true;
                if (tt[b[j]]) ++ans;
                else tt[b[j]] = true;
            }
            cout << ans << '\n';
        }
    }
}

namespace sub2 {

    bool check_dk(void) {
        return (n <= 5e3);
    }

    ii(int, int) c[N];

    bool cmp(ii(int, int) x, ii(int, int) y) {
        return (x.fi < y.fi);
    }

    void solve(void) {
        For(i, 1, n, 1) c[i] = {b[i], i};
        sort(c + 1, c + n + 1, cmp);

        For(i, 1, q, 1) {
            int x = que[i].x, y = que[i].y, u = que[i].u, v = que[i].v;
            int ans = 0;
            For(j, x, y, 1) if (u <= c[a[j]].se && c[a[j]].se <= v)
                ++ans;
            cout << ans << '\n';
        }
    }
}

namespace sub3 {

    void solve(void) {

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("PER.INP", "r", stdin);
    freopen("PER.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    For(i, 1, n, 1) cin >> a[i];
    For(i, 1, n, 1) cin >> b[i];
    For(i, 1, q, 1) cin >> que[i].x >> que[i].y >> que[i].u >> que[i].v;

    if (sub1::check_dk()) sub1::solve();
    else if (sub2::check_dk()) sub2::solve();
    else sub3::solve();

    //sub2::solve();

    return 0;
}
