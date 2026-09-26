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

typedef double de;
typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 2e3 + 7;
const int M = (int) 1e5 + 7;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int n, m, w, h;

struct Data {
    int x, y, r;
} a[N];

de dist(int x, int y, int u, int v, int r1, int r2) {
    return (de) sqrt(1ll * abs(u - x) * abs(u - x) + 1ll * abs(v - y) * abs(v - y)) - r1 - r2;
}

viii(int, int, de) edge;

vec(int) par;

void init(int n) {
    par.resize(n + 6, 0);
    For(i, 1, n + 4, 1) par[i] = i;
}

int find_par(int u) {
    if (u == par[u]) return u;
    return (par[u] = find_par(par[u]));
}

bool cmp(iii(int, int, de) x, iii(int, int, de) y) {
    if (x.se == y.se) return (x.fi.se < y.fi.se);
    return (x.se < y.se);
}

string ans[M];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> w >> h;
    For(i, 1, n, 1) {
        cin >> a[i].x >> a[i].y >> a[i].r;
        edge.pub({{i, n + 1}, dist(a[i].x, a[i].y, a[i].x, h, a[i].r, 0)});
        edge.pub({{i, n + 2}, dist(a[i].x, a[i].y, w, a[i].y, a[i].r, 0)});
        edge.pub({{i, n + 3}, dist(a[i].x, a[i].y, a[i].x, 0, a[i].r, 0)});
        edge.pub({{i, n + 4}, dist(a[i].x, a[i].y, 0, a[i].y, a[i].r, 0)});
    }
    For(i, 1, n, 1) For(j, i + 1, n, 1)
        edge.pub({{i, j}, dist(a[i].x, a[i].y, a[j].x, a[j].y, a[i].r, a[j].r)});
    For(i, 1, m, 1) {
        int x, y; cin >> x >> y;
        edge.pub({{y, -i}, x * 2});
    }

    init(n);
    sort(all(edge), cmp);
    //for (iii(int, int, de) x : edge) cout << x.se << " " << x.fi.fi << " " << x.fi.se << '\n';

    for (iii(int, int, de) x : edge) {
        if (x.fi.se > 0) {
            int tmp1 = find_par(x.fi.fi), tmp2 = find_par(x.fi.se);
            if (tmp1 != tmp2) par[tmp1] = tmp2;
        }
        else {
            x.fi.se = abs(x.fi.se);
            //cout << x.fi.se << " ";
            For(i, 1, 4, 1) {
                if (i == x.fi.fi) {
                    ans[x.fi.se] += to_string(i);
                    continue;
                }
                bool check = true;
                if (x.fi.fi <= i) {
                    if (x.fi.fi == 1 && i == 2) {
                        if (find_par(n + 1) == find_par(n + 3))
                            check = false;
                        else if (find_par(n + 2) == find_par(n + 3))
                            check = false;
                        else if (find_par(n + 3) == find_par(n + 4))
                            check = false;
                    }
                    else if (x.fi.fi == 1 && i == 3) {
                        if (find_par(n + 1) == find_par(n + 2))
                            check = false;
                        else if (find_par(n + 1) == find_par(n + 3))
                            check = false;
                        else if (find_par(n + 2) == find_par(n + 4))
                            check = false;
                        else if (find_par(n + 3) == find_par(n + 4))
                            check = false;
                    }
                    else if (x.fi.fi == 1 && i == 4) {
                        if (find_par(n + 1) == find_par(n + 4))
                            check = false;
                        else if (find_par(n + 2) == find_par(n + 4))
                            check = false;
                        else if (find_par(n + 3) == find_par(n + 4))
                            check = false;
                    }
                    else if (x.fi.fi == 2 && i == 3) {
                        if (find_par(n + 1) == find_par(n + 2))
                            check = false;
                        else if (find_par(n + 2) == find_par(n + 3))
                            check = false;
                        else if (find_par(n + 2) == find_par(n + 4))
                            check = false;
                    }
                    else if (x.fi.fi == 2 && i == 4) {
                        if (find_par(n + 1) == find_par(n + 3))
                            check = false;
                        else if (find_par(n + 1) == find_par(n + 4))
                            check = false;
                        else if (find_par(n + 2) == find_par(n + 3))
                            check = false;
                        else if (find_par(n + 2) == find_par(n + 4))
                            check = false;
                    }
                    else if (x.fi.fi == 3 && i == 4) {
                        if (find_par(n + 1) == find_par(n + 2))
                            check = false;
                        else if (find_par(n + 1) == find_par(n + 3))
                            check = false;
                        else if (find_par(n + 1) == find_par(n + 4))
                            check = false;
                    }
                }
                else {
                    if (x.fi.fi == 2 && i == 1) {
                        if (find_par(n + 1) == find_par(n + 3))
                            check = false;
                        else if (find_par(n + 2) == find_par(n + 3))
                            check = false;
                        else if (find_par(n + 3) == find_par(n + 4))
                            check = false;
                    }
                    else if (x.fi.fi == 3 && i == 1) {
                        if (find_par(n + 1) == find_par(n + 2))
                            check = false;
                        else if (find_par(n + 1) == find_par(n + 3))
                            check = false;
                        else if (find_par(n + 2) == find_par(n + 4))
                            check = false;
                        else if (find_par(n + 3) == find_par(n + 4))
                            check = false;
                    }
                    else if (x.fi.fi == 4 && i == 1) {
                        if (find_par(n + 1) == find_par(n + 4))
                            check = false;
                        else if (find_par(n + 2) == find_par(n + 4))
                            check = false;
                        else if (find_par(n + 3) == find_par(n + 4))
                            check = false;
                    }
                    else if (x.fi.fi == 3 && i == 2) {
                        if (find_par(n + 1) == find_par(n + 2))
                            check = false;
                        else if (find_par(n + 2) == find_par(n + 3))
                            check = false;
                        else if (find_par(n + 2) == find_par(n + 4))
                            check = false;
                    }
                    else if (x.fi.fi == 4 && i == 2) {
                        if (find_par(n + 1) == find_par(n + 3))
                            check = false;
                        else if (find_par(n + 1) == find_par(n + 4))
                            check = false;
                        else if (find_par(n + 2) == find_par(n + 3))
                            check = false;
                        else if (find_par(n + 2) == find_par(n + 4))
                            check = false;
                    }
                    else if (x.fi.fi == 4 && i == 3) {
                        if (find_par(n + 1) == find_par(n + 2))
                            check = false;
                        else if (find_par(n + 1) == find_par(n + 3))
                            check = false;
                        else if (find_par(n + 1) == find_par(n + 4))
                            check = false;
                    }
                }

                if (check) ans[x.fi.se] += to_string(i);
            }
        }
    }

    For(i, 1, m, 1) cout << ans[i] << '\n';

    return 0;
}
