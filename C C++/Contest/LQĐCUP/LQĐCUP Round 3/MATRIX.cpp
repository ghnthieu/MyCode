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
const int N = (int) 1e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int tcase, n, k, a, b;
ll arr1[N][N][13], arr2[N][N][13];

ll ltbinary(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b) {
        if (b & 1) res = ((res % MOD) * (a % MOD)) % MOD;
        a = ((a % MOD) * (a % MOD)) % MOD;
        b >>= 1;
    }
    return (res % MOD);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MATRIX.inp", "r", stdin);
    freopen("MATRIX.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> tcase;
    Rep(test_case, tcase) {
        cin >> n >> k >> a >> b;
        int h1, c1, h2, c2; cin >> h1 >> c1 >> h2 >> c2;
        memset(arr1, 0, sizeof(arr1)); memset(arr2, 0, sizeof(arr2));
        For(i, 1, n, 1) For(j, 1, n, 1) arr1[i][j][0] = ltbinary(i, a) * ltbinary(j, b) % MOD;
        For(i, 1, n, 1) For(j, 1, n, 1) arr2[i][j][0] = arr1[j][i][0];

        ll sum = 0;
        For(i, h1, h2, 1) For(j, c1, c2, 1)
            sum += arr1[i][j][k];
        cout << sum << '\n';
    }


    return 0;
}
