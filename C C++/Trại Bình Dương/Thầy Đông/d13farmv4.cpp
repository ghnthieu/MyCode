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
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, high[N], par[N], l[N], r[N];
ll pre[N], val[N], ans[N], sum;

struct edgee {
    int u, v, w;
} edge[N];

struct queryy {
    int d, id;
} que[N];

bool cmp(edgee x, edgee y) {
    return (x.w < y.w);
}

bool cmpp(queryy x, queryy y) {
    return (x.d < y.d);
}

void initt(void) {
    sort(high + 1, high + n + 1);
    pre[0] = 0; pre[1] = high[1];
    For(i, 2, n, 1) pre[i] = pre[i - 2] + high[i];
    For(i, 1, n - 1, 1) edge[i] = {i + 1, i, high[i + 1] - high[i]};
    sort(edge + 1, edge + n, cmp);
    sort(que + 1, que + m + 1, cmpp);
}

void init(void) {
    For(i, 1, n, 1) {
        par[i] = i;
        l[i] = i; r[i] = i;
        val[i] = high[i];
    }
}

int find_par(int u) {
    if (u == par[u]) return u;
    return par[u] = find_par(par[u]);
}

void add_par(int u, int v) {
    u = find_par(u); v = find_par(v);
    if (u == v) return;
    par[v] = u;
    sum -= val[u];
    sum -= val[v];
    minimize(l[u], l[v]);
    maximize(r[u], r[v]);
    val[u] = (pre[r[u]] - pre[l[u] + (r[u] - l[u]) % 2 - 2]);
    sum += val[u];
}

void solve(void) {
    initt();
    init();
    int j = 0;
    For(i, 1, m, 1) {
        while (j + 1 < n && edge[j + 1].w <= que[i].d) {
            ++j;
            add_par(edge[j].u, edge[j].v);
        }
        ans[que[i].id] = sum;
    }
    For(i, 1, m, 1) cout << ans[i] << '\n';
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    For(i, 1, n, 1) {
        cin >> high[i];
        sum += high[i];
    }
    For(i, 1, m, 1) {
        int d; cin >> d;
        que[i] = {d, i};
    }

    solve();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
