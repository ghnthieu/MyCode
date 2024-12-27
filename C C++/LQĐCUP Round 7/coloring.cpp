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
const int N = (int) 7e1 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, k, trace[N];
vec(int) inp[N], luu;
ll duong[N];

void dijkstra(int s, int t) {
    memset(duong, 0x3f, (n + 1) * sizeof(ll));
    duong[s] = 0;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se]) continue;
        for (int v : inp[u.se]) if (minimize(duong[v], duong[u.se] + 1)) {
            pq.push({duong[v], v});
            trace[v] = u.se;
        }
    }

    do {
        luu.pub(t);
        t = trace[t];
    } while (t != s);
    luu.pub(s); reverse(all(luu));
}

ll ltbinary(ll a, ll b) {
    a %= MOD; ll res = 1;
    while (b) {
        if (b & 1) res = ((res % MOD) * (a % MOD)) % MOD;
        a = ((a % MOD) * (a % MOD)) % MOD;
        b >>= 1;
    }
    return (res % MOD);
}

void add(ll &x, ll y) {
    y %= MOD; x += y;
    x -= ((x >= MOD) ? MOD : 0);
}

void sub1(void) {
    int u, v; cin >> u >> v; if (u > v) swap(u, v);
    if (u != v) {
        dijkstra(u, v);
        if (luu.size() == 2 || k == 1) cout << 0;
        else {
            vii(int, int) edge;
            Rep(i, luu.size() - 1) {
                int x = luu[i], y = luu[i + 1];
                edge.pub({x, y});
            }

            ll ans = 0;
            Rep(i, edge.size()) For(j, i + 1, edge.size() - 1, 1) {
                if (edge.size() > 2) add(ans, ltbinary(k, edge.size() - 2));
                add(ans, 1ll * k * (k - 1));
            }
            cout << ans;
        }
    }
    else cout << 0;
}

void sub2(void) {
    int u1, v1, u2, v2; cin >> u1 >> v1 >> u2 >> v2; if (u1 > v1) swap(u1, v1); if (u2 > v2) swap(u2, v2);
    if (u1 != v1) {
        dijkstra(u1, v1);
        if (luu.size() == 2 || k == 1) cout << 0;
        else {
            vii(int, int) edge;
            Rep(i, luu.size() - 1) {
                int x = luu[i], y = luu[i + 1];
                edge.pub({x, y});
            }

            ll ans = 0;
            Rep(i, edge.size()) For(j, i + 1, edge.size() - 1, 1) {
                if (edge.size() > 2) add(ans, ltbinary(k, edge.size() - 2));
                add(ans, 1ll * k * (k - 1));
            }
            cout << ans << '\n';
        }
    }
    else cout << 0 << '\n';

    if (u2 != v2) {
        luu.clear();
        dijkstra(u2, v2);
        if (luu.size() == 2 || k == 1) cout << 0;
        else {
            vii(int, int) edge;
            Rep(i, luu.size() - 1) {
                int x = luu[i], y = luu[i + 1];
                edge.pub({x, y});
            }

            ll ans = 0;
            Rep(i, edge.size()) For(j, i + 1, edge.size() - 1, 1) {
                if (edge.size() > 2) add(ans, ltbinary(k, edge.size() - 2));
                add(ans, 1ll * k * (k - 1));
            }
            cout << ans;
        }
    }
    else cout << 0;
}

void sub3(void) {
    For(i, 1, m, 1) {
        int u, v; cin >> u >> v;
        if (u != v) {
            dijkstra(u, v);
            if (luu.size() == 2 || k == 1) cout << 0;
            else {
                vii(int, int) edge;
                Rep(i, luu.size() - 1) {
                    int x = luu[i], y = luu[i + 1];
                    edge.pub({x, y});
                }

                ll ans = 0;
                Rep(i, edge.size()) For(j, i + 1, edge.size() - 1, 1) {
                    if (edge.size() > 2) add(ans, ltbinary(k, edge.size() - 2));
                    add(ans, k * (k - 1));
                }
                cout << ans << '\n';
            }
        }
        else cout << 0 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("coloring.inp", "r", stdin);
    freopen("coloring.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> k;
    For(i, 1, n - 1, 1) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
    }

    if (m == 1)
        sub1();
    else if (m == 2)
        sub2();
    else
        sub3();

    return 0;
}
