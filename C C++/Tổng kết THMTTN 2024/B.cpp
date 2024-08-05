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
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, luu[N], ans[N];
vii(int, int) inp[N];
map <iii(int, int, int), int> id;
map <ii(int, int), int> val;
ll duong[N];

void dijkstra(int s, int t) {
    memset(duong, 0x3f, (n + 1) * sizeof(ll));
    duong[s] = 0;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (duong[u.se] < u.fi) continue;
        for (ii(int, int) v : inp[u.se]) {
            if (minimize(duong[v.fi], duong[u.se] + v.se)) {
                pq.push({duong[v.fi], v.fi});
                luu[v.fi] = u.se;
            }
        }
    }

    /*vec(int) tmp;
    do {
        tmp.pub(t);
        t = luu[t];
    } while (t != s);
    tmp.pub(s);
    reverse(all(tmp));

    int mx = INT_MIN, tt;
    Rep(idx, tmp.size() - 1) if (maximize(mx, val[{tmp[idx], tmp[idx + 1]}]))
        tt = id[{{tmp[idx], tmp[idx + 1]}, val[{tmp[idx], tmp[idx + 1]}]}];
    ++ans[tt];*/
    For(i, 1, n, 1) cout << duong[i] << " ";
    cout << '\n';
}

void solve(void) {
    For(i, 1, n, 1) For(j, 1, n, 1) if (i != j)
        dijkstra(i, j);

    /*int mx = INT_MIN, cnt = 0;
    For(i, 1, n, 1) if (maximize(mx, ans[i])) cnt = 1;
    else if (mx == ans[i]) ++cnt;
    cout << cnt << " " << mx << '\n';
    For(i, 1, n, 1) if (ans[i] == mx)
        cout << i << " ";*/
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("B.inp", "r", stdin);
    //freopen("B.out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    Rep(edge, n - 1) {
        int x, y, w; cin >> x >> y >> w;
        inp[x].pub({y, w});
        inp[y].pub({x, w});
        id[{{x, y}, w}] = edge + 1;
        val[{x, y}] = w;
    }

    solve();

    return 0;
}
