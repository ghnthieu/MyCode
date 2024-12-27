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
const ll MOD = (ll) 1e9 + 7;
const int N = (int) 1e6 + 7;
const int base = (int) 31;

/*-----------------------------------------------------------------------------------------------------------------*/

int n;
string a[17];
ll pw[N + 7], hashh[17][N];

ll get_hash(int l, int r, int idx) {
    return 1ll * (hashh[idx][r] - hashh[idx][l - 1] + MOD) % MOD * pw[N - r] % MOD;
}

void init(void) {
    pw[0] = 1;
    For(i, 1, N, 1) pw[i] = (pw[i - 1] * base) % MOD;
    For(i, 1, n, 1) {
        string st = a[i]; int len = st.length() - 1;
        For(j, 1, len, 1) hashh[i][j] = (hashh[i][j - 1] + 1ll * (st[j] - 'a' + 1) * pw[j] % MOD) % MOD;
    }
}

void solve(void) {
    init();

    For(i, 1, n, 1) {
        int len = a[i].length() - 1;
        int csl = 1, csr = len, l = 1, r = len, ans = 0;
        while (l < r) {
            if (get_hash(csl, l, i) == get_hash(r, csr, i)) {
                csl = l + 1; csr = r - 1;
                ans += 2;
            }
            ++l; --r;
        }
        cout << ans + ((csl <= csr) ? 1 : 0) << '\n';
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PARPALIND.inp", "r", stdin);
    freopen("PARPALIND.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    int mx = 0;
    For(i, 1, n, 1) {
        cin >> a[i];
        a[i] = "h" + a[i];
        maximize(mx, a[i].length() - 1);
    }

    solve();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
