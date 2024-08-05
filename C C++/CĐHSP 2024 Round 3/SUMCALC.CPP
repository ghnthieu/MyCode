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
const int N = (int) 2e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int tcase;
ll n, ans[N];

void init(void) {
    ll res = 0;
    ans[1] = 0;
    For(i, 2, N, 1) {
        int tmp = i, cnt = 0;
        while (tmp != 1) {
            int mx = INT_MIN, val1 = -1, val2 = -1;
            For(j1, 1, tmp, 1) For(j2, j1, tmp, 1) if (j1 * j2 <= tmp)
                maximize(mx, min(j1, j2));
            ++cnt;
            tmp = mx;
        }
        ans[i] = ans[i - 1] + cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("SUMCALC.INP", "r", stdin);
    freopen("SUMCALC.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    init();

    cin >> tcase;
    Rep(test_case, tcase) {
        cin >> n;
        cout << ans[n] << '\n';
    }

    return 0;
}
