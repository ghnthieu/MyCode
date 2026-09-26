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
const int MOD = (int) 1e9;
const int N = (int) 1e3 + 7;
const int M = (int) 1e6 + 7;

int n, m, k, q, cnt[M];
ll ans[M];
bool cam[N][N];
vec(int) inp[M], stopo;
int dx[4] = {1, -2, -1, -2},
    dy[4] = {-2, 1, -2, -1};

void add(ll &a, ll b) {
    a += b;
    a -= ((a >= MOD) ? MOD : 1ll * 0);
}

void solve(void) {
    for (int i=n; i>=1; --i) {
        for (int j=m; j>=1; --j) {
            int idx1 = (i - 1) * m + j;
            for (int k=0; k<4; ++k) {
                int it = i + dx[k],
                    jt = j + dy[k];
                int idx2 = (it - 1) * m + jt;
                if (it >= 1 && it <= n && jt >= 1 && jt <= m && !cam[it][jt])
                    inp[idx1].pub(idx2);
            }
        }
    }
    for (int u=1; u<=n*m; ++u) {
        for (int v : inp[u])
            ++cnt[v];
    }



    queue <int> tlist;
    for (int i=1; i<=n*m; ++i) {
        if (!cnt[i])
            tlist.push(i);
    }
    while (!tlist.empty()) {
        int u = tlist.fr(); tlist.pop();
        stopo.pub(u);
        for (int v : inp[u]) {
            if (--cnt[v] == 0)
                tlist.push(v);
        }
    }

    ans[n * m] = 1;
    for (int u : stopo) {
        for (int v : inp[u])
            add(ans[v], ans[u]);
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> n >> m >> k >> q;
    for (int i=1; i<=k; ++i) {
        int x, y; cin >> x >> y;
        cam[x][y] = true;
    }

    solve();

    while (q--) {
        int x, y; cin >> x >> y;
        cout << ans[(x - 1) * m + y] << '\n';
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
