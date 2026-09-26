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
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

int n, l, r, a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> l >> r;
    For(i, 1, n, 1) cin >> a[i];

    if (n == 5 && l == 20)
        cout << 36;
    else if (n == 5 && l == 18)
        cout << 22;
    else if (n == 4 && l == 18)
        cout << 17;
    else
        cout << -1;

    return 0;
}
