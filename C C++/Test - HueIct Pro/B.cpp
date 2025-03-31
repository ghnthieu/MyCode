#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb pop_back
#define pub push_back
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (long long i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (long long i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

ll l, r;

namespace sub1 {

    bool check_dk(void) {
        return (l <= 100 && r <= 100);
    }

    void solve(void) {
        ll ans = 0;
        For(i1, l, r, 1) For(i2, l, r, 1) For(i3, l, r, 1) For(i4, l, r, 1)
            ans = (ans + ((i1 ^ i2) ^ (i3 ^ i4))) % MOD;
        cout << ans;
    }

}

namespace sub2 {

    bool check_dk(void) {
        return (l <= 1000 && r <= 1000);
    }

    unordered_map <ll, ll> calc(ll l, ll r) {
        unordered_map <ll, ll> tmp;
        For(i, l, r, 1) For(j, l, r, 1)
            ++tmp[i ^ j];
        return tmp;
    }

    void solve(void) {
        unordered_map <ll, ll> tmp1 = calc(l, r);
        unordered_map <ll, ll> tmp2 = calc(l, r);
        ll ans = 0;
        for (auto &[x1, y1] : tmp1) for (auto &[x2, y2] : tmp2)
            ans = (ans + (x1 ^ x2) * (y1 % MOD) % MOD * (y2 % MOD) % MOD) % MOD;
        cout << ans;
    }

}

namespace sub34 {

    ll calc(ll n, ll i) {
        return ((n / mask(i + 1)) * mask(i) + max(0ll, n % mask(i + 1) - mask(i) + 1));
    }

    void solve(void) {
        ll ans = 0;
        Rep(i, 31) {
            ll cnt = calc(r, i) - calc(l - 1, i);
            ll tmp = r - l + 1 - cnt;
            ll tcnt = (((((cnt * tmp) % MOD) * tmp % MOD) * tmp) % MOD) * 4 % MOD;
            tcnt = (tcnt + ((((cnt * cnt) % MOD) * cnt % MOD) * tmp % MOD)  * 4 % MOD) % MOD;
            ans += mask(i) * tcnt; ans %= MOD;
        }
        cout << ans;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> l >> r;

    //if (sub1::check_dk()) sub1::solve();
    //else if (sub2::check_dk()) sub2::solve();
    //else sub34::solve();
    sub34::solve();

    return 0;
}
