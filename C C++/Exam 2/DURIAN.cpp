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
const int M = (int) 19;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, mx_canh, duong[N];
vec(int) inp[N];
bool vit[N];

void dfs(int u) {
    vit[u] = true;
    for (int v : inp[u]) {
        if (!vit[v]) {
            duong[v] = duong[u] + 1;
            dfs(v);
        }
    }
}

int par[N][M + 1], high[N];

void dfs_lca(int u) {
    for (int v : inp[u]) {
        if (v != par[u][0]) {
            par[v][0] = u;
            high[v] = high[u] + 1;
            dfs_lca(v);
        }
    }
}

int lca(int u, int v) {
    if (high[v] > high[u]) return lca(v, u);
    Ford (i, M, 0, 1) if (high[par[u][i]] >= high[v])
        u = par[u][i];
    if (u == v) return u;
    Ford(i, M, 0, 1) if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

ll get_d(int u, int v) {
    return duong[u] + duong[v] - (duong[lca(u, v)] * 2);
}

int ans = INT_MIN;
bool used[N];

void sinh_th(vec(int) luu) {
    if (!luu.empty()) {
        bool check = true;
        Rep(i, luu.size()) {
            For(j, i + 1, luu.size() - 1, 1)
                if (get_d(luu[i], luu[j]) < mx_canh) {
                    check = false;
                    break;
                }
            if (!check) break;
        }

        if (check)
            maximize(ans, (int) luu.size());
        else
            return;
    }

    if (luu.size() == n) return;

    For(i, 1, n, 1) {
        if (!used[i]) {
            used[i] = true;
            luu.pub(i);
            sinh_th(luu);
            luu.pb();
            used[i] = false;
        }
    }
}

void sub1(void) {
    vec(int) tmp;
    sinh_th(tmp);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("DURIAN.inp", "r", stdin);
    freopen("DURIAN.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> mx_canh;
    Rep(edge, n - 1) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
    }

    dfs(1);
    dfs_lca(1);
    For(j, 1, M, 1) For(i, 1, n, 1)
        par[i][j] = par[par[i][j - 1]][j - 1];
    high[0] = -1;

    //if (n <= 20)
        sub1();

    return (0 ^ 0);
}
