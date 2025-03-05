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

string s;

void manacher(string st) {
    int len = st.length();
    if (len == 0) return;
    len = 2 * len + 1;

    int left[len]; left[0] = 0; left[1] = 1;
    int mid = 1, right = 2;
    int imirror, expand = -1, diff = -1, max_len = 0, max_mid = 0, start = -1, end = -1;
    For(i, 2, len - 1, 1) {
        imirror = 2 * mid - i; expand = 0; diff = right - i;
        if (diff >= 0) {
            if (left[imirror] < diff) left[i] = left[imirror];
            else if (left[imirror] == diff && right == len - 1)
                left[i] = left[imirror];
            else if (left[imirror] == diff && right < len - 1) {
                left[i] = left[imirror];
                expand = 1;
            }
            else if (left[imirror] > diff) {
                left[i] = diff;
                expand = 1;
            }
        }
        else {
            left[i] = 0;
            expand = 1;
        }

        if (expand == 1) {
            while (((i + left[i]) < len && (i - left[i]) > 0) && (((i + left[i] + 1) % 2 == 0) || (st[(i + left[i] + 1) / 2] == st[(i - left[i] - 1) / 2])))
                ++left[i];
        }

        if (maximize(max_len, left[i])) max_mid = i;
        if (i + left[i] > right) {
            mid = i;
            right = i + left[i];
        }
    }

    start = (max_mid - max_len) / 2; end = start + max_len - 1;
    For(i, start, end, 1) cout << st[i];
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> s;
    manacher(s);

    return 0;
}
