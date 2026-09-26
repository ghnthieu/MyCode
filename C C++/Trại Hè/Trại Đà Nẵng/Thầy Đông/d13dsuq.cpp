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
const int N = (int) 1e7 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q, x, y, z, MOD, a[N], tree[4 * N];

void build(int id, int l, int r) {
    if (l == r)
        tree[id] = a[l];
    else {
        int m = l + r >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
    }
}

int get_mx(int id, int l, int r, int u, int v) {
    if (l > v || u > r) return 0;
    if (l >= u && v >= r) return tree[id];
    int m = l + r >> 1;
    return max(get_mx(id << 1, l, m, u, v), get_mx(id << 1 | 1, m + 1, r, u, v));
}

void add(ll &x, ll y) {
    x += y;
    x -= ((x >= MOD) ? MOD : 0);
}

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

    cin >> n >> q >> x >> y >> z >> MOD;

    a[1] = x;
    For(i, 2, n, 1) a[i] = (1ll * a[i - 1] * y + z) % MOD;
    build(1, 1, n);

    ll ans = 0;
    For(i, 1, q, 1) {
        int l = min(1ll * i % n + 1, 1ll * i * i % n + 1), r = max(1ll * i % n + 1, 1ll * i * i % n + 1);
        add(ans, get_mx(1, 1, n, l, r));
    }
    cout << ans;

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
