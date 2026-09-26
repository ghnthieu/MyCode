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
const ll MOD = (ll) 1e9 + 7;
const int N = (int) 4e6 + 7;
const int base = (int) 31;

/*-----------------------------------------------------------------------------------------------------------------*/

ll len, k, pw[N + 7], hashx[N], hashn[N];
string s;

ll get_hashx(int l, int r) {
    return (hashx[r] - hashx[l - 1] * pw[r - l + 1] + MOD * MOD) % MOD;
}

ll get_hashn(int l, int r) {
    return (hashn[l] - hashn[r + 1] * pw[r - l + 1] + MOD * MOD) % MOD;
}

void sub1(void) {
    string st = "";
    For(i, 1, k, 1) st += s; int lenn = st.length(); st = "h" + st;

    pw[0] = 1;
    For(i, 1, lenn, 1) pw[i] = (pw[i - 1] * base) % MOD;
    For(i, 1, lenn, 1) hashx[i] = (hashx[i - 1] * base + st[i] - 'a' + 1) % MOD;
    Ford(i, lenn, 1, 1) hashn[i] = (hashn[i + 1] * base + st[i] - 'a' + 1) % MOD;

    int ans = 0;
    For(i, 1, lenn, 1) For(j, i, lenn, 1) if (get_hashx(i, j) == get_hashn(i, j))
        maximize(ans, j - i + 1);
    cout << ans;
}

int odd[N], even[N];

void calc_odd(int n, string st) {
    For(i, 1, n, 1) {
        odd[i] = 0;
        while (i - odd[i] - 1 > 0 && i + odd[i] + 1 <= n && st[i - odd[i] - 1] == st[i + odd[i] + 1])
            ++odd[i];
    }
}

void calc_even(int n, string st) {
    int l = 1, r = 0;
    For(i, 1, n - 1, 1) {
        int j = i + 1;
        even[i] = 0;
        while (i - even[i] > 0 && j + even[i] <= n && st[i - even[i]] == st[j + even[i]])
            ++even[i];
    }
}

void sub2(void) {
    string st = "";
    For(i, 1, k, 1) st += s; int lenn = st.length(); st = "h" + st;

    calc_odd(lenn, st);
    calc_even(lenn, st);
    int ans = 0;
    For(i, 1, lenn - 1, 1) {
        maximize(ans, odd[i] * 2 + 1);
        maximize(ans, even[i] * 2);
    }
    cout << ans;
}

void sub3(void) {
    //Th 1
    s = "h" + s;
    string lr = "", rl = "";
    For(i, 1, len, 1) lr += s[i];
    Ford(i, len, 1, 1) rl += s[i];
    if (lr == rl) {
        cout << 1ll * len * k;
        return;
    }
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

    cin >> len >> k >> s;

    if (len <= 1e3 && k <= 3)
        sub1();
    else if (k <= 3)
        sub2();
    else
        sub3();

    return 0;
}
