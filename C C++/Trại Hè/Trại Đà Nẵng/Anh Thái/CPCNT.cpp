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
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int tcase, n, m;
ll mobi[N + 7], phi[N + 7], pre[N + 7], pree[N + 7];

void init(void) {
    //Subtask 1
    mobi[1] = 1;
    For(i, 1, N, 1) For(j, 2 * i, N, i)
        mobi[j] -= mobi[i];

    //Subtask 2
    For(i, 1, N, 1) phi[i] = i;
    For(i, 2, N, 1) if (phi[i] == i) For(j, i, N, i)
        phi[j] -= phi[j] / i;
    pre[0] = 0;
    For(i, 1, N, 1) pre[i] = pre[i - 1] + phi[i];

    //Subtask 3
    pree[0] = 0;
    For(i, 1, N, 1) pree[i] = pree[i - 1] + mobi[i];
}

void sub1(void) {
    ll ans = 0;
    For(i, 1, n, 1) ans += (n / i) * (m / i) * mobi[i];
    cout << ans << '\n';
}

void sub2(void) {
    cout << pre[n] * 2ll - 1ll << '\n';
}

void sub3(void) {
    /*ll ans = 0;
    for (int i = 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        ans += n / i * (n / i - 1) / 2ll * ((n / i) * mobi[i]);
    }
    for (int i = 1, j; i <= m; i = j + 1) {
        j = m / (m / i);
        ans += m / i * (m / i - 1) / 2ll * ((m / i) * mobi[i]);
    }
    cout << ans << '\n';*/
    if (n > m) swap(n, m);
    ll ans = 0;
    for (ll i = 1, j; i <= n; i = j + 1) {
        ll tmp1 = n / i, tmp2 = m / i;
        j = min({1ll * n, n / tmp1, m / tmp2});
        ans += tmp1 * tmp2 * (pree[j] - pree[i - 1]);
    }
    cout << ans << '\n';
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

    init();

    cin >> tcase;
    Rep(test_case, tcase) {
        cin >> n >> m;

        if (n <= 1e3 && m <= 1e3)
            sub1();
        else if (n == m)
            sub2();
        else
            sub3();
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
