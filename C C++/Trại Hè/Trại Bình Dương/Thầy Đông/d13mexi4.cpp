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
const int N = (int) 5e3 + 7;
const int M = (int) 5e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, a[N][N];
ll cnt[N];

int mex(int x, int y) {
    if ((x == 1 && y == 1) || (x == 1 && y == 2) || (x == 2 && y == 1) || (x == 2 && y == 2)) return 0;
    if ((x == 0 && y == 0) || (x == 0 && y == 2) || (x == 2 && y == 0)) return 1;
    if ((x == 1 && y == 0) || (x == 1 && y == 1)) return 2;
}

void sub1(void) {
    For(j, 1, n, 1) { cin >> a[1][j]; ++cnt[a[1][j]]; }
    For(i, 2, n, 1) { cin >> a[i][1]; ++cnt[a[i][1]]; }

    For(i, 2, n, 1) For(j, 2, n, 1) {
        a[i][j] = mex(a[i - 1][j], a[i][j - 1]);
        ++cnt[a[i][j]];
    }

    Rep(i, 3) cout << cnt[i] << " ";
}

vec(int) b[M];

void sub2(void) {
    For(i, 1, 10, 1) b[i].resize(M);
    For(i, 11, n, 1) b[i].resize(15);
    For(j, 1, n, 1) cin >> b[1][j];
    For(i, 2, n, 1) cin >> b[i][1];

    For(i, 2, 10, 1) For(j, 2, n, 1) b[i][j] = mex(b[i - 1][j], b[i][j - 1]);
    For(i, 2, n, 1) For(j, 2, 10, 1) b[i][j] = mex(b[i - 1][j], b[i][j - 1]);
    For(i, 1, 9, 1) For(j, 1, n, 1) ++cnt[b[i][j]];
    For(i, 10, n, 1) For(j, 1, 9, 1) ++cnt[b[i][j]];
    For(i, 10, n, 1) {
        int tmp = n - i + 1;
        cnt[b[i][10]] += tmp;
        cnt[b[10][i]] += tmp;
    }
    cnt[b[10][10]] -= n - 10 + 1;
    Rep(i, 3) cout << cnt[i] << " ";
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

    cin >> n;

    if (n <= 5e3)
        sub1();
    else
        sub2();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
