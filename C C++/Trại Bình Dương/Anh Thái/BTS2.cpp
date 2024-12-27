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
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, k, low[N], num[N], tid[N], cnt = 0, tpltm = 0;
stack <int> st;
vec(int) inp[N];
ii(int, int) edge[N];

void dfs(int u) {
    low[u] = num[u] = ++cnt;
    st.push(u);
    for (int v : inp[u]) if (!tid[v]) {
        if (!num[v]) {
            dfs(v);
            minimize(low[u], low[v]);
        }
        else
            minimize(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        ++tpltm;
        int v = 0;
        do {
            v = st.top(); st.pop();
            tid[v] = tpltm;
        } while (u != v);
    }
}

int cntt[N];

void solve(void) {
    ll ans = 0;
    For(i, 1, n - 1, 1) {
        memset(low, 0, (n + 1) * sizeof(int));
        memset(num, 0, (n + 1) * sizeof(int));
        memset(tid, 0, (n + 1) * sizeof(int));
        memset(cntt, 0, (n + 1) * sizeof(int));
        cnt = 0; tpltm = 0; while (!st.empty()) st.pop();
        For(j, 1, n, 1) inp[j].clear();
        For(j, 1, n - 1, 1) if (j != i) {
            int u = edge[j].fi, v = edge[j].se;
            inp[u].pub(v);
            inp[v].pub(u);
        }
        For(j, 1, n, 1) if (!num[j])
            dfs(j);
        For(j, 1, n, 1) ++cntt[tid[j]];
        For(j, 1, n, 1) ans += 1ll * cntt[j] * cntt[j];
        //For(j, 1, n, 1) cout << tid[j] << " ";
        //cout << '\n';
    }
    cout << ans;
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

    cin >> n >> k;
    For(i, 1, n - 1, 1) cin >> edge[i].fi >> edge[i].se;

    if (k == 1)
        solve();
    else if (k == n - 1)
        cout << n;

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
