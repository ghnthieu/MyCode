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
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, a[N];

void sub1(void) {
    int ans = 0;
    For(i, 1, n, 1) For(j, i + 1, n, 1) For(k, j + 1, n, 1) {
        if ((a[i] == a[j] || a[i] == a[k] || a[j] == a[k]) && (a[i] + a[j] > a[k]) && (a[i] + a[k] > a[j]) && (a[j] + a[k] > a[i]))
            ++ans;
    }
    cout << ans;
}

vii(int, int) luu;

int get(int val) {
    int l = 1, r = n, res = 0;
    while (l <= r) {
        int m = l + r >> 1;
        if (a[m] < val) {
            res = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return res;
}

void sub2(void) {
    sort(a + 1, a + n + 1);
    luu.pub({1, 1});
    For(i, 2, n, 1) {
        if (a[i] == a[i - 1])
            luu.bk().se = i;
        else
            luu.pub({i, i});
    }

    ll ans = 0;
    for (ii(int, int) x : luu) {
        if (x.fi != x.se) {
            ans += 1ll * (x.se - x.fi) * (x.se - x.fi + 1) * (x.fi - 1)  / 2;
            ans += 1ll * (x.se - x.fi) * (x.se - x.fi + 1) * (x.se - x.fi - 1) / 6;
            ans += 1ll * (get(a[x.se] * 2) - x.se) * (x.se - x.fi + 1) * (x.se - x.fi) / 2;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("STICK.inp", "r", stdin);
    freopen("STICK.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) cin >> a[i];

    if (n <= 5e2)
        sub1();
    else
        sub2();

    return 0;
}
