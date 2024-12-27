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
const int M = (int) 1e3 + 7;
const int oo = (int) 1e9 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, q, low[N], num[N], tid[N], cnt = 0, tpltm = 0;
vec(int) inp[N], tplt[N];
ii(int, int) que[N];
stack <int> st;

void dfs(int u) {
    low[u] = num[u] = ++cnt; st.push(u);
    for (int v : inp[u]) if (!tid[v]) {
        if (!num[v]) { dfs(v); minimize(low[u], low[v]); }
        else minimize(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        ++tpltm;
        int v = 0;
        do {
            v = st.top(); st.pop();
            tid[v] = tpltm;
        } while (u != v);
    }
}

int tduong[M][M], duong[M], maxi[N];

void dijkstra(int s) {
    memset(duong, 0x3f, (n + 1) * sizeof(ll));
    duong[s] = 0;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se]) continue;
        for (int v : inp[u.se]) if (minimize(duong[v], duong[u.se] + 1))
            pq.push({duong[v], v});
    }
}

void sub1(void) {
    For(i, 1, n, 1) {
        dijkstra(i);
        For(j, 1, n, 1) tduong[i][j] = ((duong[j] > oo) ? (-1) : duong[j]);
        For(j, 1, n, 1) maximize(maxi[i], tduong[i][j]);
    }

    //For(i, 1, n, 1) cout << maxi[i] << " ";
    //cout << '\n';

    For(i, 1, n, 1) if (!num[i])
        dfs(i);
    For(i, 1, n, 1) tplt[tid[i]].pub(i);
    /*For(i, 1, n, 1) {
        for (int x : tplt[i]) cout << x <<  " ";
        cout << '\n';
    }
    cout << '\n';*/

    For(i, 1, q, 1) {
        int u = que[i].fi, v = que[i].se, ans = 0;
        if (tid[u] == tid[v]) { cout << 0 << '\n'; continue; }
        for (int x : tplt[tid[u]]) for (int y : tplt[tid[v]])
            ans += maxi[x] + maxi[y] + 1;
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DIAMETER.inp", "r", stdin);
    freopen("DIAMETER.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> q;
    For(i, 1, m, 1) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
    }
    For(i, 1, q, 1) cin >> que[i].fi >> que[i].se;

    sub1();

    return 0;
}
