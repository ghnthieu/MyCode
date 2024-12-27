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
const int INF = (int) 1e9 + 7;
const ll oo = (ll) 1e18 + 7;
const int N = (int) 5e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, k, a[N], b[N];
ll dp[N];

void sub2(void) {
    ll ans = oo;
    For(i, 1, n, 1) {
        For(j, 1, n + 1, 1) dp[j] = INF; dp[0] = 0;
        For(j, 1, n + 1, 1) {
            if (a[j] > a[i]) continue;
            For(ij, max(0, j - k), j - 1, 1)
                minimize(dp[j], max(dp[ij], 1ll * b[j]));
        }
        //For(j, 1, n + 1, 1) cout << dp[j] << " ";
        //cout << '\n';
        minimize(ans, 1ll * dp[n + 1] * a[i]);
    }
    cout << ans;
}

void sub3(void) {
    ll ans = oo;
    For(i, 1, n, 1) {
        For(j, 1, n + 1, 1) dp[j] = INF; dp[0] = 0;
        deque <int> dq; dq.pub(0);
        For(j, 1, n + 1, 1) {
            if (a[j] > a[i]) continue;
            while (!dq.empty() && dq.fr() < j - k) dq.pf();
            if (!dq.empty()) dp[j] = max(dp[dq.fr()], 1ll * b[j]);
            while (!dq.empty() && dp[dq.bk()] >= dp[j]) dq.pb();
            dq.pub(j);
        }
        //For(j, 1, n + 1, 1) cout << dp[j] << " ";
        //cout << '\n';
        minimize(ans, 1ll * dp[n + 1] * a[i]);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("mnjump.inp", "r", stdin);
    freopen("mnjump.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> k;
    bool check_sub2 = true;
    For(i, 1, n, 1) {
        cin >> a[i] >> b[i];
        if (a[i] > 1e2) check_sub2 = false;
    }

    if (n <= 1e2 && check_sub2)
        sub2();
    else
        sub3();

    return 0;
}
