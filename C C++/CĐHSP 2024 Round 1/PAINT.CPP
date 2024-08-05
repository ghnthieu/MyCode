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
const int MOD = (int) 998244353;
const int N = (int) 7;
const int M = (int) 3628807;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, a[N], b[N], c[N][N], idx = 0;
vec(int) th[M];
bool check[2 * N];

void sinh_th(vec(int) luu) {
    if (luu.size() == 2 * n) {
        th[++idx] = luu;
        return;
    }

    For(i, 1, 2 * n, 1) {
        if (!check[i]) {
            check[i] = true;
            luu.pub(i);
            sinh_th(luu);
            luu.pb();
            check[i] = false;
        }
    }
}

int color[N][N];
bool check_used[N][N];

void sub1(void) {
    vec(int) tmp;
    sinh_th(tmp);

    int ans = 0;
    For(i, 1, idx, 1) {
        //Init - check
        memset(color, 0, sizeof(color));
        memset(check_used, false, sizeof(check_used));
        bool check_conti = true;
        for (int x : th[i]) { //Chi so cua lan lan hien tai <= n thi lan hang > n thi lan cot
            if (x <= n) For(j, 1, n, 1) {
                color[x][j] = a[x];
                if (color[x][j] != c[x][j] && check_used[x][j]) {
                    check_conti = false;
                    break;
                }
                check_used[x][j] = true;
            }
            else For(j, 1, n, 1) {
                color[j][x - n] = b[x - n];
                if (color[j][x - n] != c[j][x - n] && check_used[j][x - n]) {
                    check_conti = false;
                    break;
                }
                check_used[j][x - n] = true;
            }
            if (!check_conti) break;
        }

        //Calc
        ans += ((check_conti) ? 1 : 0);
        /*if (check_conti) {
            for (int x : th[i])
                cout << x << " ";
            cout << '\n';
        }*/
    }
    cout << ans;
}

void sub2(void) {}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("PAINT.INP", "r", stdin);
    freopen("PAINT.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) cin >> a[i];
    For(i, 1, n, 1) cin >> b[i];
    For(i, 1, n, 1) For(j, 1, n, 1) cin >> c[i][j];

    //if (n <= 5)
        sub1();
    //else
    //    sub2();

    //cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
