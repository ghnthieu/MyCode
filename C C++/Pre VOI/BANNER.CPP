#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pub push_back
#define pb pop_back
#define mask(i) (1ll << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n  = (n); i < _n; ++i)
template <typename T1, typename T2> bool maximize(T1 &x, T2 y) { if (x < y) { x = y; return true; } return false; }
template <typename T1, typename T2> bool minimize(T1 &x, T2 y) { if (x > y) { x = y; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 5e4 + 7;

int len, q;
string s;
ii(int, int) que[N];

void add(ll &x, ll y) {
    x += y;
    x -= ((x >= MOD) ? MOD : 0);
}

namespace sub1 {
    bool check(void) {
        return (len <= 2e1 && q <= 2e1);
    }

    void solve(void) {
        For(i, 1, q, 1) {
            int l = que[i].fi, r = que[i].se;
            ll ans = 0;
            For(i1, l, r, 1) if (s[i1] == 'H') For(i2, i1 + 1, r, 1) if (s[i2] == 'S') For(i3, i2 + 1, r, 1) if (s[i3] == 'G')
            For(i4, i3 + 1, r, 1) if (s[i4] == '2') For(i5, i4 + 1, r, 1) if (s[i5] == '5')
                add(ans, 1ll);
            cout << ans << '\n';
        }
    }
}

int change(char ch) {
    if (ch == 'H') return 1;
    if (ch == 'S') return 2;
    if (ch == 'G') return 3;
    if (ch == '2') return 4;
    if (ch == '5') return 5;
}

namespace sub2 {
    bool check(void) {
        return (len <= 1e3 && q <= 1e3);
    }

    ll dp[N][7];

    ll calc(string st) {
        memset(dp, 0, sizeof(dp));

        int leng = st.length();
        dp[0][0] = 1;
        For(i, 1, leng, 1) {
            int tmp = change(st[i - 1]);
            Rep(j, 6) add(dp[i][j], dp[i - 1][j]);
            add(dp[i][tmp], dp[i - 1][tmp - 1]);
        }
        return dp[leng][5];
    }

    void solve(void) {
        For(i, 1, q, 1) {
            int l = que[i].fi, r = que[i].se;
            string tmp = "";
            For(j, l, r, 1) tmp += s[j];
            cout << calc(tmp) << '\n';
        }
    }
}

namespace sub3 {
    struct Node {
        ll dp[7][7];

        Node (void) {
            memset(dp, 0, sizeof(dp));
        }
    };

    Node tree[4 * N];

    Node tcalc(Node a, Node b) {
        Node res = Node();
        For(i, 1, 5, 1) For(j, i, 5, 1) {
            add(res.dp[i][j], a.dp[i][j]);
            add(res.dp[i][j], b.dp[i][j]);
            For(k, i, j - 1, 1) add(res.dp[i][j], a.dp[i][k] * 1ll * b.dp[k + 1][j] % MOD);
        }
        return res;
    }

    void build(int id, int l, int r) {
        if (l == r) {
            int tmp = change(s[l]);
            tree[id].dp[tmp][tmp] = 1;
        }
        else {
            int m = l + r >> 1;
            build(id << 1, l, m);
            build(id << 1 | 1, m + 1, r);
            tree[id] = tcalc(tree[id << 1], tree[id << 1 | 1]);
        }
    }

    Node get(int id, int l, int r, int u, int v) {
        if (l > v || u > r) return Node();
        if (l >= u && v >= r) return tree[id];
        int m = l + r >> 1;
        return tcalc(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }

    void solve(void) {
        build(1, 1, len);
        For(i, 1, q, 1) {
            int l = que[i].fi, r = que[i].se;
            Node ans = get(1, 1, len, l, r);
            cout << ans.dp[1][5] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("BANNER.INP", "r", stdin);
    freopen("BANNER.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);

    cin >> len >> q >> s;
    s = "h" + s;
    For(i, 1, q, 1) cin >> que[i].fi >> que[i].se;

    if (sub1::check()) sub1::solve();
    else if (sub2::check()) sub2::solve();
    else sub3::solve();

    return 0;
}
