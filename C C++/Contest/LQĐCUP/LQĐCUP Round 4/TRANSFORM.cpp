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
const int N = (int) 2e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q, a[N];

struct Data {
    int type, l, r;
} que[N];

void sub1(void) {
    For(i, 1, q, 1) {
        int type = que[i].type;
        if (type == 1) {
            int pos = que[i].l, val = que[i].r;
            a[pos] = val;
        }
        else {
            int l = que[i].l, r = que[i].r;
            int Mx = INT_MIN, Mn = INT_MAX;
            For(i, l, r, 1) {
                maximize(Mx, a[i]);
                minimize(Mn, a[i]);
            }

            int ans_mn = INT_MAX;
            For(i, l, r, 1) {
                int mx = INT_MIN, mn = INT_MAX;
                For(j, i, r, 1) {
                    maximize(mx, a[j]);
                    minimize(mn, a[j]);
                    if (mx == Mx && mn == Mn)
                        minimize(ans_mn, j - i + 1);
                }
            }
            int ans_pb = 0;
            For(i, l, r, 1) {
                int mx = INT_MIN, mn = INT_MAX;
                For(j, i, r, 1) {
                    maximize(mx, a[j]);
                    minimize(mn, a[j]);
                    if (mx == Mx && mn == Mn && j - i + 1 == ans_mn)
                        ++ans_pb;
                }
            }
            cout << ans_mn << " " << ans_pb << '\n';
        }
    }
}

map <int, ii(int, int)> luu;

void sub2(void) {
    int last = 1, r = 1;
    while (r <= n) {
        while (a[r] == a[last] && r <= n) ++r;
        luu[a[last]] = {last, r - 1};
        last = r;
    }

    For(i, 1, q, 1) {
        int l = que[i].l, r = que[i].r;
        if (l == r)
            cout << 1 << " " << 1 << '\n';
        else if (a[l] == a[r])
            cout << 1 << " " << min(luu[a[l]].se, r) - max(luu[a[l]].fi, l) + 1 << '\n';
        else
            cout << luu[a[r]].fi - luu[a[l]].se + 1 << " " << 1 << '\n';
    }

    //for (auto x : luu) cout << x.fi << " " << x.se.fi << " " << x.se.se << '\n';
}

int tree_mx[4 * N], tree_mn[4 * N];

void build(int id, int l, int r) {
    if (l == r) {
        tree_mx[id] = a[l];
        tree_mn[id] = a[l];
    }
    else {
        int mid = l + r >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        tree_mx[id] = max(tree_mx[id << 1], tree_mx[id << 1 | 1]);
        tree_mn[id] = min(tree_mn[id << 1], tree_mn[id << 1 | 1]);
    }
}

int get_mx(int id, int l, int r, int u, int v) {
    if (u > r || l > v) return 0;
    if (u <= l && r <= v) return tree_mx[id];
    int m = l + r >> 1;
    return max(get_mx(id << 1, l, m, u, v), get_mx(id << 1 | 1, m + 1, r, u, v));
}

int get_mn(int id, int l, int r, int u, int v) {
    if (u > r || l > v) return MOD;
    if (u <= l && r <= v) return tree_mn[id];
    int m = l + r >> 1;
    return min(get_mn(id << 1, l, m, u, v), get_mn(id << 1 | 1, m + 1, r, u, v));
}

void sub3(void) {
    map <int, int> idx;
    For(i, 1, n, 1) idx[a[i]] = i;
    build(1, 1, n);
    For(i, 1, q, 1) {
        int l = que[i].l, r = que[i].r;
        int mx = get_mx(1, 1, n, l, r), mn = get_mn(1, 1, n, l, r);
        int idx_mx = idx[mx], idx_mn = idx[mn];
        if (idx_mx < idx_mn) swap(idx_mx, idx_mn);
        //cout << mx << " " << mn << '\n';
        cout << idx_mx - idx_mn + 1 << " " << 1 << '\n';
    }
}

void sub4(void) {
    For(i, 1, q, 1) {
        int type = que[i].type;
        if (type == 1) {
            int pos = que[i].l, val = que[i].r;
            a[pos] = val;
        }
        else {
            int l = que[i].l, r = que[i].r;
            int mx = INT_MIN, mn = INT_MAX;
            For(i, l, r, 1) {
                maximize(mx, a[i]);
                minimize(mn, a[i]);
            }
            int cnt_mx = 0, cnt_mn = 0, ans_mn = INT_MAX, ans_pb = 0;
            int tr = l - 1, tl = l;
            while (tl <= r) {
                while (tr + 1 <= r && (cnt_mn == 0 || cnt_mx == 0)) {
                    if (a[tr + 1] == mx) ++cnt_mx;
                    if (a[tr + 1] == mn) ++cnt_mn;
                    ++tr;
                }
                if (cnt_mn != 0 && cnt_mx != 0) {
                    if (ans_mn == tr - tl + 1)
                        ++ans_pb;
                    else if (ans_mn > tr - tl + 1) {
                        ans_pb = 1;
                        ans_mn = tr - tl + 1;
                    }
                }
                if (a[tl] == mx) --cnt_mx;
                if (a[tl] == mn) --cnt_mn;
                ++tl;
            }
            cout << ans_mn << " " << ans_pb << '\n';
        }
    }
}

