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
const ll oo = (ll) 1e18 + 7ll;
const int N = (int) 3e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q;
ll sto[N];

void sub1(void) {
    Rep(query, q) {
        int type; cin >> type;
        if (type == 1) {
            int idx; ll val; cin >> idx >> val;
            For(i, 1, idx, 1) sto[i] = max(sto[i], val);
        }
        else {
            int idx; ll mon; cin >> idx >> mon;
            int res = 0;
            while (idx <= n) {
                if (mon == 0) break;
                if (sto[idx] <= mon) {
                    mon -= sto[idx];
                    ++res;
                }
                ++idx;
            }
            cout << res << '\n';
        }
    }
}

struct tvy {
    ll val, min, lazy;
} tree[4 * N];

void build(int id, int l, int r) {
    if (l == r) {
        tree[id].val = sto[l];
        tree[id].min = sto[l];
    }
    else {
        int m = l + r >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        tree[id].val = tree[id << 1].val + tree[id << 1 | 1].val;
        tree[id].min = min(tree[id << 1].min, tree[id << 1 | 1].min);
    }
}

void fix(int id, int l, int r) {
    if (!tree[id].lazy) return;
    tree[id].val = 1ll * (r - l + 1) * tree[id].lazy;
    tree[id].min = tree[id].lazy;
    if (l != r) {
        maximize(tree[id << 1].lazy, tree[id].lazy);
        maximize(tree[id << 1 | 1].lazy, tree[id].lazy);
    }
    tree[id].lazy = 0;
}

ll get_min(int id, int l, int r, int idx) {
    fix(id, l, r);
    if (l > idx || idx > r) return oo;
    if (l == r) return tree[id].min;
    int m = l + r >> 1;
    return min(get_min(id << 1, l, m, idx), get_min(id << 1 | 1, m + 1, r, idx));
}

void update(int id, int l, int r, int u, int v, ll val) {
    fix(id, l, r);
    if (l > v || u > r) return;
    if (l >= u && v >= r) {
        maximize(tree[id].lazy, val);
        fix(id, l, r);
        return;
    }
    int m = l + r >> 1;
    update(id << 1, l, m, u, v, val);
    update(id << 1 | 1, m + 1, r, u, v, val);
    tree[id].val = tree[id << 1].val + tree[id << 1 | 1].val;
    tree[id].min = min(tree[id << 1].min, tree[id << 1 | 1].min);
}

ll sum, ans;

void get(int id, int l, int r, int u, int v) {
    fix(id, l, r);
    if (l > v || u > r) return;
    if (l >= u && v >= r) {
        if (sum < tree[id].min) return;
        if (l == r) {
            sum -= tree[id].min;
            ++ans;
            return;
        }
        int m = l + r >> 1;
        if (tree[id].val <= sum) {
            sum -= tree[id].val;
            ans += (r - l + 1);
        }
        else {
            get(id << 1, l, m, u, v);
            get(id << 1 | 1, m + 1, r, u, v);
        }
        return;
    }
    int m = l + r >> 1;
    get(id << 1, l, m, u, v);
    get(id << 1 | 1, m + 1, r, u, v);
}

void sub2(void) {
    build(1, 1, n);
    Rep(query, q) {
        int type; cin >> type;
        if (type == 1) {
            int idx; ll val; cin >> idx >> val;
            int l = 1, r = idx, res = -1;
            while (l <= r) {
                int m = l + r >> 1;
                if (get_min(1, 1, n, m) <= val) {
                    res = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            if (res != -1) update(1, 1, n, res, idx, val);
        }
        else {
            int idx; ll val; cin >> idx >> val;
            sum = val; ans = 0;
            get(1, 1, n, idx, n);
            cout << ans << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("STORE.inp", "r", stdin);
    freopen("STORE.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) cin >> sto[i];
    cin >> q;

    if (n <= 5e3 && q <= 5e3)
        sub1();
    else
        sub2();

    return 0;
}
