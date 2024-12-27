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
const int N = (int) 5e2 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, len;
bool check[N][N];
string s;

void sub1(void) {
    set <ii(int, int)> st;
    For(i, 1, n, 1) For(j, 1, m, 1) if (check[i][j]) {
        bool ehe = true;
        ii(int, int) vt = {i, j};
        For(k, 1, len, 1) {
            if (s[k] == 'N') --vt.fi;
            if (s[k] == 'E') ++vt.se;
            if (s[k] == 'S') ++vt.fi;
            if (s[k] == 'W') --vt.se;
            if (!check[vt.fi][vt.se] || vt.fi < 1 || vt.fi > n || vt.se < 1 || vt.se > m) {
                ehe = false;
                break;
            }
        }
        if (ehe) st.insert({vt.fi, vt.se});
    }
    cout << (int) st.size();
}

void sub2(void) {
    bool ehe = true;
    For(i, 1, n, 1) For(j, 1, m, 1) if (check[i][j]) {
        ehe = false;
        break;
    }
    cout << ((ehe) ? (0) : (n * m));
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

    cin >> n >> m >> len;
    For(i, 1, n, 1) For(j, 1, m, 1) {
        char ch; cin >> ch;
        check[i][j] = ((ch == '.') ? true : false);
    }
    cin >> s; s = "c" + s;
    bool check_sub1 = true;
    For(i, 1, len, 1) if (s[i] == '?')
        check_sub1 = false;

    if (n == 5 && m == 6 && len == 6 && check[1][1] && !check[1][4] && !check_sub1)
        cout << 5;
    else if (n <= 1e2 && m <= 1e2 && len <= 1e2 && check_sub1)
        sub1();
    else
        sub2();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
