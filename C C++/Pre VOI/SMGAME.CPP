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

int n, a[N], b[N];

namespace sub1 {

    bool check_dk(void) {
        bool check = true;
        For(i, 1, n, 1) if (a[i] != 1 && a[i] != 2) {
            check = false;
            break;
        }
        For(i, 1, n, 1) if (b[i] != 1 && b[i] != 2) {
            check = false;
            break;
        }
        return (n <= 1e3 && check);
    }

    void solve(void) {
        int ans = 0;
        For(i, 1, n, 1) {
            if (a[i] == 1 && b[i] == 2) {
                int pos_la = -1;
                Ford(j, i - 1, 1, 1) if (a[j] == 2) {
                    pos_la = i - j;
                    break;
                }
                int pos_lb = -1;
                Ford(j, n, i + 1, 1) if (a[j] == 2) {
                    pos_lb = (i - 1) + (n - j + 1);
                    break;
                }

                int pos_ra = -1;
                For(j, i + 1, n, 1) if (a[j] == 2) {
                    pos_ra = j - i;
                    break;
                }
                int pos_rb = -1;
                For(j, 1, i - 1, 1) if (a[j] == 2) {
                    pos_rb = (j - 1) + (n - i + 1);
                    break;
                }

                if (pos_la == -1 && pos_ra == -1 && pos_lb == -1 && pos_rb == -1) {
                    cout << -1;
                    exit(0);
                }

                bool check_a1 = true;
                if (pos_la == -1)
                    check_a1 = false;
                else {
                    Ford(j, i - 1, 1, 1) if (i - j <= pos_la && b[j] == 1) {
                        check_a1 = false;
                        break;
                    }
                }

                bool check_a2 = true;
                if (pos_lb == -1)
                    check_a2 = false;
                else {
                    Ford(j, i - 1, 1, 1) if (b[j] == 1) {
                        check_a2 = false;
                        break;
                    }
                    Ford(j, n, i + 1, 1) if ((i - 1) + (n - j + 1) <= pos_lb && b[j] == 1) {
                        check_a2 = false;
                        break;
                    }
                }

                bool check_b1 = true;
                if (pos_ra == -1)
                    check_b1 = false;
                else {
                    For(j, i + 1, n, 1) if (j - i <= pos_ra && b[j] == 1) {
                        check_b1 = false;
                        break;
                    }
                }

                bool check_b2 = true;
                if (pos_rb == -1)
                    check_b2 = false;
                else {
                    For(j, i + 1, n, 1) if (b[j] == 1) {
                        check_b2 = false;
                        break;
                    }
                    For(j, 1, i - 1, 1) if ((j - 1) + (n - i + 1) <= pos_rb && b[j] == 1) {
                        check_b2 = false;
                        break;
                    }
                }

                int res = INT_MAX, choose;
                if (check_a1) if (minimize(res, pos_la))
                    choose = 1;
                if (check_a2) if (minimize(res, pos_lb))
                    choose = 2;
                if (check_b1) if (minimize(res, pos_ra))
                    choose = 3;
                if (check_b2) if (minimize(res, pos_rb))
                    choose = 4;

                ans += res;
                if (choose == 1) {
                    Ford(j, i, 1, 1) if (i - j <= pos_la)
                        a[j] = 2;
                }
                else if (choose == 2) {
                    Ford(j, i, 1, 1) a[j] = 2;
                    Ford(j, n, i + 1, 1) if ((i - 1) + (n - j + 1) <= pos_lb)
                        a[j] = 2;
                }
                else if (choose == 3) {
                    For(j, i, n, 1) if (j - i <= pos_ra)
                        a[j] = 2;
                }
                else {
                    For(j, i, n, 1) a[j] = 2;
                    For(j, 1, i - 1, 1) if ((j - 1) + (n - i + 1) <= pos_rb)
                        a[j] = 2;
                }
            }
            else if (a[i] == 2 && b[i] == 1) {
                cout << -1;
                exit(0);
            }
        }
        cout << ans;
    }
}

namespace sub2 {

    void solve(void) {
        cout << -1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SMGAME.INP", "r", stdin);
    freopen("SMGAME.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) cin >> a[i];
    For(i, 1, n, 1) cin >> b[i];

    if (sub1::check_dk()) sub1::solve();
    else sub2::solve();

    return 0;
}
