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
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, k;
vec(string) luu;
bool tt[N];

void sinh_th(string tmp) {
    if ((int) tmp.length() == n) {
        luu.pub(tmp);
        return;
    }

    For(i, 1, n, 1) if (!tt[i]) {
        string afters = tmp;
        tt[i] = true;
        tmp += to_string(i);
        sinh_th(tmp);
        tmp = afters;
        tt[i] = false;
    }
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void sub1(void) {
    string tmp = "";
    sinh_th(tmp);
    //for (string x : luu) cout << x << '\n';
    Rep(i, luu.size()) {
        int cnt = 0;
        Rep(j, n) if (gcd(luu[i][j] - '0', j + 1) == 1)
            ++cnt;
        if (cnt == k) {
            Rep(j, n) cout << luu[i][j] << " ";
            return;
        }
    }
}

void sub2(void) {
    For(i, 1, k - 1, 1) cout << i + 1 << " ";
    cout << 1 << " ";
    For(i, k + 1, n, 1) cout << i << " ";
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".INP", "r", stdin);
    //freopen(".OUT", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> k;

    if (n <= 10)
        sub1();
    else
        sub2();

    return 0;
}
