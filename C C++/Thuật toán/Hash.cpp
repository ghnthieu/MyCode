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

int n, q;
string s;
ll pw[N], hashh[N];

ll get_hash(int l, int r) {
    return (hashh[r] - hashh[l - 1] * pw[r - l + 1] + MOD * MOD)  % MOD;
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q >> s;
    int len = s.length();
    s = "h" + s;
    pw[0] = 1;
    For(i, 1, len, 1) pw[i] = (pw[i - 1] * base) % MOD;
    For(i, 1, len, 1) hashh[i] = (hashh[i - 1] * base + s[i] - 'a' + 1) % MOD;
    //For(i, 1, n, 1) cout << hashh[i] << " ";
    //cout << '\n';
    Rep(query, q) {
        int l, r, u, v; cin >> l >> r >> u >> v;
        if (get_hash(l, r) == get_hash(u, v))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
