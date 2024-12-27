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

int n, q, k;
ll a[N];

struct Query {
    int type, l, r, val;
} que[N];

void add(ll &x, ll y) {
    x += y;
    x -= ((x >= MOD) ? MOD : 0);
    x += ((x < 0) ? MOD : 0);
}

namespace sub1 {

    bool check_dk(void) {
        return (n <= 5e3 && q <= 5e3);
    }

    ll pre[N];

    void init_pre(void) {
        pre[0] = 0;
        For(i, 1, n, 1) {
            pre[i] = pre[i - 1];
            add(pre[i], a[i]);
        }
    }

    void solve(void) {
        For(qu, 1, q, 1) {
            int type = que[qu].type;
            if (type == 1) {
                int l = que[qu].l, r = que[qu].r, val = que[qu].val;
                For(i, l, r, 1) add(a[i], 1ll * val);
            }
            else {
                int l = que[qu].l, r = que[qu].r;
                ll ans = 0; init_pre();
                For(i, l, r, 1) {
                    if (i + k <= r) add(ans, a[i] * (pre[r] - pre[i + k - 1]) % MOD);
                    else break;
                }
                cout << ans << '\n';
            }
        }
    }
}

namespace sub2 {

    bool check_dk(void) {
        return (k == 1);
    }

    struct Node {
        ll sum, ans;
    };

    Node tree[4 * N]; ll lazy[4 * N];

    Node merge(Node a, Node b) {
        Node res = {0, 0};
        res.sum = a.sum; add(res.sum, b.sum);
        res.ans = a.ans; add(res.ans, b.ans);
        add(res.ans, a.sum * b.sum % MOD);
        return res;
    }

    void build(int id, int l, int r) {
        if (l == r)
            tree[id] = {a[l], 0};
        else {
            int m = l + r >> 1;
            build(id << 1, l, m);
            build(id << 1 | 1, m + 1, r);
            tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
        }
    }

    void fix(int id, int l, int r) {
        if (!lazy[id]) return;
        add(tree[id].ans, (lazy[id] * lazy[id] % MOD * ((r - l + 1) * (r - l) / 2) % MOD + lazy[id] * (r - l) % MOD * tree[id].sum % MOD) % MOD);
        add(tree[id].sum, 1ll * (r - l + 1) * lazy[id] % MOD);
        if (l != r) {
            add(lazy[id << 1], lazy[id]);
            add(lazy[id << 1 | 1], lazy[id]);
        }
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        fix(id, l, r);
        if (l > v || u > r) return;
        if (l >= u && v >= r) {
            add(lazy[id], val);
            fix(id, l, r);
            return;
        }
        int m = l + r >> 1;
        update(id << 1, l, m, u, v, val);
        update(id << 1 | 1, m + 1, r, u, v, val);
        tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
    }

    Node get(int id, int l, int r, int u, int v) {
        fix(id, l, r);
        if (l > v || u > r) return {0, 0};
        if (l >= u && v >= r) return tree[id];
        int m = l + r >> 1;
        return merge(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }

    void solve(void) {
        build(1, 1, n);
        For(qu, 1, q, 1) {
            int type = que[qu].type;
            if (type == 1) {
                int l = que[qu].l, r = que[qu].r, val = que[qu].val;
                update(1, 1, n, l, r, val);
            }
            else {
                int l = que[qu].l, r = que[qu].r;
                cout << get(1, 1, n, l, r).ans << '\n';
            }
        }
    }
}

namespace sub3 {

    struct Node {
        ll sum, ans, pre[6], suf[6];
        int l, r;

        Node(void) {
            sum = ans = l = r = 0;
            memset(pre, 0, sizeof(pre));
            memset(suf, 0, sizeof(suf));
        }
    };

    void sub(ll &x, ll y) {
        x -= y;
        x += ((x < 0) ? MOD : 0);
    }

    Node tree[4 * N]; ll lazy[4 * N];

