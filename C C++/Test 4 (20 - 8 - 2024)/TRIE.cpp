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
const int M = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n;
string a[N];

ll dp[N][N];
vii(int, int) luu;

void add(ll &x, ll y) {
    x += y;
    x -= ((x >= MOD) ? MOD : 0);
}

void sub(ll &x, ll y) {
    x -= y;
    x += ((x < 0) ? MOD : 0);
}

void sub1t4(void) {
    For(i, 1, n, 1) {
        int cnt_a = 0, cnt_b = 0;
        for (char x : a[i]) {
            cnt_a += (x == 'a');
            cnt_b += (x == 'b');
        }
        luu.pub({cnt_a, cnt_b});
    }

    For(i, 1, N - 1, 1) dp[0][i] = dp[i][0] = i + 1;
    For(i, 1, N - 1, 1) For(j, 1, N - 1, 1) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + 1) % MOD;

    ll ans = 0;
    For(k, 1, mask(n) - 1, 1) {
        int sl_bit1 = __builtin_popcountll(k);
        vec(int) bit1;
        Rep(i, n) if (bit(k, i))
            bit1.pub(i);

        int mna = INT_MAX, mnb = INT_MAX;
        for (int x : bit1) {
            minimize(mna, luu[x].fi);
            minimize(mnb, luu[x].se);
        }

        if (sl_bit1 % 2 == 0)
            sub(ans, dp[mna][mnb]);
        else
            add(ans, dp[mna][mnb]);
    }
    cout << ans;
}

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

ll lt[M], lt_mod[M];

ll ckn(int k, int n) {
    return lt[n] * (lt_mod[k] * lt_mod[n - k] % MOD) % MOD;
}

void subfull(void) {
    For(i, 1, n, 1) {
        int cnt_a = 0, cnt_b = 0;
        for (char x : a[i]) {
            cnt_a += (x == 'a');
            cnt_b += (x == 'b');
        }
        luu.pub({cnt_a, cnt_b});
    }

    lt[0] = 1;
    lt_mod[0] = 1;
    For(i, 1, M - 1, 1) {
        lt[i] = (lt[i - 1] * i) % MOD;
        lt_mod[i] = ltbinary(lt[i], MOD - 2);
    }

    ll ans = 0;
    For(k, 1, mask(n) - 1, 1) {
        int sl_bit1 = __builtin_popcountll(k);
        vec(int) bit1;
        Rep(i, n) if (bit(k, i))
            bit1.pub(i);

        int mna = INT_MAX, mnb = INT_MAX;
        for (int x : bit1) {
            minimize(mna, luu[x].fi);
            minimize(mnb, luu[x].se);
        }

        if (sl_bit1 % 2 == 0)
            sub(ans, ckn(mna + 1, mna + mnb + 2) - 1);
        else
            add(ans, ckn(mna + 1, mna + mnb + 2) - 1);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("TRIE.inp", "r", stdin);
    freopen("TRIE.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    bool dk_sub1t4 = true;
    For(i, 1, n, 1) {
        cin >> a[i];
        if (a[i].length() > 1e3) dk_sub1t4 = false;
    }

    if (dk_sub1t4)
        sub1t4();
    else
        subfull();

    return 0;
}
