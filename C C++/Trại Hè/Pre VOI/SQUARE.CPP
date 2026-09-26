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
const int MOD = (int) 1e9 + 9999;
const int N = (int) 1e2 + 7;

int n, m, t, luu[N], a[N][N], sum[N][N];
ii(bool, int) check[N][N];

ll ltbinary(ll a, ll b) {
    a %= MOD; ll res = 1;
    while (b) {
        if (b & 1) res = ((res % MOD) * (a % MOD)) % MOD;
        a = ((a % MOD) * (a % MOD)) % MOD;
        b >>= 1;
    }
    return (res % MOD);
}

void sub1(void) {
    For(i, 1, n , 1) For(j, 1, m, 1) check[i][j].fi = false;
    For(i, 1, t, 1) {
        int x, y, val; cin >> x >> y >> val;
        check[x][y].fi = true; check[x][y].se = val;
    }

    int ans = 0;
    For(k, 0, mask(n * m) - 1, 1) {
        Rep(i, n * m) luu[i + 1] = bit(k, i);

        int idx = 1;
        For(i, 1, n, 1) For(j, 1, m, 1) a[i][j] = luu[idx++];

        bool ok = true;
        For(i, 1, n, 1) For(j, 1, m, 1) if (check[i][j].fi == true && check[i][j].se != a[i][j]) {
            ok = false;
            break;
        }

        if (!ok) continue;

        For(i, 1, n, 1) sum[i][0] = 0; For(j, 1, m, 1) sum[0][j] = 0;
        For(i, 1, n, 1) For(j, 1, m, 1) sum[i][j] = sum[i - 1][j] + sum[j][i - 1] - sum[i - 1][j - 1] + a[i][j];

        For(i, 1, n - 1, 1) if (ok) For(j, 1, m - 1, 1) {
            int h1 = i, h2 = i + 1, c1 = j, c2 = j + 1;
            if ((sum[h2][c2] - sum[h2][c1 - 1] - sum[h1 - 1][c2] + sum[h1 - 1][c1 - 1]) % 2 != 0) {
                ok = false;
                break;
            }
        }

        if (ok) ++ans;
    }
    cout << ans;
}

void sub2(void) {
    cout << ltbinary(2, n + m - t - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("SQUARE.INP", "r", stdin);
    freopen("SQUARE.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);

    cin >> n >> m >> t;

    if (1ll * n * m <= 20)
        sub1();
    else
        sub2();

    return 0;
}
