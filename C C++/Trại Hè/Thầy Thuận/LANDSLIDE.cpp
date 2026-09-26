#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fi first
#define se second
#define bk back
#define fr front
#define pb pop_back
#define pf pop_front
#define pub push_back
#define puf push_front
#define sz(x) (ll)(x.size())
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define biti(i, x) ((1ll << (i)) & (x))
#define boolbit(i, x) (biti(i, x) != 0)
#define optm(v) v.resize(unique(all(v)) - v.begin())
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define vec(kdl) vector <kdl>
#define ii pair<int,int>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1, kdl2>, kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1, kdl2>, kdl3>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define forr(i, l, r) for (int i = l; i <= r; i++)
#define fodd(i, l, r) for (int i = l; i >= r; i--)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int mod = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const ll oo = 1e18 + 11;

int n, S, Q, H;
vector <ii> ke[500011];
ii q[500011];
int a[500011], mark[500011];
struct edge 
{
    int u, v, w;
} e[500011];
struct IT 
{
    ll lazy[500011*4], tree[500011*4];
    void push(int id) {
        tree[id << 1] += lazy[id];
        tree[id << 1 | 1] += lazy[id];
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        lazy[id] = 0;
    }
    void upd(int id, int l, int r, int u, int v, ll val) 
	{
        if (l > v || r < u) return;
        if (l >= u && r <= v) 
		{
            tree[id] += val;
            lazy[id] += val;
            return;
        }
        push(id);
        int mid = l + r >> 1;
        upd(id << 1, l, mid, u, v, val);
        upd(id << 1 | 1, mid + 1, r, u, v, val);
        tree[id] = min(tree[id << 1], tree[id << 1 | 1]);
    }
    ll get(int id, int l, int r, int u, int v) 
	{
        if (l > v || r < u) return oo;
        if (l >= u && r <= v) return tree[id];
        push(id);
        int mid = l + r >> 1;
        return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }

    void upd(int l, int r, ll val) {upd(1, 1, n, l, r, val);}
    ll get(int l, int r) {return get(1, 1, n, l, r);}
} it;
ll dist[500011];
int timer, tin[500011], tout[500011];
int idver[500011], ide[500011];
int par[500011];
vector <int> small[500011], big[500011];
ll ans[500011];
bool isin(int u, int v) 
{
    return tin[u] >= tin[v] && tout[u] <= tout[v];
}
void dfs(int u, int p) 
{
    tin[u] = ++timer;
    for (ii x : ke[u]) if (x.fi != p) 
	{
        int v = x.fi, i = x.se;
        idver[v] = i;
        ide[i] = v;
        par[v] = u;
        dist[v] = dist[u] + e[i].w;
        dfs(v, u);
    }
    tout[u] = timer;
}
void dfssmall(int u, int p) 
{
    for (ii x : ke[u]) if (x.fi != p) 
	{
        int v = x.fi, id = x.se;
        it.upd(1, n, e[id].w);
        it.upd(tin[v], tout[v], -2ll*e[id].w);
        dfssmall(v, u);
        it.upd(tin[v], tout[v], +2ll*e[id].w);
        it.upd(1, n, -e[id].w);
    }
    for (int i : small[u]) 
	{
        int v = q[i].fi;
        v = ide[v];
        if (isin(H, v)) ans[i] = -1;
        else {
            ll t = it.get(tin[v], tout[v]);
            if (t >= 1e15) ans[i] = -2;
            else ans[i] = t;
        }
    }
    for (int i : big[u]) 
	{
        int v = q[i].fi;
        v = ide[v];
        if (isin(H, v) == 0) ans[i] = -1;
        else {
            ll t = min(it.get(1, tin[v] - 1), it.get(tout[v] + 1, n));
            if (t >= 1e15) ans[i] = -2;
            else ans[i] = t;
        }
    }
}
int main() 
{
    #define TASK "template"
//    freopen(TASK".inp", "r", stdin);
//    freopen(TASK".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> S >> Q >> H;
    forr(i, 1, n - 1) {
        int u, v, w; cin >> u >> v >> w;
        ke[u].push_back({v, i});
        ke[v].push_back({u, i});
        e[i] = {u, v, w};
    }
    forr(i, 1, S) cin >> a[i], mark[a[i]] = 1;
    forr(i, 1, Q) cin >> q[i].fi >> q[i].se;
    dfs(1, 0);
    forr(i, 1, n) 
	{
        if (mark[i]) it.upd(tin[i], tin[i], dist[i]);
        else it.upd(tin[i], tin[i], oo);
    }
    forr(i, 1, Q) 
	{
        int del = q[i].fi, u = q[i].se;
        int v = ide[del];
        if (isin(u, v)) small[u].push_back(i);
        else big[u].push_back(i);
    }
    dfssmall(1, 0);
    forr(i, 1, Q) if (ans[i] == -1) cout << "escaped" << endl;
    else if (ans[i] == -2) cout << "oo" << endl;
    else cout << ans[i] << endl;
    return 0;
}
 