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

typedef double de;
typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;


/*-----------------------------------------------------------------------------------------------------------------*/

int n, k;
ii(int, int) inp[N];
de ans = 1e15;
bool check[N];

void solve(vii(int, int) luu) {
    if (luu.size() == k) {
        de mx = -1e15;
        Rep(j1, luu.size()) Rep(j2, luu.size()) if (j1 != j2) {
            maximize(mx, (de) (luu[j1].se - luu[j2].se) / (luu[j1].fi - luu[j2].fi));
            if (mx > ans) return;
        }
        minimize(ans, mx);

        return;
    }

    For(i, 1, n, 1) {
        if (!check[i]) {
            check[i] = true;
            luu.pub(inp[i]);
            solve(luu);
            luu.pb();
            check[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> k;
    For(i, 1, n, 1) cin >> inp[i].fi >> inp[i].se;

    vii(int, int) tmp;
    solve(tmp);
    cout << fixed << setprecision(6) << ans;

    return 0;
}
