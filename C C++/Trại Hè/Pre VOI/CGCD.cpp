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

int n, m;
ll mobi[N + 7], phi[N + 7], pre[N + 7], pree[N + 7];

void init(void) {
    //Subtask 0
    mobi[1] = 1;
    For(i, 1, N, 1) For(j, 2 * i, N, i)
        mobi[j] -= mobi[i];

    //Subtask 1
    For(i, 1, N, 1) phi[i] = i;
    For(i, 2, N, 1) if (phi[i] == i) For(j, i, N, i)
        phi[j] -= phi[j] / i;
    pre[0] = 0;
    For(i, 1, N, 1) pre[i] = pre[i - 1] + phi[i];

    //Subtask 2
    pree[0] = 0;
    For(i, 1, N, 1) pree[i] = pree[i - 1] + mobi[i];
}

void sub0(void) {
    ll ans = 0;
    For(i, 1, n, 1) ans += (n / i) * (m / i) * mobi[i];
    cout << ans << '\n';
}

void sub1(void) {
    cout << pre[n] * 2ll - 1ll << '\n';
}

void sub2(void) {
    if (n > m) swap(n, m);
    ll ans = 0;
    for (ll i = 1, j; i <= n; i = j + 1) {
        ll tmp1 = n / i, tmp2 = m / i;
        j = min({1ll * n, n / tmp1, m / tmp2});
        ans += tmp1 * tmp2 * (pree[j] - pree[i - 1]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("CGCD.INP", "r", stdin);
    freopen("CGCD.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    init();

    cin >> n >> m;

    if (n <= 1e3 && m <= 1e3)
        sub0();
    else if (n == m)
        sub1();
    else
        sub2();

    return 0;
}
