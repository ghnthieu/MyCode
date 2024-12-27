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
const int N = (int) 3e5 + 7;

int tcase, n, m, k, defau[N];

struct Edge {
    int u, v, w;
} edge[N];

struct Dsu {
    vec(int) par;

    void init(int n) {
        par.resize(n + 5, 0);
        For(i, 1, n, 1) par[i] = i;
    }

    int find_par(int u) {
        if (u == par[u]) return u;
        return par[u] = find_par(par[u]);
    }

    bool add_par(int u, int v) {
        u = find_par(u); v = find_par(v);
        if (u == v) return false;
        par[v] = u; return true;
    }
} dsu;

bool cmp(Edge x, Edge y) {
    return (x.w < y.w);
}

namespace sub1_3 {

    bool check_dk(void) {
        return (n <= 6 && m <= 20);
    }

    int colr[N];
    bool vit[N];
    vec(int) inp[N];
    ll ans = LLONG_MAX;

    void dfs(int u) {
        vit[u] = true;
        for (int v : inp[u]) if (!vit[v])
            dfs(v);
    }

    void backtrack(vec(int) luu) {
        if (luu.size() == n) {
            Rep(i, luu.size()) if (defau[i + 1] != 0 && defau[i + 1] != luu[i]) return;
            For(i, 1, n, 1) {
                if (defau[i] != 0) colr[i] = defau[i];
                else colr[i] = luu[i - 1];
            }
            dsu.init(n); For(i, 1, n, 1) inp[i].clear();
            ll sum = 0;
            For(i, 1, m, 1) {
                if (!dsu.add_par(colr[edge[i].u], colr[edge[i].v]))
                    continue;
                sum += edge[i].w;
                inp[colr[edge[i].u]].pub(colr[edge[i].v]);
                inp[colr[edge[i].v]].pub(colr[edge[i].u]);
            }
            memset(vit, false, (n + 1) * sizeof(bool));
            dfs(colr[1]);
            bool ok = true;
            For(i, 1, k, 1) if (!vit[i]) {
                ok = false;
                break;
            }
            if (ok) minimize(ans, sum);
            return;
        }

        For(i, 1, k, 1) {
            luu.pub(i);
            backtrack(luu);
            luu.pb();
        }
    }

    void solve(void) {
        sort(edge + 1, edge + m + 1, cmp);
        vec(int) tmp; ans = LLONG_MAX;;
        backtrack(tmp);
        cout << ((ans == LLONG_MAX) ? (-1) : ans) << '\n';
    }
}

namespace subfull {

    ll res[N];

    void solve(void) {
        dsu.init(n);
        memset(res, 0, sizeof(res));
        For(i, 1, n, 1) {
            if (defau[i] == 0) continue;
            if (res[defau[i]] != 0) dsu.add_par(res[defau[i]], i);
            res[defau[i]] = i;
        }
        sort(edge + 1, edge + m + 1, cmp);
        ll ans = LLONG_MAX, cnt = 0, sum = 0;
        if (cnt >= k - 1) minimize(ans, sum);
        For(i, 1, m, 1) if (dsu.add_par(edge[i].u, edge[i].v)) {
            sum += edge[i].w; ++cnt;
            if (cnt >= k - 1) minimize(ans, sum);
        }

        cout << ((ans == LLONG_MAX) ? (-1) : ans) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("GRAPHZIP.INP", "r", stdin);
    freopen("GRAPHZIP.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> tcase;
    Rep(test_case, tcase) {
        cin >> n >> m >> k;
        For(i, 1, n, 1) cin >> defau[i];
        For(i, 1, m, 1) {
            int x, y, w; cin >> x >> y >> w;
            edge[i] = {x, y, w};
        }

        if (sub1_3::check_dk()) sub1_3::solve();
        else subfull::solve();
    }

    return 0;
}
