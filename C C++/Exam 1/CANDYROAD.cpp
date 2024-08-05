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
const int MOD = (int) 998244353;
const int N = (int) 2e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

ll  n, m, cendy[N];

void add(ll &x, ll y) {
    x += y;
    x -= ((x >= MOD) ? MOD : 0);
    x += ((x < 0) ? MOD : 0);
}

vec(int) luu_idx[N];
map <int, int> idx;

void upp(ll &x) {
    x %= MOD;
    x += ((x < 0) ? MOD : 0);
}

void solve(void) {
    ll sum = m * (m + 1) % MOD * 499122177 % MOD;
    ll sum_pb = 0;
    For(i, 1, n, 1) {
        if (!idx[cendy[i]]) {
            idx[cendy[i]] = i;
            sum_pb += cendy[i];
        }
        luu_idx[idx[cendy[i]]].pub(i);
    }

    ll ans = 0;
    For(i, 1, n, 1) {
        add(ans, (sum - sum_pb) % MOD * (n - i + 1) % MOD);
        if (luu_idx[i].empty()) continue;
        add(ans, 1ll * (luu_idx[i][0] - 1) * luu_idx[i][0] % MOD * 499122177 % MOD * cendy[i] % MOD);
        Rep(j, luu_idx[i].size() - 1)
            add(ans, 1ll * (luu_idx[i][j + 1] - luu_idx[i][j]) * (luu_idx[i][j + 1] - luu_idx[i][j] - 1) % MOD * 499122177 % MOD * cendy[i] % MOD);
        add(ans, 1ll * (n - luu_idx[i].bk() + 1) * (n - luu_idx[i].bk()) % MOD * 499122177 % MOD * cendy[i] % MOD);
    }

    cout << ans % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("CANDYROAD.inp", "r", stdin);
    freopen("CANDYROAD.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    For(i, 1, n, 1) cin >> cendy[i];

    solve();

    return 0;
}
