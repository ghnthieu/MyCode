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

typedef double de;
typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e2 + 7;

int n, m[N];
vii(int, int) luu[N];

namespace sub1 {

    bool check_dk(void) {
        bool ok = true;
        For(i, 1, n, 1) if (ok) {
            if (luu[i].size() != 4) {
                ok = false;
                break;
            }

            bool check = false;
            For(j, 0, luu[i].size() - 2, 1) if (luu[i][j].se == 0 && luu[i][j + 1].se == 0) {
                check = true;
                break;
            }

            if (luu[i][0].se == 0 && luu[i].back().se == 0) check = true;

            if (check == false) ok = false;
        }
        return (n <= 50 && ok);
    }

    de calc(ii(int, int) x, ii(int, int) y) {
        return (de) sqrt(1ll * (y.fi - x.fi) * (y.fi - x.fi) + 1ll * (y.se - x.se) * (y.se - x.se));
    }

    struct tdo {
        int x, y, u, v, idx;
    } choose[N];

    bool cmp(tdo x, tdo y) {
        return (x.x < y.x);
    }

    void solve(void) {
        For(i, 1, n, 1) {
            bool ok = false;
            For(j, 0, luu[i].size() - 2, 1) if (luu[i][j].se == 0 && luu[i][j + 1].se == 0) {
                int x = luu[i][j].fi, y = luu[i][j + 1].fi; if (x > y) swap(x, y);
                choose[i] = {x, 0, y, 0, i};
                ok = true;
                break;
            }
            int x = luu[i][0].fi, y = luu[i].back().fi; if (x > y) swap(x, y);
            if (!ok) choose[i] = {x, 0, y, 0, i};
        }

        //For(i, 1, n, 1) cout << choose[i].x << " " << choose[i].y << " " << choose[i].u << " " << choose[i].v << '\n';
        sort(choose + 1, choose + n + 1, cmp);
        //For(i, 1, n, 1) cout << choose[i].x << " " << choose[i].y << " " << choose[i].u << " " << choose[i].v << '\n';
        int start = 0;
        For(i, 1, n, 1) if (choose[i].idx == 1) {
            start = i;
            break;
        }

        int i = start; de ans = 0;
        while (i >= 1) {
            if (i > 1) ans += calc({choose[i - 1].u, choose[i - 1].v}, {choose[i].x, choose[i].y});
            --i;
        }
        i = start;
        while (i <= n) {
            if (i < n) ans += calc({choose[i].u, choose[i].v}, {choose[i + 1].x, choose[i + 1].y});
            ++i;
        }
        cout << (ll) (ans * 1000000);
    }
}

namespace sub2 {

    bool check_dk(void) {

    }

    void solve(void) {

    }
}

namespace sub3 {

    void solve(void) {

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("BAL.INP", "r", stdin);
    freopen("BAL.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) {
        cin >> m[i];
        For(j, 1, m[i], 1) {
            int x, y; cin >> x >> y;
            luu[i].pub({x, y});
        }
    }

    //if (sub1::check_dk()) sub1::solve();
    //else if (sub2::check_dk()) sub2::solve();
    //else sub3::solve();

    sub1::solve();

    return 0;
}
