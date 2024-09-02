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
const int M = (int) 1e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q, duong[N], tree[4 * N];
ii(ll, ll) tdo[N];

void build(int id, int l, int r) {
    if (l == r)
        tree[id] = duong[l];
    else {
        int mid = l + r >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
    }
}

int get_max(int id, int l, int r, int u, int v) {
    if (l > v || u > r) return -1;
    if (l >= u && v >= r) return tree[id];
    int m = l + r >> 1;
    return max(get_max(id << 1, l, m, u, v), get_max(id << 1 | 1, m + 1, r, u, v));
}

bool cmp(ii(int, int) a, ii(int, int) b) {
    return (a.fi < b.fi);
}

map <int, int> new_pos;

void sub3(void) {
    For(i, 1, n, 1) {
        int not_need; cin >> not_need;
        cin >> tdo[i].fi;
        tdo[i].se = i;
    }

    sort(tdo + 1, tdo + n + 1, cmp);
    For(i, 1, n - 1, 1) {
        if (tdo[i].fi < 0 && tdo[i + 1].fi < 0)
            duong[i] = abs(tdo[i].fi) - abs(tdo[i + 1].fi);
        else if (tdo[i].fi < 0 && tdo[i + 1].fi >= 0)
            duong[i] = abs(tdo[i].fi) + tdo[i + 1].fi;
        else
            duong[i] = tdo[i + 1].fi - tdo[i].fi;
    }

    For(i, 1, n, 1) new_pos[tdo[i].se] = i;
    build(1, 1, n - 1);
    Rep(query, q) {
        int st, en; cin >> st >> en;
        if (st == en) {
            cout << 0 << '\n';
            continue;
        }
        else {
            if (new_pos[st] > new_pos[en]) swap(st, en);
            cout << get_max(1, 1, n - 1, new_pos[st], new_pos[en] - 1) << '\n';
        }
    }
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
    int u, v; ll w;
};

vec(Data) edge;

bool cmpp(Data x, Data y) {
    return (x.w < y.w);
}

ll tduong[M][M];
vec(int) inp[M];
int high[M], par[M];

void dfs(int u, int pr) {
    for (int v : inp[u]) {
        if (v == pr) continue;
        par[v] = u;
        high[v] = high[u] + 1;
        dfs(v, u);
    }
}

ll get_mx(int u, int v) {
    if (high[u] < high[v]) swap(u, v);

    ll ans = 0;
    while (high[u] > high[v]) {
        int x = u, y = par[u];
        maximize(ans, tduong[x][y]);
        u = par[u];
    }

    while (u != v) {
        int x = u, y = par[u];
        maximize(ans, tduong[x][y]);
        x = v, y = par[v];
        maximize(ans, tduong[x][y]);
        u = par[u];
        v = par[v];
    }
    return ans;
}

void sub12(void) {
    For(i, 1, n, 1) cin >> tdo[i].fi >> tdo[i].se;
    For(i, 1, n, 1) For(j, 1, n, 1) {
        tduong[i][j] = abs(tdo[i].fi - tdo[j].fi) + abs(tdo[i].se - tdo[j].se);
        tduong[j][i] = abs(tdo[i].fi - tdo[j].fi) + abs(tdo[i].se - tdo[j].se);
    }
    For(i, 1, n, 1) For(j, 1, n, 1) {
        Data x; x.u = i; x.v = j; x.w = tduong[i][j];
        edge.pub(x);
    }

    dsu.init(n);
    sort(all(edge), cmpp);
    for (Data x : edge) {
        //cout << x.u << " " << x.v << " " << x.w << '\n';
        if (!dsu.addpar(x.u, x.v)) continue;
        inp[x.u].pub(x.v);
        inp[x.v].pub(x.u);
        //cout << x.u << " " << x.v << '\n';
    }

    high[1] = 1;
    dfs(1, 0);
    Rep(query, q) {
        int st, en; cin >> st >> en;
        cout << get_mx(st, en) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("ELECAR.inp", "r", stdin);
    freopen("ELECAR.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;

    if (n <= 1e3 && q <= 1e3)
        sub12();
    else
        sub3();

    return 0;
}
