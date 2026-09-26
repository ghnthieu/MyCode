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
const int N = (int) 1e6 + 7;
const int M = (int) 19;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, k, q;
bool spec[N];
vii(int, int) inp[N];
ll duong[N];

void dijkstra(void) {
    memset(duong, 0x3f, (n + 1) * sizeof(ll));
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq;
    For(i, 1, n, 1) if (spec[i]) {
        duong[i] = 0;
        pq.push({0, i});
    }
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se]) continue;
        for (ii(int, int) v : inp[u.se]) if (minimize(duong[v.fi], duong[u.se] + v.se))
            pq.push({duong[v.fi], v.fi});
    }

    //For(i, 1, n, 1) cout << duong[i] << " ";
}

struct Dsu {
    vec(int) par;

    void init(int n) {
        par.resize(n + 5, 0);
        For(i, 1, n, 1) par[i] = i;
    }

    int findpar(int u) {
        if (par[u] == u) return u;
        return (par[u] = findpar(par[u]));
    }

    bool addpar(int u, int v) {
        u = findpar(u); v = findpar(v);
        if (u == v) return false;
        par[v] = u; return true;
    }
} dsu;

struct Data {
    int u, v, w;
}; vec(Data) edge;

bool cmp(Data x, Data y) {
    return (x.w > y.w);
}

int par[N][M + 1], val[N][M + 1], high[N];

void dfs_lca(int u) {
    for (ii(int, int) v : inp[u]) if (v.fi != par[u][0]) {
        par[v.fi][0] = u;
        val[v.fi][0] = v.se;
        high[v.fi] = high[u] + 1;
        dfs_lca(v.fi);
    }
}

int lca(int u, int v) {
    if (high[v] > high[u]) swap(v, u);
    int res = INT_MAX;
    Ford (i, M, 0, 1) if (high[par[u][i]] >= high[v]) {
        minimize(res, val[u][i]);
        u = par[u][i];
    }
    if (u == v) return res;
    Ford(i, M, 0, 1) if (par[u][i] != par[v][i]) {
        minimize(res, val[u][i]);
        minimize(res, val[v][i]);
        u = par[u][i];
        v = par[v][i];
    }
    minimize(res, val[u][0]);
    minimize(res, val[v][0]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("WALK.inp", "r", stdin);
    freopen("WALK.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> k >> q;
    For(i, 1, m, 1) {
        int x, y, w; cin >> x >> y >> w;
        inp[x].pub({y, w});
        inp[y].pub({x, w});
        Data t; t.u = x; t.v = y; t.w = w;
        edge.pub(t);
    }
    For(i, 1, k, 1) {
        int pos; cin >> pos;
        spec[pos] = true;
    }

    dijkstra();

    Rep(i, m) {
        Data t; t.u = edge[i].u, t.v = edge[i].v, t.w = min(duong[edge[i].u], duong[edge[i].v]);
        edge[i] = t;
    }
    For(i, 1, n, 1) inp[i].clear();

    dsu.init(n);
    sort(all(edge), cmp);
    for (Data x : edge) {
        if (!dsu.addpar(x.u, x.v)) continue;
        inp[x.u].pub({x.v, x.w});
        inp[x.v].pub({x.u, x.w});
    }

    dfs_lca(1);
    For(j, 1, M, 1) For(i, 1, n, 1) {
        par[i][j] = par[par[i][j - 1]][j - 1];
        val[i][j] = min(val[i][j - 1], val[par[i][j - 1]][j - 1]);
    }
    high[0] = -1;

    Rep(query, q) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << '\n';
    }

    return 0;
}
