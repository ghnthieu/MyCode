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
const int N = (int) 1e5 + 7;
const int M = (int) 5e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int tcase, n, idx_a, idx_b, ans[N];

struct Data {
    int x, y, z;
} a[N];

vec(int) inp[M];

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
        cin >> n >> idx_a >> idx_b;
        For(i, 1, n, 1) {
            cin >> a[i].x >> a[i].y >> a[i].z;
            inp[a[i].x].pub(i);
            inp[a[i].y].pub(i);
            inp[a[i].z].pub(i);
        }

        memset(ans, -1, (n + 1) * sizeof(int));
        queue <int> q; q.push(idx_a);
        ans[idx_a] = 0;
        while (!q.empty()) {
            int i = q.fr(); q.pop();
            for (int x : inp[a[i].x]) if (ans[x] == -1) {
                ans[x] = ans[i] + 1;
                q.push(x);
            }
            inp[a[i].x].clear();

            for (int x : inp[a[i].y]) if (ans[x] == -1) {
                ans[x] = ans[i] + 1;
                q.push(x);
            }
            inp[a[i].y].clear();

            for (int x : inp[a[i].z]) if (ans[x] == -1) {
                ans[x] = ans[i] + 1;
                q.push(x);
            }
            inp[a[i].z].clear();
        }

        For(i, 1, n, 1) {
            inp[a[i].x].clear();
            inp[a[i].y].clear();
            inp[a[i].z].clear();
        }

        cout << ans[idx_b] << '\n';
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
