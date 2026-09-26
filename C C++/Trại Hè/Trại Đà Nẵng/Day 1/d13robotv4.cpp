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
const int M = (int) 4e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, a[N], f[M][M];

void solve(void) {
    //Calc first
    int idx_1 = n + 1, idx_2 = n + 1, new_n = 2 * n + 1;
    while (idx_1 > 0 && a[idx_1] == a[n + 1]) --idx_1; ++idx_1;
    while (idx_2 <= new_n && a[idx_2] == a[n + 1]) ++idx_2; --idx_2;

    //Init
    memset(f, 0x3f, sizeof(f));
    f[idx_1][idx_2] = 0;
    queue <ii(int, int)> qe;
    qe.push({idx_1, idx_2});

    //Calc
    while (!qe.empty()) {
        ii(int, int) top = qe.fr(); qe.pop();
        //Th 1
        if (top.fi > 1) {
            int tidx_1 = top.fi - 1, tidx_2 = top.se + 1;
            while (tidx_1 > 0 && a[tidx_1] == a[top.fi - 1]) --tidx_1; ++tidx_1;
            while (tidx_2 <= new_n && a[tidx_2] == a[top.fi - 1]) ++tidx_2; --tidx_2;
            if (minimize(f[tidx_1][tidx_2], f[top.fi][top.se] + 1))
                qe.push({tidx_1, tidx_2});
        }

        //Th 2
        if (top.se < new_n) {
            int tidx_1 = top.fi - 1, tidx_2 = top.se + 1;
            while (tidx_1 > 0 && a[tidx_1] == a[top.se + 1]) --tidx_1; ++tidx_1;
            while (tidx_2 <= new_n && a[tidx_2] == a[top.se + 1]) ++tidx_2; --tidx_2;
            if (minimize(f[tidx_1][tidx_2], f[top.fi][top.se] + 1))
                qe.push({tidx_1, tidx_2});
        }
    }
    cout << f[1][new_n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n * 2 + 1, 1) cin >> a[i];

    solve();

    return 0;
}
