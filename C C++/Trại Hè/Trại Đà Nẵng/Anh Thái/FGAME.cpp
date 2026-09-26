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

int n, m, a[N][N];
ll pre[N][N];

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

    Rep(test_case, 5) {
        cin >> n >> m;
        For(i, 1, n, 1) For(j, 1, m, 1) {
            cin >> a[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }

        ll sum = pre[n][m];
        if (sum % 3 == 1)
            cout << 1 << '\n';
        else if (sum % 3 == 2)
            cout << 0 << '\n';
        else {
            //cout << sum[h2][c2] - sum[h1-1][c2] - sum[h2][c1-1] + sum[h1-1][c1-1] << endl;
            bool check = false;
            For(i, 1, n, 1) { //n - m ; i - 1
                ll sum = pre[n][m] - pre[i - 1][m] - pre[n][0] + pre[i - 1][0];
                if (sum % 3 == 1) check = true;
            }
            For(j, 1, m, 1) { //n - m ; 1 - j
                ll sum = pre[n][m] - pre[0][m] - pre[n][j - 1] + pre[0][j - 1];
                if (sum % 3 == 1) check = true;
            }
            cout << ((check) ? 1 : 0) << '\n';
        }
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
