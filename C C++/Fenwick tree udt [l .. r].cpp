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
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q;
ll udt[N], sum[N];

void update(int u, int v) {
    for (int i = u; i <= n; i += i & -i) {
        udt[i] += v;
        sum[i] += 1ll * u * v;
    }
}

void upp(int l, int r, int v) {
    update(l, v); update(r + 1, -v);
}

ll get(int u) {
    ll ans = 0;
    for (int i = u; i > 0; i -= i & -i)
        ans += 1ll * (u + 1) * udt[i] - sum[i];
    return ans;
}

ll get_mul(int l, int r) {
    return get(r) - get(l - 1);
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    For(i, 1, n, 1) {
        int x; cin >> x;
        upp(i, i, x);
    }

    Rep(query, q) {
        int type; cin >> type;
        if (type == 1) {
            int l, r, k; cin >> l >> r >> k;
            upp(l, r, k);
        }
        else {
            int l, r; cin >> l >> r;
            cout << get_mul(l, r) << '\n';
        }
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
