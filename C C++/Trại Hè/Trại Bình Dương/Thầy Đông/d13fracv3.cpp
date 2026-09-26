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
const int N = (int) 5e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, duong[N], a[N], trace[N];
map <ii(int, int), int> idx;
vec(int) inp[N];

void noi(int x, int y) { inp[x].pub(y); inp[y].pub(x); }

void init(void) {
    idx[{1, 1}] = 1; idx[{1, 2}] = 2; idx[{2, 1}] = 3; idx[{1, 3}] = 4; idx[{2, 3}] = 5;
    idx[{3, 2}] = 6; idx[{3, 1}] = 7; idx[{1, 4}] = 8; idx[{2, 5}] = 9; idx[{3, 5}] = 10;
    idx[{3, 4}] = 11; idx[{4, 3}] = 12; idx[{5, 3}] = 13; idx[{5, 2}] = 14; idx[{4, 1}] = 15;
    idx[{1, 5}] = 16; idx[{2, 7}] = 17; idx[{3, 8}] = 18; idx[{3, 7}] = 19; idx[{4, 7}] = 20;
    idx[{5, 8}] = 21; idx[{5, 7}] = 22; idx[{4, 5}] = 23; idx[{5, 4}] = 24; idx[{7, 5}] = 25;
    idx[{8, 5}] = 26; idx[{7, 4}] = 27; idx[{7, 3}] = 28; idx[{8, 3}] = 29; idx[{7, 2}] = 30; idx[{5, 1}] = 31;
    noi(1, 2); noi(1, 3); noi(2, 4); noi(2, 5); noi(3, 6); noi(3, 7); noi(4, 8); noi(4, 9); noi(5, 10);
    noi(5, 11); noi(6, 12); noi(6, 13); noi(7, 14); noi(7, 15); noi(8, 16); noi(8, 17); noi(9, 18);
    noi(9, 19); noi(10, 20); noi(10, 21); noi(11, 22); noi(11, 23); noi(12, 24); noi(12, 25); noi(13, 26);
    noi(13, 27); noi(14, 28); noi(14, 29); noi(15, 30); noi(15, 31);
}

map <ii(int, int), int> cnt;

void dijkstra(int s, int t) {
    memset(duong, 0x3f, (31 + 1) * sizeof(ll)); duong[s] = 0;
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
    vec(int) luu;
    do {
        luu.pub(t);
        t = trace[t];
    } while (t != s);
    luu.pub(s); reverse(all(luu));

    Rep(i, luu.size() - 1) {
        int x = luu[i], y = luu[i + 1]; if (x > y) swap(x, y);
        ++cnt[{x, y}];
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    init();

    cin >> n >> m;
    For(i, 1, m, 1) {
        int x, y; cin >> x >> y;
        a[i] = idx[{x, y}];
    }

    For(i, 2, m, 1) dijkstra(a[i], 1);
    cout << cnt.size();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