    Node merge(Node a, Node b) {
        if (a.ans == -1) return b;
        if (b.ans == -1) return a;

        Node res;
        int sz_a = a.r - a.l + 1, sz_b = b.r - b.l + 1;
        For(i, 1, k, 1) res.pre[i] = a.pre[i];
        For(i, sz_a + 1, k, 1) res.pre[i] = b.pre[i - sz_a];
        For(i, 1, k, 1) res.suf[i] = b.suf[i];
        For(i, sz_b + 1, k, 1) res.suf[i] = a.suf[i - sz_b];
        res.l = a.l; res.r = b.r;
        add(res.sum, a.sum); add(res.sum, b.sum);
        add(res.ans, a.ans); add(res.ans, b.ans);
        ll sum = b.sum, tsum = a.sum; int cnt = 0;
        Ford(i, k, 1, 1) {
            add(res.ans, 1ll * a.suf[i] * sum % MOD);
            sub(sum, b.pre[k - i + 1]);
            sub(tsum, a.suf[i]);
        }
        if (a.r - a.l + 1 > k) add(res.ans, 1ll * tsum * b.sum % MOD);

        return res;
    }

    void build(int id, int l, int r) {
        if (l == r) {
            tree[id].sum = a[l];
            tree[id].l = l; tree[id].r = r;
            tree[id].pre[1] = a[l];
            tree[id].suf[1] = a[r];
        }
        else {
            int m = l + r >> 1;
            build(id << 1, l, m);
            build(id << 1 | 1, m + 1, r);
            tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
        }
    }

    ll ltbinary(ll a, ll b) {
        a %= MOD; ll res = 1;
        while (b) {
            if (b & 1) res = ((res % MOD) * (a % MOD)) % MOD;
            a = ((a % MOD) * (a % MOD)) % MOD;
            b >>= 1;
        }
        return (res % MOD);
    }

    ll pw = ltbinary(2, MOD - 2);

    void fix(int id, int l, int r) {
        if (!lazy[id]) return;

        ll x = lazy[id], tmp = r - l + 2 - 2 * k; maximize(tmp, 0ll);
        ll val_1 = 0, val_2 = 0, sum = tree[id].sum;
        For(i, 1, k, 1) {
            int left = l + i + k - 1;
            int cnt_l = r - left + 1; maximize(cnt_l, 0);
            int right = r - i - k + 1;
            int cnt_r = right - l + 1; maximize(cnt_r, 0);
            add(val_1, 1ll * x * tree[id].pre[i] % MOD * cnt_l);
            add(val_1, 1ll * x * tree[id].suf[i] % MOD * cnt_r);
            sub(sum, tree[id].pre[i]);
            sub(sum, tree[id].suf[i]);
        }
        add(val_1, 1ll * x * sum % MOD * tmp % MOD);
        ll du = r - l - k + 1; maximize(du, 0ll);
        val_2 = 1ll * du * (du + 1) % MOD * pw % MOD * x % MOD * x % MOD;
        add(tree[id].ans, (val_1 + val_2) % MOD);
        add(tree[id].sum, 1ll * (r - l + 1) * x % MOD);
        For(i, 1, min(r - l + 1, k), 1) {
            add(tree[id].pre[i], x);
            add(tree[id].suf[i], x);
        }

        if (l != r) {
            add(lazy[id << 1], lazy[id]);
            add(lazy[id << 1 | 1], lazy[id]);
        }
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        fix(id, l, r);
        if (l > v || u > r) return;
        if (l >= u && v >= r) {
            add(lazy[id], val);
            fix(id, l, r);
            return;
        }
        int m = l + r >> 1;
        update(id << 1, l, m, u, v, val);
        update(id << 1 | 1, m + 1, r, u, v, val);
        tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
    }

    Node luu;

    Node get(int id, int l, int r, int u, int v) {
        fix(id, l, r);
        if (l > v || u > r) return luu;
        if (l >= u && v >= r) return tree[id];
        int m = l + r >> 1;
        return merge(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }

    void solve(void) {
        build(1, 1, n);
        luu.l = 1; luu.r = 0; luu.ans = -1;
        For(qu, 1, q, 1) {
            int type = que[qu].type;
            if (type == 1) {
                int l = que[qu].l, r = que[qu].r, val = que[qu].val;
                update(1, 1, n, l, r, val);
            }
            else {
                int l = que[qu].l, r = que[qu].r;
                cout << get(1, 1, n, l, r).ans << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q >> k;
    For(i, 1, n, 1) cin >> a[i];
    For(i, 1, q, 1) {
        cin >> que[i].type;
        if (que[i].type == 1) cin >> que[i].l >> que[i].r >> que[i].val;
        else cin >> que[i].l >> que[i].r;
    }

    if (sub1::check_dk()) sub1::solve();
    else if (sub2::check_dk()) sub2::solve();
    else sub3::solve();

    return 0;
}
