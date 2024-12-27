#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pub push_back
#define pb pop_back
#define mask(i) (1ll << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n  = (n); i < _n; ++i)
template <typename T1, typename T2> bool maximize(T1 &x, T2 y) { if (x < y) { x = y; return true; } return false; }
template <typename T1, typename T2> bool minimize(T1 &x, T2 y) { if (x > y) { x = y; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;

int n, q, a[N], duong[N], trace[N];
vec(int) inp[N], luu;

void dijkstra_trace(int s, int t) {
    memset(duong, 0x3f, (n + 1) * sizeof(int)); duong[s] = 0;
    priority_queue <ii(int, int), vii(int, int), greater <ii(int, int)>> pq; pq.push({0, s});
    while (!pq.empty()) {
        ii(int, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se]) continue;
        for (int v : inp[u.se]) if (minimize(duong[v], duong[u.se] + 1)) {
            pq.push({duong[v], v});
            trace[v] = u.se;
        }
    }
    luu.clear();
    do {
        luu.pub(t); t = trace[t];
    } while (s != t);
    luu.pub(s); reverse(all(luu));
}

vec(vec(int)) tluu;

void backtrack(vec(int) luu) {
    if (luu.size() % 2 == 1)
        tluu.pub(luu);
    if (luu.size() == min(20, n)) return;
    For(i, 1, n, 1) {
        luu.pub(i);
        backtrack(luu);
        luu.pb();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    For(i, 1, n, 1) cin >> a[i];
    For(i, 1, n - 1, 1) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
    }

    vec(int) tmp;
    backtrack(tmp);

    Rep(query, q) {
        int u, v; cin >> u >> v; if (u > v) swap(u, v);
        dijkstra_trace(u, v);
        //for (int x : luu) cout << x << " ";
        //cout << '\n';
        int ans = 0;
        For(k, 1, min(n, 20), 1) if (k % 2 == 1) {
            bool check = false;
            Rep(i, tluu.size()) if (tluu[i].size() == k) {
                bool ok = true;
                Rep(j, tluu[i].size() - 1) {
                    if ((j + 1) % 2 == 1) {
                        int tmp1 = tluu[i][j], tmp2 = tluu[i][j + 1];
                        if (a[luu[tmp1]] > a[luu[tmp2]]) {
                            ok = false;
                            break;
                        }
                    }
                    else {
                        int tmp1 = tluu[i][j], tmp2 = tluu[i][j + 1];
                        if (a[luu[tmp1]] < a[luu[tmp2]]) {
                            ok = false;
                            break;
                        }
                    }
                }
            }
            if (check) ans = k;
        }
        cout << ans << '\n';
    }

    return 0;
}
