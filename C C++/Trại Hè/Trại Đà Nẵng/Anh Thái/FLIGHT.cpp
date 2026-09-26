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

int n, m, cnt[N];
bool vit[N];
vec(int) inp[N];

struct Data {
    int u, v, w;
} edge[N];

struct Dsu {
    vec(int) par;

    void init(int n) {
        par.resize(n + 5, 0);
        For(i, 1, n, 1) par[i] = i;
    }

    int find_par(int u) {
        if (par[u] == u) return u;
        return (par[u] = find_par(par[u]));
    }

    bool add_par(int u, int v) {
        u = find_par(u); v = find_par(v);
        if (u == v) return false;
        par[v] = u; return true;
    }
} dsu;

void dfs(int u) {
    vit[u] = true;
    for (int v : inp[u]) {
        if (!vit[v]) {
            cnt[v] = 1 - cnt[u];
            dfs(v);
        }
        else if (cnt[v] == cnt[u]) {
            cout << -1;
            exit(0);
        }
    }
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

    cin >> n >> m;
    dsu.init(m);
    For(i, 1, n, 1) {
        cin >> edge[i].w >> edge[i].u >> edge[i].v;
        if (edge[i].w == 0) dsu.add_par(edge[i].u, edge[i].v);
    }
    For(i, 1, n, 1) {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if (w == 1) {
            if (u == v) continue;
            inp[dsu.find_par(u)].pub(dsu.find_par(v));
            inp[dsu.find_par(v)].pub(dsu.find_par(u));
            if (dsu.find_par(u) == dsu.find_par(v)) {
                cout << -1;
                return 0;
            }
        }
    }
    For(i, 1, n, 1) if (edge[i].w == 1) {
        int u = edge[i].u, v = edge[i].v;
        if (u == v && !vit[u]) {
            cnt[u] = 1;
            dfs(u);
        }
    }
    For(i, 1, m, 1) if (dsu.find_par(i) == i && !vit[i]) {
        cnt[i] = 1;
        dfs(i);
    }
    For(i, 1, m, 1) if (dsu.find_par(i) != i)
        cnt[i] = cnt[dsu.find_par(i)];

    int cntt = 0;
    For(i, 1, m, 1) cntt += cnt[i];
    cout << cntt << '\n';
    For(i, 1, m, 1) if (cnt[i] == 1)
        cout << i << " ";

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
