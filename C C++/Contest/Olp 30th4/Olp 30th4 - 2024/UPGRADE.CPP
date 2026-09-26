#include <bits/stdc++.h>
using namespace std;

#define NAME ""
#define fi first
#define se second
#define fr front
#define bk back
#define pf pop_front
#define pb pop_back
#define puf push_front
#define pub push_back
#define NOT 18446744073709551615
#define __Trung_Hieu___ signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define vec(kdl) vector <kdl>
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1,kdl2>,kdl3>>
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
typedef long double lde;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;

int n, m, trance[N];
vii(int, int) inp[N];
ll duong[N];

vec(int) dijkstra(int s, int t) {
    duong[s] = 0;
    trance[s] = s;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se])
            continue;
        for (ii(int, int) v : inp[u.se]) {
            if (minimize(duong[v.fi], duong[u.se] + v.se)) {
                pq.push({duong[v.fi], v.fi});
                trance[v.fi] = u.se;
            }
        }
    }
    vec(int) luu;
    do {
        luu.pub(t);
        t = trance[t];
    } while (t != s);
    luu.pub(s);
    reverse(all(luu));
    return luu;
}

void solve(void) {
    memset(duong, 0x3f, sizeof(duong));
    vec(int) luul = dijkstra(1, n);
    memset(duong, 0x3f, sizeof(duong));
    vec(int) luur = dijkstra(n, 1);
    reverse(all(luur));
    int cnt = 0;
    for (int i=0; i<luul.size()-1; ++i) {
        if (luul[i] == luur[i] && luul[i + 1] == luur[i + 1])
            ++cnt;
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("UPGRADE.INP", "r", stdin);
    freopen("UPGRADE.OUT", "w", stdout);

    cin >> n >> m;
    for (int i=1; i<=m; ++i) {
        int x, y, t; cin >> x >> y >> t;
        inp[x].pub({y, t});
        inp[y].pub({x, t});
    }

    solve();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
