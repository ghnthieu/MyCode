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

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q, tid[N], kbau[N], duong[N], trace[N], cnt[N], cost[N];
vec(int) inp[N], luu[N];

void dijkstra(int s, int t, int idx) {
    memset(duong, 0x3f, (n + 1) * sizeof(int)); duong[s] = 0;
    priority_queue <ii(int, int), vii(int, int), greater <ii(int, int)>> pq; pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se]) continue;
        for (int v : inp[u.se]) if (minimize(duong[v], duong[u.se] + 1)) {
            pq.push({duong[v], v});
            trace[v] = u.se;
        }
    }
    vec(int) tmp;
    do {
        tmp.pub(t);
        t = trace[t];
    } while (t != s);
    reverse(all(tmp));
    for (int x : tmp) luu[idx].pub(x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("treasure.inp", "r", stdin);
    freopen("treasure.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    For(i, 2, n, 1) {
        int x; cin >> x;
        inp[x].pub(i);
        inp[i].pub(x);
    }
    For(i, 1, n, 1) {
        int x; cin >> x;
        tid[i] = x;
    }
    For(i, 1, n, 1) cin >> cost[i];

    luu[1].pub(1);
    For(i, 2, n, 1) dijkstra(1, i, i);

    /*For(i, 1, n, 1) {
        for (int x : luu[i]) cout << x << " ";
        cout << '\n';
    }*/

    Rep(query, q) {
        int type; cin >> type;
        if (type == 1) {
            int v, new_id; cin >> v >> new_id;
            tid[v] = new_id;
        }
        else {
            int choose, m; cin >> choose >> m;
            For(i, 1, m, 1) cin >> kbau[i];

            memset(cnt, 0, (n + 1) * sizeof(int));
            For(i, 1, m, 1) for (int x : luu[kbau[i]])
                ++cnt[x];

            ll ans = 0;
            For(i, 1, n, 1) if (tid[i] == choose)
                maximize(ans, 1ll * cost[i] * cnt[i]);
            cout << ans << '\n';
        }
    }

    return 0;
}
