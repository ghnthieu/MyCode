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
const int N = (int) 5e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q, cl[N];
bool have[N];

void sub1(void) {
    Rep(query, q) {
        int l, r; cin >> l >> r;
        int ans = 0;
        For(i, l, r, 1) if (have[i])
            ++ans;
        cout << ans << '\n';
    }
}

void sub2(void) {
    Rep(query, q) {
        int l, r; cin >> l >> r;
        int cnt = 0;
        For(i, l, r, 1) if (have[i])
            ++cnt;
        int ans = 0, i = l;
        while (i <= r) {
            if ((have[i] && cnt > 1) || (have[i] && cnt == 1 && i == r)) {
                ++ans; --cnt;
            }
            else if (have[i] && cnt == 1)
                break;
            else {
                while (!have[i]) ++i;
                --cnt;
            }
            ++i;
        }
        cout << ans << '\n';
    }
}

void sub3(void) {

}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("QSNAIL.INP", "r", stdin);
    freopen("QSNAIL.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    For(i, 1, n, 1) {
        char x; cin >> x;
        have[i] = ((x - '0' == 1) ? true : false);
    }
    bool check_sub1 = true, check_sub2 = true;
    For(i, 1, n, 1) {
        cin >> cl[i];
        if (cl[i] < 0) check_sub1 = false;
        if ((cl[i] != 0 && have[i]) || (cl[i] >= 0 && !have[i])) check_sub2 = false;
    }

    if (check_sub1 && n <= 8e4 && (q == 1 || q == 2))
        sub1();
    else if (check_sub2 && n <= 8e4 && (q == 1 || q == 2))
        sub2();
    else
        sub2();

    return 0;
}
