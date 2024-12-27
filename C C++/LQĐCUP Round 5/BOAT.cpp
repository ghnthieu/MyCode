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
const int N = (int) 5e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, q, res = 0;
vec(int) inp[N];
ii(int, int) que[N];
bool tt[10007][10007];

ll dp1[N];

void sub1(void) {
    For(i, 1, n, 1) if (!inp[i].empty()) for (int x : inp[i]) {
        tt[i][x] = true;
        tt[x][i] = true;
    }

    For(i, 1, q, 1) dp1[i] = 1;
    For(i, 1, q, 1) {
        int u = que[i].fi, v = que[i].se;
        For(j, i + 1, q, 1) {
            int ut = que[j].fi, vt = que[j].se;
            if (tt[v][ut] || v == ut) maximize(dp1[j], dp1[i] + 1);
        }
    }

    ll ans = 0;
    For(i, 1, q, 1) maximize(ans, dp1[i]);
    cout << ans;
}

void sub2(void) {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BOAT.inp", "r", stdin);
    freopen("BOAT.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> q;
    For(i, 1, m, 1) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
    }
    For(i, 1, q, 1) cin >> que[i].fi >> que[i].se;

    if (n <= 1e4 && q <= 1e4)
        sub1();
    else
        sub2();

    return 0;
}
