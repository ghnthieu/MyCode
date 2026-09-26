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

typedef long double de;
typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

int n;

struct Data {
    int x, y;
    de water;
} a[N];

de calc(int x, int y) {
    return (de) sqrt((a[x].x - a[y].x) * (a[x].x - a[y].x) + (a[x].y - a[y].y) * (a[x].y - a[y].y));
}

de tcalc(int x1, int y1, int x2, int y2) {
    return (de) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool cmp(Data x, Data y) {
    return (x.water < y.water);
}

namespace sub1 {

    bool check_dk(void) {
        return (n <= 3);
    }

    void solve(void) {
        if (n == 1) {
            cout << fixed << setprecision(10) << (de) a[1].water;
            return;
        }

        if (n == 2) {
            de tmp1 = a[1].water, tmp2 = a[2].water;
            if (tmp1 > tmp2) swap(tmp1, tmp2);
            de res = (de) (tmp2 - tmp1 - calc(1, 2)) / 2; maximize(res, 0);
            //cout << res << '\n';
            if (res == 0) cout << fixed << setprecision(10) << (de) min(tmp1, tmp2) << '\n';
            else cout << fixed << setprecision(10) << (de) min(tmp1 + res, tmp2 - res - calc(1, 2)) << '\n';
            return;
        }

        if (n == 3) {
            vec(Data) srt; srt.pub(a[1]); srt.pub(a[2]); srt.pub(a[3]);
            sort(all(srt), cmp);

            de ans = LLONG_MIN;

            //Th1 a -> b
            Data tmp1 = srt[0], tmp2 = srt[1], tmp3 = srt[2]; de mn = LLONG_MAX;
            de res = (de) (tmp2.water - tmp1.water - tcalc(tmp2.x, tmp2.y, tmp1.x, tmp1.y)) / 2; maximize(res, 0);
            if (res == 0) {
                minimize(mn, min({tmp1.water, tmp2.water, tmp3.water}));
                maximize(ans, mn);
            }
            else {
                minimize(mn, min({tmp1.water + res, tmp2.water - res - tcalc(tmp2.x, tmp2.y, tmp1.x, tmp1.y), tmp3.water}));
                maximize(ans, mn);
            }

            //Th2 a -> c
            tmp1 = srt[0], tmp2 = srt[1], tmp3 = srt[2]; mn = LLONG_MAX;
            res = (de) (tmp3.water - tmp1.water - tcalc(tmp3.x, tmp3.y, tmp1.x, tmp1.y)) / 2; maximize(res, 0);
            if (res == 0) {
                minimize(mn, min({tmp1.water, tmp2.water, tmp3.water}));
                maximize(ans, mn);
            }
            else {
                minimize(mn, min({tmp1.water + res, tmp3.water - res - tcalc(tmp3.x, tmp3.y, tmp1.x, tmp1.y), tmp2.water}));
                maximize(ans, mn);
            }

            //Th3 b -> c
            tmp1 = srt[0], tmp2 = srt[1], tmp3 = srt[2]; mn = LLONG_MAX;
            res = (de) (tmp3.water - tmp2.water - tcalc(tmp3.x, tmp3.y, tmp2.x, tmp2.y)) / 2; maximize(res, 0);
            if (res == 0) {
                minimize(mn, min({tmp1.water, tmp2.water, tmp3.water}));
                maximize(ans, mn);
            }
            else {
                minimize(mn, min({tmp2.water + res, tmp3.water - res - tcalc(tmp3.x, tmp3.y, tmp2.x, tmp2.y), tmp1.water}));
                maximize(ans, mn);
            }

            //Th4 a -> b -> c
            tmp1 = srt[0], tmp2 = srt[1], tmp3 = srt[2]; mn = LLONG_MAX;
            res = (de) (tmp2.water - tmp1.water - tcalc(tmp2.x, tmp2.y, tmp1.x, tmp1.y)) / 2; maximize(res, 0);
            if (res == 0) {
                minimize(mn, min({tmp1.water, tmp2.water, tmp3.water}));
                maximize(ans, mn);
            }
            else {
                minimize(mn, min({tmp1.water + res, tmp2.water - res - tcalc(tmp2.x, tmp2.y, tmp1.x, tmp1.y), tmp3.water}));
                tmp1.water += res;
                tmp2.water = tmp2.water - res - tcalc(tmp2.x, tmp2.y, tmp1.x, tmp1.y);
                maximize(ans, mn);
            }

            res = (de) (tmp3.water - tmp2.water - tcalc(tmp3.x, tmp3.y, tmp2.x, tmp2.y)) / 2; maximize(res, 0);
            if (res == 0) {
                minimize(mn, min({tmp1.water, tmp2.water, tmp3.water}));
                maximize(ans, mn);
            }
            else {
                minimize(mn, min({tmp2.water + res, tmp3.water - res - tcalc(tmp3.x, tmp3.y, tmp2.x, tmp2.y), tmp1.water}));
                maximize(ans, mn);
            }

            cout << fixed << setprecision(10) << (de) ans << '\n';
        }
    }
}

namespace sub2 {

    void solve(void) {
        sort(a + 1, a + n + 1, cmp);

        de ans = LLONG_MIN;

        For(i, 2, n, 1) {
            Data tmp1 = a[1], tmp2 = a[i]; de mn = LLONG_MAX;
            de res = (de) (tmp2.water - tmp1.water - tcalc(tmp2.x, tmp2.y, tmp1.x, tmp1.y)) / 2; maximize(res, 0);
            if (res == 0) {
                For(j, 1, n, 1) minimize(mn, a[j].water);
                maximize(ans, mn);
            }
            else {
                minimize(mn, tmp1.water + res);
                minimize(mn, tmp2.water - res - tcalc(tmp2.x, tmp2.y, tmp1.x, tmp1.y));
                For(j, 2, n, 1) if (j != i)
                    minimize(mn, a[j].water);
                maximize(ans, mn);
            }
        }

        cout << fixed << setprecision(10) << (de) ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("DROUGHT.INP", "r", stdin);
    freopen("DROUGHT.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);

    cin >> n;
    bool check_sub2 = true;
    For(i, 1, n, 1) {
        cin >> a[i].x >> a[i].y >> a[i].water;
        if (a[i].y != 0) check_sub2 = false;
    }

    if (sub1::check_dk()) sub1::solve();
    else sub2::solve();

    return 0;
}
