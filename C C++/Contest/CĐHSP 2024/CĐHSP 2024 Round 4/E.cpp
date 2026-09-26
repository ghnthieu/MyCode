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
const int N = (int) 4e2 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, duong[N][N];

void solve(void) {
    ll ans = LLONG_MAX;
    Rep(k, mask(n)) {
        vec(int) luu_bit1, luu_bit0;
        For(i, 1, n, 1) {
            if (bit(k, (i - 1)))
                luu_bit1.pub(i);
            else
                luu_bit0.pub(i);
        }

        ll mx1 = 0, mx2 = 0;
        Rep(i, luu_bit1.size()) For(j, i + 1, luu_bit1.size() - 1, 1)
            maximize(mx1, duong[luu_bit1[i]][luu_bit1[j]]);
        Rep(i, luu_bit0.size()) For(j, i + 1, luu_bit0.size() - 1, 1)
            maximize(mx2, duong[luu_bit0[i]][luu_bit0[j]]);

        minimize(ans, mx1 + mx2);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n - 1, 1) For(j, i + 1, n, 1) {
        int w; cin >> w;
        duong[i][j] = w;
        duong[j][i] = w;
    }
    For(k, 1, n, 1) For(u, 1, n, 1) For(v, 1, n, 1)
        minimize(duong[u][v], duong[u][k] + duong[k][v]);

    solve();

    return 0;
}
