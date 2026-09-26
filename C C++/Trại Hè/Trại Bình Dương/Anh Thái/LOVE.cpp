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
const int INF = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

struct Data {
    int u, v, day;
};

int n, m;
vec(Data) edge;
vec(int) inp[N];
bool vit[N];

bool cmp(Data a, Data b) {
    return (a.day < b.day);
}

void dfs(int u) {
    vit[u] = true;
    for (int v : inp[u]) if (!vit[v])
        dfs(v);
}

bool check(int val) {
    For(i, 1, n, 1) inp[i].clear();
    for (Data x : edge) {
        if (x.day > val) break;
        inp[x.u].pub(x.v);
        inp[x.v].pub(x.u);
    }
    memset(vit, false, (n + 1) * sizeof(bool));
    dfs(1);
    return vit[n];
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    For(i, 1, m, 1) {
        Data x; cin >> x.u >> x.v >> x.day;
        edge.pub(x);
    }
    sort(all(edge), cmp);

    int l = 1, r = 1e9, ans = INF;
    while (l <= r) {
        int m = l + r >> 1;
        if (check(m)) {
            minimize(ans, m);
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ans;

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
