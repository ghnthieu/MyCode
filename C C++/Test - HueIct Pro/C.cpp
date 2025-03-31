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

int n, l, r, k, a[N];

bool check(int x) {
    int cnt = 0, sum_bo = 0, sum_kv = 0;
    deque <ii(int, int)> dq;
    For(i, 1, n, 1) {
        sum_bo += a[i]; ++sum_kv;
        dq.pub({a[i], 1});
        while (sum_kv > r) {
            sum_bo -= dq.front().fi;
            sum_kv -= dq.front().se;
            dq.pop_front();
        }
        if (l <= sum_kv && sum_bo / sum_kv >= x) {
            ++cnt; sum_bo = 0; sum_kv = 0;
            dq.clear();
        }
    }
    return (cnt >= k);
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

    cin >> n >> l >> r >> k;
    int mx = 0;
    For(i, 1, n, 1) cin >> a[i], maximize(mx, a[i]);
    int l = 0, r = mx, ans = 0;
    while (l <= r) {
        int m = l + r >> 1;
        if (check(m)) {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << ans - 1;

    return 0;
}
