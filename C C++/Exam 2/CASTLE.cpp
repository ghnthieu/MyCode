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

int n, m, high[N][N];

void sub1(void) {
    ll ans = 0;
    For(i1, 1, n, 1) For(j1, 1, m, 1) {
        For(i2, i1, n, 1) For(j2, j1, m, 1) {
            bool check = true;
            int ti1 = i1, ti2 = i2;
            while (ti1 <= ti2) {
                int tj1 = j1, tj2 = j2;
                while (tj1 <= tj2) {
                    if (high[ti1][tj1] != high[i1][j1]) {
                        check = false;
                        break;
                    }
                    if (high[ti1][tj2] != high[i1][j1]) {
                        check = false;
                        break;
                    }
                    if (high[ti2][tj1] != high[i1][j1]) {
                        check = false;
                        break;
                    }
                    if (high[ti2][tj2] != high[i1][j1]) {
                        check = false;
                        break;
                    }
                    ++tj1; --tj2;
                }
                if (!check) break;
                ++ti1; --ti2;
            }
            ans += ((check) ? 1 : 0);
        }
    }
    cout << ans;
}

void sub2(void) {}

void sub3(void) {}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("CASTLE.inp", "r", stdin);
    freopen("CASTLE.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    For(i, 1, n, 1) For(j, 1, m, 1) cin >> high[i][j];

    //if (n <= 50 && m <= 50)
        sub1();
    /*else if (n <= 5e2 && m <= 5e2)
        sub2();
    else
        sub3();*/

    return (0 ^ 0);
}