struct node {

    int mxl, mxr, mnl, mnr, best, cnt;

    node (int a, int b, int c, int d, int e, int f) {
        best = a; cnt = b;
        mxl = c; mxr = d;
        mnl = e; mnr = f;
    }

    node (int val) {
        best = 1; cnt = 1;
        mxl = val; mxr = val;
        mnl = val; mnr = val;
    }

    node (void) {
        best = -1;
    }

} tree[4 * N];

node mer(node l, node r) {
    if (l.best < 0) return r;
    if (r.best < 0) return l;

    int best, cnt, mxl, mxr, mnl, mnr;
    int mx = max(a[l.mxl], a[r.mxr]),
        mn = min(a[l.mnl], a[r.mnr]);

    if (a[l.mnl] == mn) mnl = l.mnl;
    else mnl = r.mnl;

    if (a[l.mxl] == mx) mxl = l.mxl;
    else mxl = r.mxl;

    if (a[r.mnr] == mn) mnr = r.mnr;
    else mnr = l.mnr;

    if (a[r.mxr] == mx) mxr = r.mxr;
    else mxr = l.mxr;

    best = INT_MAX;

    if (a[l.mxl] == mx) {
        if (a[l.mnl] == mn) minimize(best, l.best);
        if (a[r.mnr] == mn) minimize(best, r.mnl - l.mxr + 1);
    }

    if (a[r.mxr] == mx) {
        if (a[r.mnr] == mn) minimize(best, r.best);
        if (a[l.mnl] == mn) minimize(best, r.mxl - l.mnr + 1);
    }

    cnt = 0;
    if (a[l.mnr] == mn && a[r.mxl] == mx && best == r.mxl - l.mnr + 1) ++cnt;
    if (a[l.mxr] == mx && a[r.mnl] == mn && best == r.mnl - l.mxr + 1) ++cnt;
    if (a[l.mnl] == mn && a[l.mxl] == mx && best == l.best) cnt += l.cnt;
    if (a[r.mnr] == mn && a[r.mxr] == mx && best == r.best) cnt += r.cnt;

    return node(best, cnt, mxl, mxr, mnl, mnr);
}

void buildd(int id, int l, int r) {
    if (l == r) {
        tree[id] = node(l);
    }
    else {
        int m = l + r >> 1;
        buildd(id << 1, l, m);
        buildd(id << 1 | 1, m + 1, r);
        tree[id] = mer(tree[id << 1], tree[id << 1 | 1]);
    }
}

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        a[pos] = val;
        tree[id] = node(pos);
    }
    else {
        int m = l + r >> 1;
        if (pos <= m)
            update(id << 1, l, m, pos, val);
        else
            update(id << 1 | 1, m + 1, r, pos, val);
        tree[id] = mer(tree[id << 1], tree[id << 1 | 1]);
    }
}

node get(int id, int l, int r, int u, int v) {
    if (l > v || u > r) return node();
    if (l >= u && v >= r) return tree[id];
    int m = l + r >> 1;
    return mer(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
}

void sub5(void) {
    buildd(1, 1, n);
    For(i, 1, q, 1) {
        int type = que[i].type;
        if (type == 1) {
            int pos = que[i].l, val = que[i].r;
            update(1, 1, n, pos, val);
        }
        else {
            int l = que[i].l, r = que[i].r;
            cout << get(1, 1, n, l, r).best << " " << get(1, 1, n, l, r).cnt << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TRANSFORM.inp", "r", stdin);
    freopen("TRANSFORM.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    bool check_sub2 = true, check_sub3 = true;
    map <int, int> cnt;
    For(i, 1, n, 1) {
        cin >> a[i];
        if (a[i] < a[i - 1]) check_sub2 = false;
        ++cnt[a[i]]; if (cnt[a[i]] > 1) check_sub3 = false;
    }

    For(i, 1, q, 1) {
        cin >> que[i].type >> que[i].l >> que[i].r;
        if (que[i].type == 1) check_sub2 = false;
        if (que[i].type == 1) check_sub3 = false;
    }

    if (n <= 8e2 && q <= 8e2)
        sub1();
    else if (check_sub2)
        sub2();
    else if (check_sub3)
        sub3();
    else if (q <= 4e2)
        sub4();
    else
        sub5();

    return 0;
}
