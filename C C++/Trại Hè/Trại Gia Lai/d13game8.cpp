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
const int N = (int) 1e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int tcase, n, a[N][N];

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

    cin >> tcase;
    Rep(test_case, tcase) {
        cin >> n;
        For(i, 1, n, 1) For(j, 1, n, 1) cin >> a[i][j];

        int ans = 0;
        while (true) {
            bool check = false;
            For(i, 1, n, 1) {
                bool ok = true;
                For(j, 1, n, 1) if (a[i][j] < 0 && a[i][j] != INT_MIN) {
                    ok = false;
                    break;
                }

                int cnt = 0;
                For(j, 1, n, 1) if (a[i][j] > 0) ++cnt;

                if (ok && cnt == n) { check = true; break; }
            }

            //cout << check << '\n';

            if (check) {
                int mx = 0, pos = 0;
                For(i, 1, n, 1) {
                    bool ok = true;
                    For(j, 1, n, 1) if (a[i][j] < 0 && a[i][j] != INT_MIN) {
                        ok = false;
                        break;
                    }
                    if (ok) {
                        int mn_h = INT_MAX;
                        For(j, 1, n, 1) if (a[i][j] != INT_MIN)
                            minimize(mn_h, a[i][j]);
                        if (maximize(mx, mn_h))
                            pos = i;
                    }
                }

                int res = INT_MAX, poss = 0;
                For(j, 1, n, 1) if (a[pos][j] != INT_MIN) if (minimize(res, a[pos][j]))
                    poss = j;
                ans += res;
                //cout << ans << '\n';
                For(i, 1, n, 1) a[i][poss] = INT_MIN;
                For(j, 1, n, 1) a[pos][j] = INT_MIN;
                /*For(i, 1, n, 1) {
                    For(j, 1, n, 1) cout << a[i][j] << " ";
                    cout << '\n';
                }*/
            }
            else {
                int mx = INT_MIN + 1, pos = 0;
                For(i, 1, n, 1) {
                    int mx_h = INT_MIN + 1;
                    For(j, 1, n, 1) if (a[i][j] < 0 && a[i][j] != INT_MIN)
                        maximize(mx_h, a[i][j]);
                    if (maximize(mx, mx_h))
                        pos = i;
                }

                if (mx == INT_MIN + 1) {
                    For(i, 1, n, 1) {
                        int mx_h = INT_MIN + 1;
                        For(j, 1, n, 1) if (a[i][j] > 0)
                            maximize(mx_h, a[i][j]);
                        if (maximize(mx, mx_h))
                            pos = i;
                    }
                }
                //cout << mx << '\n';

                int res = INT_MIN + 1, poss = 0;
                For(j, 1, n, 1) if (a[pos][j] < 0 && a[pos][j] != INT_MIN) if (maximize(res, a[pos][j]))
                    poss = j;

                if (res == INT_MIN + 1) {
                    For(j, 1, n, 1) if (a[pos][j] > 0) if (maximize(res, a[pos][j]))
                        poss = j;
                }
                ans += res;
                For(i, 1, n, 1) a[i][poss] = INT_MIN;
                For(j, 1, n, 1) a[pos][j] = INT_MIN;

                //cout << mx << '\n';
            }

            bool conti = false;
            For(i, 1, n, 1) For(j, 1, n, 1) if (a[i][j] != INT_MIN) {
                conti = true;
                break;
            }

            if (!conti) break;
        }

        cout << ans << '\n';
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
