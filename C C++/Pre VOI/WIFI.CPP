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
const int N = (int) 2e5 + 7;

int n;

struct Data {
    ll x, y, r;
} a[N];

namespace sub1 {

    bool check_dk(void) {
        return (n <= 10);
    }

    bool tt[N];

    void solve(void) {
        int ans = INT_MAX;
        For(k, 0, mask(n) - 1, 1) {
            memset(tt, false, (n + 1) * sizeof(bool));
            Rep(i, n) if (bit(k, i)) {
                tt[i + 1] = true;
                For(j, 1, n, 1) if (i + 1 != j) if (sqrt((a[i + 1].x - a[j].x) * (a[i + 1].x - a[j].x) + (a[i + 1].y - a[j].y) * (a[i + 1].y - a[j].y)) <= a[i + 1].r)
                    tt[j] = true;
            }
            bool check = true;
            For(i, 1, n, 1) if (!tt[i]) {
                check = false;
                break;
            }
            if (check) {
                int cnt = 0;
                Rep(i, n) if (bit(k, i))
                    ++cnt;
                minimize(ans, cnt);
            }
        }
        cout << ans;
    }
}

namespace sub2 {

    vec(int) inp[N];

    int calc(Data x, Data y) {
        return (sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y)));
    }

    void init(void) {
        For(i, 1, n, 1) For(j, 1, n, 1) if (i != j) if (calc(a[i], a[j]) <= a[i].r)
            inp[i].pub(j);
    }

    int low[N], num[N], tid[N], cnt = 0, tpltm = 0;
    stack <int> st;

    void dfs(int u) {
        low[u] = num[u] = ++cnt; st.push(u);
        for (int v : inp[u]) if (!tid[v]) {
            if (!num[v]) {
                dfs(v);
                minimize(low[u], low[v]);
            }
            else minimize(low[u], num[v]);
        }
        if (low[u] == num[u]) {
            ++tpltm; int v = 0;
            do {
                v = st.top(); st.pop();
                tid[v] = tpltm;
            } while (v != u);
        }
    }

    vec(int) new_inp[N]; int dag[N];

    void solve(void) {
        init();
        For(i, 1, n, 1) if (!num[i])
            dfs(i);
        For(i, 1, n, 1) if (!inp[i].empty()) for (int x : inp[i]) if (tid[x] != tid[i]) {
            new_inp[tid[i]].pub(tid[x]);
            ++dag[tid[x]];
        }

        int ans = 0;
        For(i, 1, tpltm, 1) if (dag[i] == 0)
            ++ans;
        cout << ans;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("WIFI.INP", "r", stdin);
    freopen("WIFI.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) cin >> a[i].x >> a[i].y >> a[i].r;

    if (sub1::check_dk()) sub1::solve();
    else sub2::solve();

    //sub2::solve();

    return 0;
}
