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
const int N = (int) 1e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, k, ans = INT_MAX;
bool have_change[N][N], vit[N][N];

// 0 = -> ; 1 = <- ; 2 = ^ ; 3 = v

void solve(int i, int j, int huong, int cnt) {
    cout << i << " " << j << " " << huong << " " << cnt << '\n';
    if (i < 1 || i > n || j < 1 || j > m) return;

    if (i == n && j == m && huong == 0) {
        minimize(ans, cnt);
        return;
    }

    if (have_change[i][j]) {
        solve(i, j, 0, cnt + 1);
        solve(i, j, 1, cnt + 1);
        solve(i, j, 2, cnt + 1);
        solve(i, j, 3, cnt + 1);
    }

    /*if (huong == 0 && j <= m - 1 && !vit[i][j + 1]) {
        vit[i][j + 1] = true;
        solve(i, j + 1, huong, cnt);
        vit[i][j + 1] = false;
    }
    else if (huong == 1 && j >= 2 && !vit[i][j - 1]) {
        vit[i][j - 1] = true;
        solve(i, j - 1, huong, cnt);
        vit[i][j - 1] = false;
    }
    else if (huong == 2 && i >= 2 && !vit[i - 1][j]) {
        vit[i - 1][j] = true;
        solve(i - 1, j, huong, cnt);
        vit[i - 1][j] = false;
    }
    else if (i <= n - 1 && !vit[i + 1][j]) {
        vit[i + 1][j] = true;
        solve(i + 1, j, huong, cnt);
        vit[i + 1][j] = false;
    }*/
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> k;
    Rep(change, k) {
        int x, y; cin >> x >> y;
        have_change[x][y] = true;
    }

    solve(1, 1, 0, 0);
    cout << ((ans != INT_MAX) ? ans : (-1));

    return 0;
}
