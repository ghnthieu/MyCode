#include <bits/stdc++.h>
#define ll long long
#define forr(i, l, r) for (ll i = l; i <= r; i++)
#define fodd(i, l, r) for (ll i = l; i >= r; i--)
#define all(v) v.begin(), v.end()
#define biti(i, x) ((1ll << (i)) & (x))
#define boolbit(i, x) (biti(i, x) != 0)
#define endl '\n'
#define fi first
#define se second
#define sz(x) (ll)(x.size())
#define ii pair<ll,ll>
#define optm(v) v.resize(unique(all(v)) - v.begin())
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) {if (a > b) {a = b; return true;} return false;}
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) {if (a < b) {a = b; return true;} return false;}
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int n, k, c[100011], nc[100011];
vector<int> e[100011];
pair<int, int> res;
int d[100011], s[100011], t[100011], mx;
int ti[100011], to[100011], sz[100011], h[100011], timee;
vector<int> *vec[100011];
vector<int> p[100011];
int v[100011];
void dfs0(int u) 
{
    ti[u] = ++timee;
    for (int x : e[u]) 
    {
        h[x] = h[u] + 1;
        dfs0(x);
        sz[u] += sz[x];
    }
    sz[u]++;
    to[u] = timee;
}
void dfs1(int u, int cl, int hh) 
{
    for (int x : e[u])
        dfs1(x, cl, hh + 1);
    d[hh] += (c[u] == cl);
}
void dfs3(int u, int cl, int hh) 
{
    for (int x : e[u])
        dfs3(x, cl, hh + 1);
    mx = max(mx, hh);
    s[hh]++;
    t[hh] += (c[u] == cl);
}
void dfs2(int u, int cl, int hh) 
{
    if (c[u] == cl) 
    {
        mx = 0;
        for (int x : e[u])
            dfs3(x, cl, hh + 1);
        pair<int, int> x = {1, 0};
        forr(i, hh + 1, mx) 
        {
            x.fi += min(d[i], s[i]);
            x.se += min(d[i], s[i]) - t[i];
            s[i] = t[i] = 0;
        }
        if (res.fi < x.fi || (res.fi == x.fi && res.se > x.se))
            res = x;
        return;
    }
    for (int x : e[u])
        dfs2(x, cl, hh + 1);
}
void solve1(int cl) 
{
    forr(i, 0, n - 1)
        d[i] = s[i] = t[i] = 0;

    dfs1(0, cl, 0);
    dfs2(0, cl, 0);
}
void dsutree(int u, int keep) 
{
    int mx = -1, bc = -1;
    for (int x : e[u])
        if (sz[x] > mx)
            mx = sz[x], bc = x;

    for (int x : e[u])
        if (x != bc)
            dsutree(x, 0);
    if (bc != -1)
        dsutree(bc, 1), vec[u] = vec[bc];
    else vec[u] = new vector<int>();
    vec[u]->push_back(h[u]);
    s[h[u]]++;
    for (int x : e[u])
        if (x != bc)
            for (int v : *vec[x]) 
            {
                vec[u]->push_back(v);
                s[v]++;
            }
    if (nc[c[u]] <= sqrt(n)) 
    {
        for (int x : p[c[u]])
            v[h[x]] = d[h[x]] = t[h[x]] = 0;
        for (int x : p[c[u]]) 
        {
            d[h[x]]++;
            if (ti[x] >= ti[u] && ti[x] <= to[u])
                t[h[x]]++;
        }
        pair<int, int> y = {1, 0};
        for (int x : p[c[u]])
            if (h[x] > h[u] && !v[h[x]]) 
            {
                v[h[x]] = 1;
                y.fi += min(s[h[x]], d[h[x]]);
                y.se += min(s[h[x]], d[h[x]]) - t[h[x]];
            }
        if (res.fi < y.fi || (res.fi == y.fi && res.se > y.se))
            res = y;
    }
    if (!keep) 
    {
        for (int x : *vec[u])
            s[x]--;
    }
}
int main() 
{
    #define TASK "template"
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".ans", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    forr(i, 0, n - 1) 
    {
        cin >> c[i];
        nc[c[i]]++;
        p[c[i]].push_back(i);
    }
    forr(i, 1, n - 1) 
    {
        int par;
        cin >> par;
        e[par].push_back(i);
    }
    forr(i, 0, k - 1)
        if (nc[i] && nc[i] > sqrt(n))
            solve1(i);
    dfs0(0);
    dsutree(0, 0);
    cout << res.fi << ' ' << res.se << '\n';
}