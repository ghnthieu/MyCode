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
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

ll tcase, n, k, last, a[N], tree_sum[4 * N], tree_cnt[4 * N];
vec(int) nen;

void update(int id, int l, int r, int pos, ll val) {
    if (l > pos || pos > r) return;
    if (l == r) {
        ++tree_cnt[id];
        tree_sum[id] += val;
        return;
    }
    int m = l + r >> 1;
    update(id << 1, l, m, pos, val);
    update(id << 1 | 1, m + 1, r, pos, val);
    tree_cnt[id] = tree_cnt[id << 1] + tree_cnt[id << 1 | 1];
    tree_sum[id] = tree_sum[id << 1] + tree_sum[id << 1 | 1];
}

int get_cnt(int id, int l, int r, int u, int v) {
    if (l > v || u > r) return 0;
    if (l >= u && v >= r) return tree_cnt[id];
    int m = l + r >> 1;
    return get_cnt(id << 1, l, m, u, v) + get_cnt(id << 1 | 1, m + 1, r, u, v);
}

ll get_sum(int id, int l, int r, int u, int v) {
    if (l > v || u > r) return 0;
    if (l >= u && v >= r) return tree_sum[id];
    int m = l + r >> 1;
    return get_sum(id << 1, l, m, u, v) + get_sum(id << 1 | 1, m + 1, r, u, v);
}

bool check(int l, int r, ll m) {
    int pos = upper_bound(all(nen), m - 1) - nen.begin();
    ll res = 1ll * m * get_cnt(1, 1, nen.size() - 1, pos, nen.size() - 1);
    res += 1ll * get_sum(1, 1, nen.size() - 1, 1, pos - 1);
    return ((res >= 1ll * m * k) ? true : false);
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

    cin >> tcase;

    Rep(test_case, tcase) {
        cin >> n >> k >> last;

        nen.clear();
        memset(tree_cnt, 0, sizeof(tree_cnt));
        memset(tree_sum, 0, sizeof(tree_sum));

        For(i, 1, n, 1) {
            cin >> a[i];
            nen.pub(a[i]);
        }
        nen.pub(-1);
        sort(all(nen));
        nen.resize(unique(all(nen)) - nen.begin());

        For(i, 1, last, 1) {
            int pos = upper_bound(all(nen), a[i]) - nen.begin() - 1;
            update(1, 1, nen.size() - 1, pos, a[i]);
        }
        For(i, last + 1, n, 1) {
            ll l = 0, r = 1e15, ans = 0;
            int pos = upper_bound(all(nen), a[i]) - nen.begin() - 1;
            update(1, 1, nen.size() - 1, pos, a[i]);
            while (l <= r) {
                ll m = l + r >> 1;
                if (check(1, i, m)) {
                    maximize(ans, m);
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            cout << ans << '\n';
        }
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
