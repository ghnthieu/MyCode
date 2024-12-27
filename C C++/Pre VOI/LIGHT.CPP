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
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

struct Data {
    int v, sec, leng;
};

int n, q, k, trace[N];
vec(Data) inp[N];
ll duong[N];
vec(int) luu;
map <ii(int, int), ii(int, int)> edge;
vii(int, int) edgee;

void dijkstra(int s, int t) {
    memset(duong, 0x3f, (n + 1) * sizeof(ll)); duong[s] = 0;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq; pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se]) continue;
        for (Data v : inp[u.se]) if (minimize(duong[v.v], duong[u.se] + 1)) {
            pq.push({duong[v.v], v.v});
            trace[v.v] = u.se;
        }
    }
    luu.clear();
    do {
        luu.pub(t);
        t = trace[t];
    } while (t != s);
    luu.pub(s);
    reverse(all(luu));
}

set <int> st;
map <int, bool> sec[N + 7];

bool check(int x) {
    int i = 0, canh = 0;
    while (i <= x) {
        int u = edgee[canh].fi, v = edgee[canh].se; int ck = edge[{u, v}].fi, timee = edge[{u, v}].se;
        if (sec[i][ck] == true) {
            i += timee;
            if (i <= x && canh == edgee.size() - 1)
                return true;
            else
                ++canh;
        }
        else ++i;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("LIGHT.INP", "r", stdin);
    freopen("LIGHT.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q >> k;
    For(i, 1, n - 1, 1) {
        int x, y, z; cin >> x >> y >> z;
        Data tmp; tmp.v = x; tmp.sec = y; tmp.leng = z;
        inp[i + 1].pub(tmp);
        tmp.v = i + 1;
        inp[x].pub(tmp);
        edge[{i + 1, x}] = {y, z};
        edge[{x, i + 1}] = {y, z};
        st.insert(y);
    }

    for (auto x : st) {
        ll sum = 0; bool check = true;
        int i = 0;
        while (i <= N) {
            if (check) {
                int tmp = x;
                while (tmp-- && i <= N) {
                    sec[i][x] = check;
                    ++i;
                }
                check = false;
            }
            else {
                int tmp = k - x;
                while (tmp-- && i <= N) {
                    sec[i][x] = check;
                    ++i;
                }
                check = true;
            }
        }
    }

    Rep(query, q) {
        int u, v; cin >> u >> v;
        dijkstra(u, v);
        edgee.clear();
        Rep(i, luu.size() - 1) edgee.pub({luu[i], luu[i + 1]});
        //cout << u << " " << v << '\n';
        //for (ii(int, int) x : edgee) cout << x.fi << " " << x.se << '\n';
        //cout << '\n';
        int l = 1, r = N, ans = N + 1;
        while (l <= r) {
            int m = l + r >> 1;
            if (check(m)) {
                minimize(ans, m);
                r = m - 1;
            }
            else
                l = m + 1;
        }
        cout << ans << '\n';
    }

    return 0;
}
