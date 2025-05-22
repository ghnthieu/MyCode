#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb pop_back
#define pub push_back
#define __Trung_Hieu___ signed main()
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (long long i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int x;
ll m;

void sub1(void) {
    int cnt = 0, tx = x;
    while (tx) { ++cnt; tx /= 10; }
    ll mod = 1;
    while (cnt) { mod *= 10ll; --cnt; }

    int ans = 0;
    For(i, 1, m, 1) if (i != x && i % mod == x) {
        //cout << i << " ";
        ++ans;
    }
    cout << ans;
}

void sub2(void) {
    int cnt_x = 0, tx = x;
    while (tx) { ++cnt_x; tx /= 10; }
    int cnt_m = 0; ll tm = m;
    while (tm) { ++cnt_m; tm /= 10; }
    int cnt = cnt_x; ll mod = 1;
    while (cnt) { mod *= 10ll; --cnt; }

    if (cnt_x >= cnt_m)
        cout << 0;
    else {
        if (m % mod >= x && cnt_x != cnt_m)
            cout << m / mod;
        else if (m % mod >= x && cnt_x == cnt_m)
            cout << 0;
        else {
            string s = to_string(m);
            vec(int) luu;
            bool check = true;
            Ford(i, s.length() - cnt_x - 1, 0, 1) {
                if (s[i] != '0' && check) {
                    check = false;
                    if (s[i] - '0' - 1 != 0) luu.pub(s[i] - '0' - 1);
                }
                else if (s[i] == '0' && check)
                    luu.pub(9);
                else
                    luu.pub(s[i] - '0');
            }
            reverse(all(luu)); for (int x : luu) cout << x;
        }
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("LIKENUM.INP", "r", stdin);
    freopen("LIKENUM.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> x >> m;

    if (m <= 1e5)
        sub1();
    else
        sub2();

    return 0;
}
