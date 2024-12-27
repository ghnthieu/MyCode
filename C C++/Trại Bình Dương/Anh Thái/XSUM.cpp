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
const int N = (int) 1e4 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

string n, m;

void add(int &x, int y) {
    x += y;
    x -= ((x >= MOD) ? MOD : 0);
}

void sub(int &x, int y) {
    x -= y;
    x += ((x < 0) ? MOD : 0);
}

int ltbinary(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % MOD;
        a = 1ll * a * a % MOD;
        b >>= 1;
    }
    return res;
}

string subb(string st) {
    int i = st.length() - 1;
    while (i >= 0 && st[i] == '0') st[i--] = '9';
    if (i >= 0) st[i] = char(int(st[i]) - 1);
    while (st.length() > 1 && st[0] == '0') st.erase(st.begin());
    return st;
}

bool check;

string divv(string st) {
    check = (int(st[st.length() - 1]) - 48) % 2;
    string res = ""; int tmp = 0;
    Rep(i, st.length()) {
        tmp = tmp * 10 + int(st[i]) - 48;
        res += char(tmp / 2 + 48);
        tmp %= 2;
    }
    while (res.length() > 1 && res[0] == '0') res.erase(res.begin());
    return res;
}

int mod(string st) {
    int res = 0;
    Rep(i, st.length()) res = (1ll * res * 10 + int(st[i]) - 48) % MOD;
    return res;
}

int dp[2][N], tdp[2][N], pw[N], modu[N];
string bitt[2];

int calc_bit(int tt, int idx) {
    int res = 0;
    res = tdp[tt][idx + 1];
    res = 1ll * res * pw[idx - 1] % MOD;
    if (bitt[tt][idx - 1] == '1') add(res, dp[tt][idx - 1] + 1);
    return res;
}

void init(void) {
    pw[0] = 1;
    For(i, 1, 5007, 1) {
        pw[i] = pw[i - 1] * 2;
        pw[i] -= ((pw[i] >= MOD) ? MOD : 0);
    }
}

void sub1(void) {
    init();
    int x = mod(n), y = mod(m);
    n = subb(n), m = subb(m);
    while (n.length() > 1 || n[0] != '0') {
        n = divv(n);
        bitt[0] += char(check + 48);
    }
    while (m.length() > 1 || m[0] != '0') {
        m = divv(m);
        bitt[1] += char(check + 48);
    }
    modu[0] = 1; modu[1] = ltbinary(2, MOD - 2);
    For(i, 2, 5007, 1) modu[i] = 1ll * modu[i - 1] * modu[1] % MOD;
    while (bitt[0].length() < bitt[1].length()) bitt[0] += '0';
    while (bitt[1].length() < bitt[0].length()) bitt[1] += '0';
    int len = bitt[0].length();
    For(tt, 0, 1, 1) For(i, 1, len, 1) {
        dp[tt][i] = dp[tt][i - 1];
        add(dp[tt][i], ((bitt[tt][i - 1] == '1') ? pw[i - 1] : 0));
    }
    For(tt, 0, 1, 1) Ford(i, len, 1, 1) {
        tdp[tt][i] = tdp[tt][i + 1] * 2 % MOD;
        add(tdp[tt][i], int(bitt[tt][i - 1]) - 48);
    }
    int ans = 0;
    For(i, 1, len, 1) {
        int cnt1 = calc_bit(0, i), cnt2 = calc_bit(1, i);
        int tmp1 = x, tmp2 = y;
        sub(tmp1, cnt1); sub(tmp2, cnt2);
        int sum = 0;
        add(sum, 1ll * tmp2 * cnt1 % MOD);
        add(sum, 1ll * tmp1 * cnt2 % MOD);
        add(ans, 1ll * sum * pw[i - 1] % MOD);
    }
    cout << ans;
}

void sub2(void) {}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;

    // if (n.length() <= 10 && m.length() <= 10)
        sub1();
    // else
        // sub2();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
