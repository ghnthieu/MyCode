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
const int N = (int) 5e2 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, par[N];
ll wei[N][N];
bool vit[N];
vec(int) inp[N];

ll Ford_Fulkerson(int s, int t) {
    ll res = 0;
    while (true) {
        //Init
        memset(vit, false, (n + 1) * sizeof(bool));
        memset(par, (-1), (n + 1) * sizeof(int));
        queue <int> q;
        q.push(s);
        vit[s] = true;

        //Tim duong tang luong
        while (!q.empty()) {
            int u = q.fr(); q.pop();
            for (int v : inp[u]) {
                if (!vit[v] && wei[u][v]) {
                    vit[v] = true;
                    par[v] = u;
                    q.push(v);
                }
            }
        }

        //Check ton tai duong tang luong
        if (!vit[t]) break;

        //Find gia tri tang luong
        ll flow = LLONG_MAX;
        int v = t;
        while (v != s) {
            int u = par[v];
            minimize(flow, wei[u][v]);
            v = u;
        }

        //Cap nhat weight luong
        v = t;
        while (v != s) {
            int u = par[v];
            wei[u][v] -= flow;
            wei[v][u] += flow;
            v = u;
        }

        //Cap nhat ans
        res += flow;
    }

    return res;
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    Rep(edge, m) {
        int x, y, w; cin >> x >> y >> w;
        inp[x].pub(y);
        inp[y].pub(x);
        wei[x][y] += w;
    }

    cout << Ford_Fulkerson(1, n);

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
