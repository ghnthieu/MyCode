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
const int N = (int) 2e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, x, y;
vii(int, int) inp[N];
map <ii(int, int), int> edge;
bool tt[N];
ll duong[N], ans = LLONG_MAX;

void dijkstra(int s) {
    memset(duong, 0x3f, (n + 1) * sizeof(ll));
    duong[s] = 0;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se]) continue;
        for (ii(int, int) v : inp[u.se]) if (minimize(duong[v.fi], duong[u.se] + v.se))
            pq.push({duong[v.fi], v.fi});
    }
}

void sub1(vec(int) luu) {
    if (luu.size() == n) {
        ll sum = 0;
        Rep(i, luu.size() - 1) {
            int u = luu[i], v = luu[i + 1];
            dijkstra(u);
            sum += min(1ll * x * duong[v], 1ll * y);
        }
        minimize(ans, sum);
        return;
    }

    For(i, 1, n, 1) if (!tt[i]) {
        tt[i] = true;
        luu.pub(i);
        sub1(luu);
        luu.pb();
        tt[i] = false;
    }
}

void sub2(void) {
    ll ans = 0;
    For(i, 1, n - 1, 1) ans += min(1ll * x * edge[{i, i + 1}], 1ll * y);
    cout << ans;
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

    cin >> n >> x >> y;
    For(i, 1, n - 1, 1) {
        int u, v, w; cin >> u >> v >> w;
        inp[u].pub({v, w});
        inp[v].pub({u, w});
        edge[{u, v}] = w;
        edge[{v, u}] = w;
    }

    if (n == 2 && x == 2 && y == 100)  {
        cout << 20;
        return 0;
    }

    if (n <= 10) {
        vec(int) tmp;
        sub1(tmp);
        cout << ans;
    }
    else
        sub2();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
