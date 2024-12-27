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
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q, a[N];

void sub1(void) {
    Rep(query, q) {
        int type; cin >> type;
        if (type == 0) {
            int l, r, val; cin >> l >> r >> val;
            For(i, l, r, 1) a[i] ^= val;
        }
        else {
            int l, r; cin >> l >> r;
            ll sum = 0;
            For(i, l, r, 1) sum += a[i];
            cout << sum << '\n';
        }
    }
}

ll tree[4 * N], lazy[4 * N];

void build(int id, int l, int r) {
    if (l == r)
        tree[id] = a[l];
    else {
        int m = l + r >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        tree[id] = tree[id << 1] + tree[id << 1 | 1];
    }
}

void fix(int id, int l, int r) {
    if (!lazy[id]) return;
    tree[id] ^= (r - l + 1) * lazy[id];
    if (l != r) {
        lazy[id << 1] ^= lazy[id];
        lazy[id << 1 | 1] ^= lazy[id];
    }
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    fix(id, l, r);
    if (l > v || u > r) return;
    if (l >= u && v >= r) {
        lazy[id] ^= val;
        fix(id, l, r);
        return;
    }
    int m = l + r >> 1;
    update(id << 1, l, m, u, v, val);
    update(id << 1 | 1, m + 1, r, u, v, val);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

ll get_ans(int id, int l, int r, int u, int v) {
    fix(id, l, r);
    if (l > v || u > r) return 0;
    if (l >= u && v >= r) return tree[id];
    int m = l + r >> 1;
    return get_ans(id << 1, l, m, u, v) + get_ans(id << 1 | 1, m + 1, r, u, v);
}

void sub2(void) {
    build(1, 1, n);
    Rep(query, q) {
        int type; cin >> type;
        if (type == 0) {
            int l, r, val; cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
        else {
            int l, r; cin >> l >> r;
            cout << get_ans(1, 1, n, l, r) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("LZXOR.INP", "r", stdin);
    freopen("LZXOR.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) cin >> a[i];
    cin >> q;

    if (n <= 5e3 && q <= 5e3)
        sub1();
    else
        sub2();

    return 0;
}
