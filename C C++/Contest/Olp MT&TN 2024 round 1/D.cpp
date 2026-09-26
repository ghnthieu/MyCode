#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define NAME ""
#define fi first
#define se second
#define fr front
#define bk back
#define pf pop_front
#define pb pop_back
#define puf push_front
#define pub push_back
#define NOT 18446744073709551615
#define __Trung_Hieu___ signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define bit(n, i) ((n >> i) & 1)
#define mask(i) (1ll << i)
#define vec(kdl) vector <kdl>
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1,kdl2>,kdl3>>
template <typename T1, typename T2> void maximize(T1 &a, T2 b) { if (a < b) a = b; }
template <typename T1, typename T2> void minimize(T1 &a, T2 b) { if (a > b) a = b; }

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
typedef long double lde;
const int MOD = (int) 1e9 + 7;
const int N = (int) 4e5 + 7;

int n, q, arr[N];

void add(ll &a, ll b) {
    a *= b;
    a %= MOD;
    a += ((a == 0) ? MOD : 0);
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> n >> q;
    for (int i=1; i<=n; ++i)
        cin >> arr[i];
    while (q--) {
        int l, r, x, y, k; cin >> l >> r >> x >> y >> k;
        ll res = 1;
        for (int i=l; i<=r; ++i) {
            if (x <= arr[i] && arr[i] <= y)
                add(res, ltbinary(arr[i], k));
        }
        cout << res << '\n';
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
