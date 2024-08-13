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
const int MOD = (int) 998244353;
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q, a, b;
ll tree[4 * N], gt[N], val[N];

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
void build(int id, int l, int r) {
    if (l == r)
        tree[id] = gt[l];
    else {
        int mid = l + r >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        tree[id] = tree[id << 1] + tree[id << 1 | 1];
        tree[id] %= MOD;
    }
}

ll get(int id, int l, int r, int u, int v) {
    if (u > r || l > v) return 0;
    if (u <= l && r <= v)
        return tree[id] % MOD;
    else {
        int m = l + r >> 1;
        return get(id << 1, l, m, u, v) % MOD + get(id << 1 | 1, m + 1, r, u, v) % MOD;
    }
}

void update(int id, int l, int r, int pos, ll value) {
    if (l == r)
        tree[id] = value;
    else {
        int m = l + r >> 1;
        if (pos <= m)
            update(id << 1, l, m, pos, value);
        else
            update(id << 1 | 1, m + 1, r, pos, value);
        tree[id] = tree[id << 1] + tree[id << 1 | 1];
        tree[id] %= MOD;
    }
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

    cin >> n >> q >> a >> b;
    For(i, 1, n, 1) cin >> val[i];

    For(i, 1, n, 1) gt[i] = ltbinary(a, val[i]) * ltbinary(val[i], b) % MOD;
    build(1, 1, n);
    Rep(query, q) {
        int type; cin >> type;
        if (type == 1) {
            int l, r; ll value; cin >> l >> r >> value;
            value %= MOD;
            For(i, l, r, 1) {
                val[i] += value;
                update(1, 1, n, i, ltbinary(a, val[i]) * ltbinary(val[i], b) % MOD);
            }
        }
        else {
            int l, r; cin >> l >> r;
            cout << get(1, 1, n, l, r) % MOD << '\n';
        }
    }

    return 0;
}
