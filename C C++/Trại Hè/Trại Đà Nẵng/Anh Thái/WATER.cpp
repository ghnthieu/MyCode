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
const int N = (int) 4e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, pw[N], luu[N], rmq[N][27];
ii(int, int) a[N];

void init(void) {
    m *= 2;
    For(i, 1, m / 2, 1) {
        a[m / 2 + i].fi = a[i].fi + n;
        a[m / 2 + i].se = a[i].se + n;
    }
    sort(a + 1, a + m + 1);
    pw[0] = 1;
    For(i, 1, 17, 1) pw[i] = pw[i - 1] * 2;
    For(i, 1, m, 1) luu[a[i].fi] = max(luu[a[i - 1].fi], a[i].se);
    For(i, 1, 2 * n, 1) {
        maximize(luu[i], luu[i - 1]);
        maximize(luu[i], luu[i + 1]);
    }
    For(i, 1, 2 * n, 1) rmq[i][0] = max(luu[i], i);
    For(j, 1, 17, 1) For(i, 1, 2 * n, 1) {
        rmq[i][j] = rmq[rmq[i][j - 1]][j - 1];
        rmq[i][j] = max(rmq[i][j], rmq[i][j - 1]);
        rmq[i][j] = max(rmq[i][j], i);
    }
}

int find_rmq(int x, int y) {
    x = a[x].se; --y;
    int res = x;
    Ford(i, 17, 0, 1) if (pw[i] <= y) {
        x = rmq[x][i];
        y -= pw[i];
        maximize(res, x);
    }
    return res;
}

bool check(int x) {
    For(i, 1, m, 1) if (n <= find_rmq(i, x) - a[i].fi + 1)
        return true;
    return false;
}

void solve(void) {
    init();
    int l = 1, r = m, res = INT_MAX;
    while (l <= r) {
        int m = l + r >> 1;
        if (check(m)) {
            minimize(res, m);
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ((res == INT_MAX) ? (-1) : (m / 2 - res));
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

    cin >> n >> m;
    For(i, 1, m, 1) {
        cin >> a[i].fi >> a[i].se;
        if (a[i].fi > a[i].se) a[i].se += n;
    }

    if (m <= 5e3)
        solve();
    else
        cout << -1;

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
