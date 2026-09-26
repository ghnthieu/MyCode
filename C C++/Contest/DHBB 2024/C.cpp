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

int n, m;
vec(Data) inp;
Dsu dsu;

bool cmp(Data a, Data b) {
    return (a.w > b.w);
}

bool cmpp(Data a, Data b) {
    return (a.w < b.w);
}

vec(Data) not_edge;

void solve(void) {
    dsu.init(n);
    sort(all(inp), cmp);
    for (Data x : inp) {
        if (!dsu.addpar(x.u, x.v)) {
            not_edge.pub(x);
            continue;
        }
    }

    sort(all(not_edge), cmpp);
    ll ans = 0;
    int idx = 0;
    For(i, 1, n, 1) {
        if (dsu.findpar(1) != dsu.findpar(i)) {
            ans += not_edge[idx].w;
            ++idx;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("comnet.inp", "r", stdin);
    //freopen("comnet.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    For(i, 1, m, 1) {
        Data x; cin >> x.u >> x.v >> x.w; x.idx = i;
        inp.pub(x);
    }

    solve();

    return 0;
}
