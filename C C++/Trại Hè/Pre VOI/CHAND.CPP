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

int n, q, col[N];
vec(int) inp[N];
ii(int, int) que[N], edge[N];

namespace sub1 {

    bool check_dk(void) {
        bool check1 = true, check2 = true;

        For(i, 1, n, 1) if (col[i] != 1 && col[i] != 2) {
            check1 = false;
            break;
        }

        int cnt_1 = 0, cnt_2 = 0;
        For(i, 1, n, 1) {
            if (inp[i].size() == 1) ++cnt_1;
            else if (inp[i].size() == 2) ++cnt_2;
            else { check2 = false; break; }
        }

        return (n <= 10 && q <= 10 && check1 && check2 && cnt_1 == 2 && cnt_2 == n - 2);
    }

    int tcol[N], trace[N];
    bool vit[N];
    vec(int) ddi[N];
    vec(vec(int)) res;


    void dfs(int u) {
        vit[u] = true;
        for (int v : inp[u]) if (!vit[v]) {
            trace[v] = u;
            dfs(v);
        }
    }

    void sinh_th(vec(int) luu) {
        if (luu.size() == n) {
            res.pub(luu);
            return;
        }

        For(i, 1, 2, 1) {
            luu.pub(i);
            sinh_th(luu);
            luu.pb();
        }
    }

    void solve(void) {
        vec(int) tmp; sinh_th(tmp);
        For(k, 1, q, 1) {
            memset(vit, false, (n + 1) * sizeof(bool));
            int l = que[k].fi, r = que[k].se; if (l > r) swap(l, r);
            vec(int) luu; luu.pub(r);
            if (l == r) {
                ddi[k] = luu;
                continue;
            }
            dfs(l); int tl = l, tr = r;
            do {
                luu.pub(trace[tr]);
                tr = trace[tr];
            } while (tr != tl);
            reverse(all(luu)); ddi[k] = luu;
        }

        For(k, 1, q, 1) {
            int ans = INT_MAX;
            Rep(i, res.size()) {
                Rep(j, res[i].size()) tcol[j + 1] = res[i][j];
                int cnt = 0;
                For(j, 1, n, 1) if (col[j] != tcol[j])
                    ++cnt;

                bool check = true;
                Ford(kd, k, 1, 1) {
                    if (!check) break;
                    vec(int) light_a, light_b;
                    for (int x : ddi[kd]) light_a.pub(tcol[x]);
                    Ford(j, ddi[kd].size() - 1, 0, 1) light_b.pub(tcol[ddi[kd][j]]);
                    Rep(i, light_a.size()) if (light_a[i] != light_b[i]) {
                        check = false;
                        break;
                    }
                }

                if (check) minimize(ans, cnt);
            }
            cout << ans << '\n';
        }
    }
}

namespace sub2 {

    bool check_dk(void) {
        return (n <= 2e2 && q <= 2e2);
    }

    int par[N], tpar[N], high[N];
    bool vit[N];
    vec(int) tinp[N];

    void dfs(int u, int par) {
        for (int v : inp[u]) if (v != par) {
            tpar[v] = u;
            high[v] = high[u] + 1;
            dfs(v, u);
        }
    }

    void init(void) {
        For(i, 1, n, 1) {
            par[i] = i;
            tinp[i].pub(col[i]);
        }
    }

    int find_par(int u) {
        if (par[u] == u) return u;
        return (par[u] = find_par(par[u]));
    }

    bool add_par(int u, int v) {
        u = find_par(u); v = find_par(v);
        if (u == v) return false;
        if (tinp[u].size() < tinp[v].size()) swap(u, v);
        par[v] = u;
        for (int x : tinp[v]) tinp[u].pub(x);
        tinp[v].clear(); return true;
    }

    void solve(void) {
        init();
        dfs(1, -1);
        For(k, 1, q, 1) {
            int u = que[k].fi, v = que[k].se;
            if (high[u] < high[v]) swap(u, v);
            vec(int) luu_l, luu_r;
            while (high[u] != high[v]) {
                luu_l.pub(u);
                u = tpar[u];
            }
            while (u != v) {
                luu_l.pub(u);
                luu_r.pub(v);
                u = tpar[u]; v = tpar[v];
            }
            luu_l.pub(u); reverse(all(luu_r));
            for (int v : luu_r) luu_l.pub(v);
            int l = 0, r = luu_l.size() - 1;
            while (l < r) {
                add_par(luu_l[l], luu_l[r]);
                ++l; --r;
            }
            memset(vit, false, (n + 1) * sizeof(bool));

            ll ans = 0;
            For(i, 1, n, 1) {
                int u = find_par(i);
                if (vit[u]) continue;
                vit[u] = true;
                sort(all(tinp[u]));
                int m = tinp[u].size(), medi = tinp[u][(m - 1) / 2];
                for (int v : tinp[u]) ans = ans + abs(v - medi);
            }
            cout << ans << '\n';
        }
    }
}

namespace sub3 {
    void solve(void) {

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CHAND.INP", "r", stdin);
    freopen("CHAND.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    For(i, 1, n, 1) cin >> col[i];
    For(i, 1, n - 1, 1) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
        edge[i] = {x, y};
    }
    For(i, 1, q, 1) cin >> que[i].fi >> que[i].se;

    if (sub1::check_dk()) sub1::solve();
    else if (sub2::check_dk()) sub2::solve();
    else sub3::solve();

    return 0;
}
