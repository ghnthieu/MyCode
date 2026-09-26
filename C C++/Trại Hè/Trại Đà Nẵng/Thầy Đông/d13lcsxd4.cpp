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

int n, x, a[N], b[N], tree_mx[4 * N];
map <int, int> idx;
ll tree_cnt[4 * N];

void add(ll &x, ll y) {
    x += y;
    x -= ((x >= MOD) ? MOD : 0);
}

void update(int id, int l, int r, int pos, int val, ll tval) {
    if (l > pos || pos > r) return;
    if (l == r) {
        if (val > tree_mx[id]) {
            tree_mx[id] = val;
            tree_cnt[id] = tval;
        }
        else if (val == tree_mx[id])
            add(tree_cnt[id], tval);
    }
    else {
        int m = l + r >> 1;
        update(id << 1, l, m, pos, val, tval);
        update(id << 1 | 1, m + 1, r, pos, val, tval);
        if (tree_mx[id << 1] > tree_mx[id << 1 | 1]) {
            tree_mx[id] = tree_mx[id << 1];
            tree_cnt[id] = tree_cnt[id << 1];
        }
        else if (tree_mx[id << 1] < tree_mx[id << 1 | 1]) {
            tree_mx[id] = tree_mx[id << 1 | 1];
            tree_cnt[id] = tree_cnt[id << 1 | 1];
        }
        else {
            tree_mx[id] = tree_mx[id << 1];
            tree_cnt[id] = (tree_cnt[id << 1] + tree_cnt[id << 1 | 1]) % MOD;
        }
    }
}

ll get_mx(int id, int l, int r, int u, int v) {
    if (l > v || u > r) return 0;
    if (l >= u && v >= r) return tree_mx[id];
    int m = l + r >> 1;
    return max(get_mx(id << 1, l, m, u, v), get_mx(id << 1 | 1, m + 1, r, u, v));
}

ll get_cnt(int id, int l, int r, int u, int v, ll val) {
    if (l > v || u > r || tree_mx[id] < val) return 0;
    if (l >= u && v >= r) return tree_cnt[id];
    int m = l + r >> 1;
    return (get_cnt(id << 1, l, m, u, v, val) + get_cnt(id << 1 | 1, m + 1, r, u, v, val)) % MOD;
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

    cin >> n >> x;
    For(i, 1, n, 1) { cin >> a[i]; idx[a[i]] = i; }
    For(i, 1, n, 1) cin >> b[i];

    update(1, 0, 1e5, 0, 1, 1);
    For(i, 1, n, 1) {
        viii(int, int, ll) luu;
        For(j, b[i] - x, b[i] + x, 1) {
            if (1 <= j && j <= n) {
                int x = idx[j];
                int len = get_mx(1, 0, 1e5, 0, x - 1);
                ll val = get_cnt(1, 0, 1e5, 0, x - 1, len);
                luu.pub({{len, x}, val});
            }
        }

        for (iii(int, int, ll) y : luu) update(1, 0, 1e5, y.fi.se, y.fi.fi + 1, y.se);
    }
    cout << tree_mx[1] - 1 << " " << tree_cnt[1];

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
