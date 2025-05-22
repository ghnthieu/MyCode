#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb pop_back
#define pub push_back
#define __Trung_Hieu___ signed main()
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const ll INF = (ll) 1e18 + 7ll;
const int N = (int) 5e3 + 7;
const int M = (int) 17;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, par[N][M + 1], high[N];
vii(int, int) inp[N], tinp[N];
ll duong[N];
bool vit[N], check[N];

void dfs(int u) {
    vit[u] = true;
    for (ii(int, int) v : inp[u]) if (!vit[v.fi]) {
        duong[v.fi] = duong[u] + v.se;
        dfs(v.fi);
    }
}

void dfs_lca(int u) {
    for (ii(int, int) v : inp[u]) if (v.fi != par[u][0]) {
        par[v.fi][0] = u;
        high[v.fi] = high[u] + 1;
        dfs_lca(v.fi);
    }
}

int lca(int u, int v) {
    if (high[v] > high[u]) return lca(v, u);
    Ford(i, M, 0, 1) if (high[par[u][i]] >= high[v])
        u = par[u][i];
    if (u == v) return u;
    Ford(i, M, 0, 1) if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

ll get_sum(int u, int v) {
    return duong[u] + duong[v] - (duong[lca(u, v)] * 2);
}

void FordBellman(int s) {
    memset(duong, 0x3f, (n + 1) * sizeof(ll)); duong[s] = 0;
    memset(check, false, (n + 1) * sizeof(bool)); check[s] = true;
    queue <int> qu; qu.push(s);

    while (!qu.empty()) {
        int u = qu.front(); qu.pop(); check[u] = false;
        for (ii(int, int) v : tinp[u]) if (minimize(duong[v.fi], duong[u] + v.se) && !check[v.fi]) {
            qu.push(v.fi);
            check[v.fi] = true;
        }
    }

    For(i, 1, n, 1) cout << ((duong[i] >= INF) ? (-1) : duong[i]) << " ";
}

void dijkstra(int s) {
    memset(duong, 0x3f, (n + 1) * sizeof(ll)); duong[s] = 0;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq; pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se]) continue;
        for (ii(int, int) v : tinp[u.se]) if (minimize(duong[v.fi], duong[u.se] + v.se))
            pq.push({duong[v.fi], v.fi});
    }
    For(i, 1, n, 1) cout << duong[i] << " ";
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".INP", "r", stdin);
    //freopen(".OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    Rep(edge, n - 1) {
        int u, v, w; cin >> u >> v >> w;
        inp[u].pub({v, w});
        inp[v].pub({u, w});
    }

    dfs(1);
    dfs_lca(1);
    For(j, 1, M, 1) For(i, 1, n, 1)
        par[i][j] = par[par[i][j - 1]][j - 1];
    high[0] = -1;

    For(u, 1, n, 1) For(v, u + 1, n, 1)
        tinp[u].pub({v, get_sum(u, v)});

    dijkstra(1);

    return 0;
}
