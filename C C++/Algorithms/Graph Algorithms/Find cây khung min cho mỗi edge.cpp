#include <bits/stdc++.h>
using namespace std;

#define NAME "mst"
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
#define vec(kdl) vector <kdl>
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1,kdl2>,kdl3>>
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 5e5 + 7;

struct Dsu {
    vec(int) par;
    
    void init(int n) {
        par.resize(n + 5, 0);
        for (int i=1; i<=n; ++i)
            par[i] = i;
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
};

struct Data {
    int u, v, w, idx;
};

struct Tdata {
    int par; ll mx = LLONG_MIN;
};

int sub, n, m, high[N];
ll mxw = 0, luu[N];
vec(Data) inp;
vii(int, int) tmp[N];
Dsu dsu;
Tdata upd[N][21];

void dfs(int u, int par) {
    upd[u][0].par = par;
    for (ii(int, int) v : tmp[u]) {
        if (v.fi == par) continue;
        high[v.fi] = high[u] + 1;
        upd[v.fi][0].mx = v.se;
        dfs(v.fi, u);
    }
}

ll lca(int u, int v) {
    ll tres = LLONG_MIN;
    if (high[u] < high[v]) swap(u, v);
    int ttmp = high[u] - high[v];
    for (int i=0; i<=20; ++i) {
        if (bit(ttmp, i)) {
            maximize(tres, upd[u][i].mx);
            u = upd[u][i].par;
        }
    }

    if (u == v) return tres;

    for (int i=20; i>=0; --i) {
        if (upd[u][i].par != upd[v][i].par) {
            maximize(tres, max(upd[u][i].mx, upd[v][i].mx));
            u = upd[u][i].par ; v = upd[v][i].par;
        }
    }
    maximize(tres, max(upd[u][0].mx, upd[v][0].mx));
    return tres;
}

void buildlca(void) {
    dfs(1, 1);
    for (int i=1; i<=20; ++i) {
        for (int j=1; j<=n; ++j) {
            upd[j][i].par = upd[upd[j][i - 1].par][i - 1].par;
            upd[j][i].mx = max(upd[j][i - 1].mx, upd[upd[j][i - 1].par][i - 1].mx);
        }
    }
}

bool cmp(Data a, Data b) {
    return (a.w < b.w);
}

void builddsu(void) {
    dsu.init(n);
    sort(all(inp), cmp);
    for (Data x : inp) {
        if (!dsu.addpar(x.u, x.v)) continue;
        tmp[x.u].pub({x.v, x.w});
        tmp[x.v].pub({x.u, x.w});
        luu[x.idx] = -1;
        mxw += x.w;
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> sub >> n >> m;
    for (int i=1; i<=m; ++i) {
        Data x; cin >> x.u >> x.v >> x.w; x.idx = i;
        inp.pub(x);
    }

    builddsu();
    buildlca();

    for (Data x : inp) {
        if (luu[x.idx] == -1)
            luu[x.idx] = mxw;
        else
            luu[x.idx] = mxw - lca(x.u, x.v) + x.w;
    }

    for (int i=1; i<=m; ++i)
        cout << luu[i] << '\n';

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
