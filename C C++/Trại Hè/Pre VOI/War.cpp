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
const int INF = (int) 1e9 + 7;
const int N = (int) 2e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int t, n, m, trace[N];
ll brok[N][N];
vii(int, int) inp[N];
bool can_go[N][N], tcan_go[N][N];
vec(int) luu;

ll duong[N];

void dijkstra(int s, int t) {
    memset(duong, 0x3f, (n + 1) * sizeof(ll)); duong[s] = 0;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq; pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se]) continue;
        for (ii(int, int) v : inp[u.se]) if (tcan_go[u.se][v.fi] && tcan_go[v.fi][u.se] && minimize(duong[v.fi], duong[u.se] + v.se)) {
            pq.push({duong[v.fi], v.fi});
            trace[v.fi] = u.se;
        }
    }
    luu.clear();
    do {
        luu.pub(t);
        t = trace[t];
    } while (t != s);
    luu.pub(s); reverse(all(luu));
}

ll ans[N][N];

void solve(void) {
    Rep(i, n) For(j, i + 1, n - 1, 1) {
        Rep(k1, n) Rep(k2, n)
            tcan_go[k1][k2] = can_go[k1][k2];

        //cout << i << " " << j << '\n';
        while (true) {
            dijkstra(i, j); if (duong[j] >= INF) break;
            //for (int x : luu) cout << x << " ";
            //cout << '\n';
            ll res = LLONG_MAX; int u, v;
            Rep(k, luu.size() - 1) if (minimize(res, brok[luu[k]][luu[k + 1]])) {
                u = luu[k]; v = luu[k + 1];
            }
            tcan_go[u][v] = false;
            tcan_go[v][u] = false;
            ans[i][j] += res; ans[j][i] += res;

            //cout << res << '\n';
        }
        //cout << '\n';

    }

    /*Rep(i, n) {
        Rep(j, n) cout << ans[i][j] << " ";
        cout << '\n';
    }

    cout << '\n';

    Rep(i, n) {
        Rep(j, n) cout << brok[i][j] << " ";
        cout << '\n';
    }*/

    if (t == 1) {
        ll anss = LLONG_MAX;
        Rep(i, n) Rep(j, n) if (i != j)
            minimize(anss, ans[i][j]);
        cout << anss << '\n';
    }
    else {
        ll sum = 0; int cnt = 0;
        Rep(i, n) Rep(j, n) {
            ++cnt; sum += ans[i][j];
        }
        cout << sum / cnt * n * (n - 1) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> t >> n >> m;
    For(i, 1, m, 1) {
        int x, y, w; cin >> x >> y >> w;
        brok[x][y] += w;
        brok[y][x] += w;
        inp[x].pub({y, w});
        inp[y].pub({x, w});
        can_go[x][y] = true;
        can_go[y][x] = true;
    }

    solve();

    return 0;
}
