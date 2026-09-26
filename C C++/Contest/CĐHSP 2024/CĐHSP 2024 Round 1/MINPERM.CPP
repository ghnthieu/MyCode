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
const int N = (int) 10 + 7;
const int M = (int) 3628807;

/*-----------------------------------------------------------------------------------------------------------------*/

int tcase, n, a[N], b[N], c[N], idx = 0;
vec(int) th[M];
bool check[N];

void sinh_th(vec(int) luu) {
    if (luu.size() == n) {
        th[++idx] = luu;
        return;
    }

    For(i, 1, n, 1) {
        if (!check[i]) {
            check[i] = true;
            luu.pub(i);
            sinh_th(luu);
            luu.pb();
            check[i] = false;
        }
    }
}

void solve(void) {
    int ans_idx = -1;
    ll ans = LLONG_MAX;
    For(t_idx, 1, idx, 1) {
        ll mx = LLONG_MIN;
        Rep(i, n) {
            ll sum1 = 0;
            For(j, 1, i + 1, 1) sum1 += a[th[t_idx][j - 1]];
            ll sum2 = 0;
            For(j, i + 1, n, 1) sum2 += b[th[t_idx][j - 1]];
            maximize(mx, 1ll * (sum1 + sum2) * c[th[t_idx][i]]);
        }
        if (minimize(ans, mx)) ans_idx = t_idx;
    }
    for (int x : th[ans_idx])
        cout << x << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("MINPERM.INP", "r", stdin);
    freopen("MINPERM.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> tcase;
    Rep(test_case, tcase) {
        cin >> n;
        For(i, 1, n, 1) cin >> a[i] >> b[i] >> c[i];

        vec(int) tmp;
        sinh_th(tmp);
        solve();

        //Init
        For(i, 1, idx, 1) th[i].clear();
        memset(check, false, (n + 1) * sizeof(bool));
        idx = 0;
    }

    //cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
