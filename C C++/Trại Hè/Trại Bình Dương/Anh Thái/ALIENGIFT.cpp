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

ii(int, int) a_key[N];
int n, a_gf[N][4];
ll sum_gf[N][mask(4)], dp[N][mask(4)];
vec(int) thom, luu[mask(4)];

void init(void) {
    For(i, 0, mask(4) - 1, 1) {
        bool check = true;
        Rep(j, 3) if (bit(i, j) && bit(i, j + 1)) {
            check = false;
            break;
        }
        if (check) thom.pub(i);
    }

    For(i, 1, n, 1) for (int j : thom) {
        ll sum = 0;
        Rep(k, 4) if (bit(j, k))
            sum += a_gf[i][k];
        sum_gf[i][j] = sum;
    }

    for (int i : thom) for (int j : thom) {
        bool check = true;
        Rep(k, 4) if (bit(i, k) && bit(j, k)) {
            check = false;
            break;
        }
        if (check) {
            luu[i].pub(j);
            luu[j].pub(i);
        }
    }
}

void sub1(void) {
    init();
    memset(dp, -0x3f, sizeof(dp));
    for (int x : thom) if (x != 0) dp[1][x] = sum_gf[1][x];
    For(i, 2, n, 1) For(j, 1, i - 1, 1) {
        if (a_key[j].fi + j <= i && i <= a_key[j].se + j) for (int k : thom) for (int tk : luu[k])
            maximize(dp[i][tk], dp[j][k] + sum_gf[i][tk]);
    }
    ll ans = 0;
    For(i, 1, n, 1) if (a_key[i].fi + i > n || a_key[i].se + i > n) for (int x : thom)
        maximize(ans, dp[i][x]);
    cout << ans;
}

void sub2(void) {
    cout << 0;
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

    cin >> n;
    For(i, 1, n, 1) cin >> a_key[i].fi >> a_key[i].se >> a_gf[i][0] >> a_gf[i][1] >> a_gf[i][2] >> a_gf[i][3];

    //if (n <= 1e3)
        sub1();
    //else
    //    sub2();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
