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
const int N = (int) 5e2 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m1, m2;
ll duong_a[N], duong_b[N];
vec(int) inp_a[N], inp_b[N];
bool vit[N];

void dijkstra_a(int s) {
    memset(vit, false, (n + 1) * sizeof(bool));
    memset(duong_a, 0x3f, (n + 1) * sizeof(ll));
    duong_a[s] = 0;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (vit[u.se]) continue;
        vit[u.se] = true;
        for (int v : inp_a[u.se]) if (minimize(duong_a[v], duong_a[u.se] + 1)) {
            pq.push({duong_a[v], v});
        }
    }
}

void dijkstra_b(int s) {
    memset(vit, false, (n + 1) * sizeof(bool));
    memset(duong_b, 0x3f, (n + 1) * sizeof(ll));
    duong_b[s] = 0;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (vit[u.se]) continue;
        vit[u.se] = true;
        for (int v : inp_b[u.se]) if (minimize(duong_b[v], duong_b[u.se] + 1)) {
            pq.push({duong_b[v], v});
        }
    }
}

void solve(void) {
    ll ans = 0;
    For(i, 1, n, 1) {
        dijkstra_a(i);
        dijkstra_b(i);
        For(j, 1, n, 1) ans += max(duong_a[j], duong_b[j]) * 2ll;
    }
    cout << ans / 2ll;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m1;
    Rep(edge, m1) {
        int x, y; cin >> x >> y;
        inp_a[x].pub(y);
        inp_a[y].pub(x);
    }
    cin >> m2;
    Rep(edge, m2) {
        int x, y; cin >> x >> y;
        inp_b[x].pub(y);
        inp_b[y].pub(x);
    }

    solve();

    return 0;
}
