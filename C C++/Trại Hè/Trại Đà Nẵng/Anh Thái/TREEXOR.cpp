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

/*-----------------------------------------------------------------------------------------------------------------*/

int n, x, xorr[N], cnt = 0;
vec(int) inp[N];

void dfs(int u, int par) {
    for (int v : inp[u]) {
        if (v == par) continue;
        dfs(v, u);
        xorr[u] ^= xorr[v];
    }
    if (xorr[u] == 0 && u != 1) ++cnt;
}

ll ltbinary(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b) {
        if (b & 1)
            res = ((res % MOD) * (a % MOD)) % MOD;
        a = ((a % MOD) * (a % MOD)) % MOD;
        b >>= 1;
    }
    return (res % MOD);
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> x;
    For(i, 1, n, 1) cin >> xorr[i];
    For(i, 1, n - 1, 1) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
    }
    dfs(1, -1);

    cout << ltbinary(2, cnt);

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
