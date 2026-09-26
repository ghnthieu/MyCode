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
const int N = (int) 1e3 + 7;
const int M = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n;
ll a[N];

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void sub1(void) {
    int ans = 0;
    For(k, 1, mask(n) - 1, 1) {
        ll tmp = -1;
        Rep(i, n) if (bit(k, i)) {
            if (tmp == -1)
                tmp = a[i + 1];
            else
                tmp = gcd(tmp, a[i + 1]);
        }
        if (tmp > 1) maximize(ans, __builtin_popcountll(k));
    }
    cout << ans;
}

ll cnt[M], cnt_div[M];

void sub2(void) {
    For(i, 2, M - 7, 1) For(j, i, M - 7, i) cnt_div[i] += cnt[j];

    ll ans = 0;
    For(i, 2, M - 7, 1) maximize(ans, cnt_div[i]);
    cout << ans;
}

void sub3(void) {

}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("gcd.inp", "r", stdin);
    //freopen("gcd.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);


    cin >> n;
    bool check_sub2 = true;
    For(i, 1, n, 1) {
        cin >> a[i]; if (a[i] <= 1e6) ++cnt[a[i]];
        if (a[i] > 1e6) check_sub2 = false;
    }

    if (n <= 18)
        sub1();
    else if (check_sub2)
        sub2();
    else
        sub3();

    return 0;
}
