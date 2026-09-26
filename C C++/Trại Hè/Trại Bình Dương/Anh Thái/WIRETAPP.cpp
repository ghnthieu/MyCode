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
#define bit(n, i) (((/n) >> (i)) & 1)
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

int n, m;

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

    cin >> n >> m;
    if (m == 1) {
        int x, y, w; cin >> x >> y >> w;
        For(i, 1, n, 1) cout << ((i == x) ? w : 0) << " ";
    }
    else if (m == 2) {
        int x1, y1, w1, x2, y2, w2; cin >> x1 >> y1 >> w1 >> x2 >> y2 >> w2;
        if (x1 > y1) swap(x1, y1); if (x2 > y2) swap(x2, y2);
        if (x1 == x2 && y1 == y2)
            For(i, 1, n, 1) cout << ((i == x1) ? min(w1, w2) : 0) << " ";
        else if (x1 != x2 && x1 != y2 && y1 != x2 && y1 != y2) {
            For(i, 1, n, 1) {
                if (i == x1)
                    cout << w1 << " ";
                else if (i == x2)
                    cout << w2 << " ";
                else
                    cout << 0 << " ";
            }
        }
        else if (y1 == x2) {
            For(i, 1, n, 1) {
                if (i == y1)
                    cout << min(w1, w2) << " ";
                else if (i == x1)
                    cout << w1 - min(w1, w2) << " ";
                else if (i == y2)
                    cout << w2 - min(w1, w2) << " ";
                else
                    cout << 0 << " ";
            }
        }
        else {
            For(i, 1, n, 1) {
                if (i == x1)
                    cout << w1 << " ";
                else if (i == x2)
                    cout << w2 << " ";
                else
                    cout << 0 << " ";
            }
        }
    }
    else if (n == 1) {
        cout << 0;
    }
    else if (n == 2) {
        int ans = INT_MAX;
        For(i, 1, m, 1) {
            int x, y, w; cin >> x >> y >> w;
            minimize(ans, w);
        }
        cout << ans << " " << 0;
    }
    else
        cout << "invalid";

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
