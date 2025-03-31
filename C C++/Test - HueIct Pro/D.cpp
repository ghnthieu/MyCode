#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb pop_back
#define pub push_back
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector<kdl>
#define ii(kdl1, kdl2) pair<kdl1, kdl2>
#define vii(kdl1, kdl2) vector<pair<kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

ii(int, int) gett(int idx, int n) {
    if (idx <= n) return {idx, 0};
    if (idx <= 2 * n) return {n, idx - n};
    if (idx <= 3 * n) return {3 * n - idx, n};
    return {0, 4 * n - idx};
}

bool check(ii(int, int) A, ii(int, int) B, ii(int, int) C, ii(int, int) D) {
    auto tmp = [](ii(int, int) A, ii(int, int) B, ii(int, int) C) {
        return (C.fi - A.fi) * (B.se - A.se) - (B.fi - A.fi) * (C.se - A.se);
    };

    int d1 = tmp(A, B, C), d2 = tmp(A, B, D), d3 = tmp(C, D, A), d4 = tmp(C, D, B);
    return (d1 * d2 < 0 && d3 * d4 < 0);
}

int n, m;
vii(ii(int, int), ii(int, int)) seg;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
     //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;

    int ans = 1;
    Rep(edge, m) {
        int x, y; cin >> x >> y;
        ii(int, int) A = gett(x, n), B = gett(y, n);
        Rep(j, seg.size()) if (check(A, B, seg[j].fi, seg[j].se))
            ++ans;
        seg.pub({A, B});
        ++ans;
    }
    cout << ans;

    return 0;
}
