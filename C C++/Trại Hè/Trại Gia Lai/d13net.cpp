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
const int N = (int) 5e1 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, dsu[N][N];
ii(int, int) edge[N];
ll dp[N][1][2][3][4][5][6][7][8][9];

int find_par(int idx, int u) {
    if (dsu[idx][u] == u) return u;
    return dsu[idx][u] = find_par(idx, dsu[idx][u]);
}

void add_par(int idx, int u, int v) {
    u = find_par(idx, u); v = find_par(idx, v);
    if (u > v) swap(u, v);
    dsu[idx][v] = u;
    For(i, 1, 9, 1) find_par(idx, i);
}

ll calc(int idx) {
    if (idx == m + 1) {
        For(i, 1, n, 1) if (dsu[idx][i] != dsu[49][i]) return 0;
        return 1;
    }
    ll &res = dp[idx][dsu[idx][1] - 1][dsu[idx][2] - 1][dsu[idx][3] - 1][dsu[idx][4] - 1][dsu[idx][5] - 1][dsu[idx][6] - 1][dsu[idx][7] - 1][dsu[idx][8] - 1][dsu[idx][9] - 1];
    if (res != -1) return res; res = 0;
    For(i, 1, 9, 1) dsu[idx + 1][i] = dsu[idx][i];
    res += calc(idx + 1);
    add_par(idx + 1, edge[idx].fi, edge[idx].se);
    res += calc(idx + 1);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    For(i, 1, m, 1) cin >> edge[i].fi >> edge[i].se;

    memset(dp, -1, sizeof(dp));
    For(i, 1, 9, 1) dsu[1][i] = i;
    For(i, 1, n, 1) dsu[49][i] = i;
    For(i, 1, m, 1) add_par(49, edge[i].fi, edge[i].se);

    cout << calc(1);

    return 0;
}
