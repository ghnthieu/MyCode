#include <bits/stdc++.h>
using namespace std;

#define NAME "MAXMUL"
#define fi first
#define se second
#define fr front
#define bk back
#define pf pop_front
#define pb pop_back
#define puf push_front
#define pub push_back
#define NOT 18446744073709551615
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <kdl1,kdl2>,kdl3>>

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

ll n, q, a[N];
ll tree[4 * N];

void build(int v, int l, int r) {
    if (l == r)
        tree[v] = a[l];
    else {
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        tree[v] = ((tree[2 * v] % MOD) * (tree[2 * v + 1] % MOD) % MOD);
    }
}

int get(int v, int treel, int treer, int l, int r) {
    if (treel > r || treer < l)
        return 1;
    if (treel >= l && treer <= r)
        return tree[v] % MOD;
    else {
        int treem = treel + treer >> 1;
        ll get1 = get(2 * v, treel, treem, l , r) % MOD;
        ll get2 = get(2 * v + 1, treem + 1, treer, l, r) % MOD;
        return (get1 * get2) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);

    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    cin >> q;
    if (n <= 1e3 && q <= 1e3) {
        while (q--) {
            int x, y; cin >> x >> y;
            ll ans = 1;
            for (int i=x; i<=x+y-1; ++i)
                ans = (ans * a[i]) % MOD;
            cout << ans << '\n';
        }
    }
    else {
        build(1, 1, n);
        while (q--) {
            int x, y; cin >> x >> y;
            cout << get(1, 1, n, x, x+y-1) % MOD << '\n';
        }
    }

    return 0;
}
