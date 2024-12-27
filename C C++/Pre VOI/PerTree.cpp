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
const int N = (int) 5e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, par[N], gift[N];

void add(ll &x, ll y) {
    x += y;
    x -= ((x >= MOD) ? MOD : 0);
}

namespace sub1 {

    bool check_dk(void) {
        return (n <= 10);
    }

    bool tt[N], check[N];
    ll ans[N];

    void backtrack(vec(int) luu) {
        if (!luu.empty()) {
            memset(check, false, (n + 1) * sizeof(bool));
            check[0] = true;
            bool ok = true;
            for (int x : luu) {
                if (!check[par[x]]) {
                    ok = false;
                    break;
                }
                else
                    check[x] = true;
            }
            if (!ok) return;
        }

        if (luu.size() == n) {
            memset(check, false, (n + 1) * sizeof(bool));
            check[0] = true;
            bool ok = true;
            for (int x : luu) {
                if (!check[par[x]]) {
                    ok = false;
                    break;
                }
                else
                    check[x] = true;
            }

            if (ok) Rep(i, luu.size())
                add(ans[luu[i]], gift[i + 1]);

            return;
        }

        For(i, 1, n, 1) if (!tt[i]) {
            tt[i] = true;
            luu.pub(i);
            backtrack(luu);
            luu.pb();
            tt[i] = false;
        }
    }

    void solve(void) {
        vec(int) tmp;
        backtrack(tmp);
        For(i, 1, n, 1) cout << ans[i] << " ";
    }
}

namespace sub2 {

    int cnt[N];
    ll gt[N], dp[N][N], ans[N];

    ll ltbinary(ll a, ll b) {
        a %= MOD; ll res = 1;
        while (b) {
            if (b & 1) res = ((res % MOD) * (a % MOD)) % MOD;
            a = ((a % MOD) * (a % MOD)) % MOD;
            b >>= 1;
        }
        return (res % MOD);
    }

    void init(void) {
        gt[0] = 1;
        For(i, 1, n, 1) gt[i] = gt[i - 1] * i % MOD;
        Ford(i, n, 1, 1) { ++cnt[i]; cnt[par[i]] += cnt[i]; }
    }

    void solve(void) {
        init();
        dp[1][1] = n;
        ans[1] = gift[1] * gt[n] % MOD;
        For(i, 2, n, 1) {
            For(j, 1, n, 1) dp[i][j] = (dp[par[i]][j] + dp[i][j - 1] * (n - cnt[i] - j + 1) % MOD) % MOD;
            Ford(j, n, 1, 1) {
                dp[i][j] = dp[i][j - 1] * cnt[i] % MOD;
                add(ans[i], dp[i][j] * gt[n - j] % MOD * gift[j] % MOD);
            }
        }

        /*For(i, 1, n, 1) cout << gt[i] << " ";
        cout << '\n';
        For(i, 1, n, 1) cout << cnt[i] << " ";
        cout << '\n';
        For(i, 1, n, 1) {
            For(j, 1, n, 1) cout << dp[i][j] << " ";
            cout << '\n';
        }
        For(i, 1, n, 1) cout << ans[i] << " ";
        cout << '\n';*/

        ll tmp = 1;
        For(i, 1, n, 1) tmp = tmp * cnt[i] % MOD;
        //cout << tmp << '\n';
        tmp = ltbinary(tmp, MOD - 2);

        //cout << tmp << '\n';

        For(i, 1, n, 1) cout << ans[i] * tmp % MOD << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    par[1] = 0;
    For(i, 2, n, 1) cin >> par[i];
    For(i, 1, n, 1) cin >> gift[i];

    if (sub1::check_dk()) sub1::solve();
    else sub2::solve();

    return 0;
}
