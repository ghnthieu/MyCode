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
const int N = (int) 2e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, a[N];

void sub1(void) {
    int ans = 0;
    For(l, 1, n, 1) {
        map <int, int> cnt; int mx = 0, sl = 0;
        For(r, l, n, 1) {
            ++cnt[a[r]];
            if (maximize(mx, cnt[a[r]]))
                sl = 1;
            else if (cnt[a[r]] == mx)
                ++sl;
            if (sl == cnt.size())
                ++ans;
        }
    }
    cout << ans;
}

int pre[N][21];

void sub2(void) {
    For(i, 1, n, 1) {
        For(j, 1, 20, 1) pre[i][j] = pre[i - 1][j];
        ++pre[i][a[i]];
    }

    For(i, 1, 20, 1) {
        For(j, 1, n, 1) cout << pre[j][i] << " ";
        cout << '\n';
    }
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

    cin >> n;
    For(i, 1, n, 1) cin >> a[i];


    if (n <= 2000)
        sub1();
    else
        sub2();

    return 0;
}
