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

int n, q, color[N], trace[N];
vec(int) inp[N];
ll duong[N];
vec(int) luu;

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
    luu.clear();
    do {
        luu.pub(t);
        t = trace[t];
    } while (t != s);
    luu.pub(s); reverse(all(luu));
}

int high[N];
bool vit[N];

void xddc(int u) {
    vit[u] = true;
    for (int v : inp[u]) if (!vit[v]) {
        high[v] = high[u] + 1;
        xddc(v);
    }
}

void change_color(int u, int col) {
    vit[u] = true;
    for (int v : inp[u]) if (!vit[v] && high[v] > high[u]) {
        color[v] = col;
        change_color(v, col);
    }
}

set <int> pb;

void cnt_color(int u) {
    vit[u] = true;
    for (int v : inp[u]) if (!vit[v] && high[v] > high[u]) {
        pb.insert(color[v]);
        cnt_color(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("COLTR.inp", "r", stdin);
    freopen("COLTR.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    For(i, 1, n - 1, 1) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
    }
    For(i, 1, n, 1) cin >> color[i];

    xddc(1);
    Rep(query, q) {
        int type; cin >> type;
        if (type == 1) {
            int u, v, new_color; cin >> u >> v >> new_color;
            dijkstra(u, v);
            for (int x : luu) color[x] = new_color;
        }
        else if (type == 2) {
            int u, new_color; cin >> u >> new_color;
            memset(vit, false, (n + 1) * sizeof(bool));
            change_color(u, new_color);
            color[u] = new_color;
        }
        else if (type == 3) {
            int u, v; cin >> u >> v;
            dijkstra(u, v);
            set <int> st;
            for (int x : luu) st.insert(color[x]);
            cout << st.size() << '\n';
        }
        else {
            int u; cin >> u;
            pb.clear();
            memset(vit, false, (n + 1) * sizeof(bool));
            cnt_color(u);
            pb.insert(color[u]);
            cout << pb.size() << '\n';
        }
    }

    return 0;
}
