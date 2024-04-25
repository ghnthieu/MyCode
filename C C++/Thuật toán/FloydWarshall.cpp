#include <bits/stdc++.h>
using namespace std;

#define NAME ""
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
const int MOD = (int) 1e9 + 7;
const int N = (int) 5e2 + 7;

int n, m, q, inp[N][N], trance[N][N];
ll duong[N][N];

void FloydWarshall(void) {
    memset(duong, 0x3f, sizeof(duong));
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (inp[i][j] < MOD)
                duong[i][j] = inp[i][j];
        }
    }
    for (int i=1; i<=n; ++i)
        duong[i][i] = 0;
    for (int k=1; k<=n; ++k) {
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j)
                minimize(duong[i][j], duong[i][k] + duong[k][j]);
        }
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (i != j) {
                trance[i][j] = -1;
                for (int k=1; k<=n; ++k) {
                    if (k != j && duong[i][k] + inp[k][j] == duong[i][j]) {
                        if (trance[i][j] < 0 || inp[trance[i][j]][j] > inp[k][j])
                            trance[i][j] = k;
                    }
                }
            }
        }
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> n >> m >> q;
    memset(inp, 0x3f, sizeof(inp));
    for (int i=1; i<=m; ++i) {
        int x, y, w; cin >> x >> y >> w;
        minimize(inp[x][y], w);
        minimize(inp[y][x], w);
    }

    FloydWarshall();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
