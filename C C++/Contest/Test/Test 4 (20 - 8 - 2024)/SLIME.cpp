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

int n, s, slm[N];
ll gt[N], gt_mod[N];

void sub1(void) {
    int ans = 0;
    For(k, 1, mask(n) - 1, 1) {
        priority_queue <int, vec(int), greater <int>> pq;
        Rep(i, n) if (bit(k, i))
            pq.push(slm[i + 1]);
        bool check = false;
        while (!pq.empty()) {
            int top = pq.top(); pq.pop();
            if (top == s) { check = true; break; }
            if (!pq.empty() && top == pq.top()) {
                pq.pop();
                pq.push(top * 2);
            }
        }
        if (check) ++ans;
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

int ckn(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return gt[n] * gt_mod[k] % MOD * gt_mod[n - k] % MOD;
}

void sub3(void) {
    int k = 0;
    while (s % 2 == 0) {
        ++k;
        s /= 2;
    }

    int t = -1;
    Rep(i, 14) if (s * ltbinary(2, i) == slm[1]) {
        t = i;
        break;
    }

    if (t == -1) { cout << 0; return; }

    gt[0] = 1;
    For(i, 1, N - 1, 1) {
        gt[i] = gt[i - 1] * i % MOD;
        gt_mod[i] = ltbinary(gt[i], MOD - 2);
    }

    int tk = ltbinary(2, k - t);
    cout << ckn(n, tk);;
}

int cnt_choose[N], dp[13][mask(13)], k = 0;
bool check[13][mask(13)];

void add(int &x, int y) {
    x += y;
    x -= ((x >= MOD) ? MOD : 0);
}

void sub(int &x, int y) {
    x -= y;
    //x += ((x < 0) ? MOD : 0);
    x %= MOD;
}

int get_dp(int cs_k, int cs_mask) {
    int res = dp[cs_k][cs_mask]; bool tcheck = check[cs_k][cs_mask];
    if (tcheck) return res;
    if (cs_k == k + 1) return bit(cs_mask, k);

    int new_csm = ((cs_mask & mask(k)) ? mask(k) : cs_mask), choose = ltbinary(2, cnt_choose[cs_k]); res = 0;
    Rep(i, cnt_choose[cs_k] + 1) {
        add(res, ckn(cnt_choose[cs_k], i) * 1ll * get_dp(cs_k + 1, new_csm) % MOD);
        if (new_csm & mask(k))
            new_csm = mask(k);
        else
            new_csm += mask(cs_k);
        sub(choose, ckn(cnt_choose[cs_k], i) - MOD);
        if (new_csm & mask(k)) break;
    }
    add(res, choose * 1ll * get_dp(cs_k + 1, mask(k)) % MOD);

    tcheck = true;
    return res;
}

void sub2(void) {
    k = 0;
    while (s % 2 == 0) {
        ++k; s /= 2;
    }

    gt[0] = 1;
    For(i, 1, N - 1, 1) gt[i] = gt[i - 1] * i % MOD;
    gt_mod[N - 1] = ltbinary(gt[N - 1], MOD - 2);
    Ford(i, N - 2, 0, 1) gt_mod[i] = gt_mod[i + 1] * 1ll * (i + 1) % MOD;

    int sl = 0;
    For(i, 1, n, 1) {
        if (slm[i] % s != 0)
            ++sl;
        else {
            if (__builtin_popcountll(slm[i] / s) == 1) //Chon 1
                ++cnt_choose[__builtin_ctz(slm[i] / s)];
            else
                ++sl;
        }
    }

    cout << get_dp(0, 0) * ltbinary(2, sl) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("SLIME.inp", "r", stdin);
    freopen("SLIME.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> s;
    bool dk_sub3 = true;
    For(i, 1, n, 1) {
        cin >> slm[i];
        if (i > 1 && slm[i] != slm[i - 1]) dk_sub3 = false;
    }

    if (dk_sub3)
        sub3();
    else if (n <= 19)
        sub1();
    else if (n <= 2e3)
        sub2();

    return 0;
}
