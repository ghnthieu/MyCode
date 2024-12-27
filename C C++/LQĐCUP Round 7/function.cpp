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
const int N = (int) 1e5 + 7;
const int M = (int) 1e3 + 7;
const int base = (int) 31;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q, val[N];
string str[N];
ll pw[N], hash_str[M][M];
vec(int) luu;

struct Data {
    int type, idx, new_val; string xc;
} que[N];

ll get_hash(int l, int r, int idx) {
    return (hash_str[idx][r] - hash_str[idx][l - 1] * pw[r - l + 1] + MOD * MOD) % MOD;
}

void init(void) {
    pw[0] = 1;
    For(i, 1, M - 1, 1) pw[i] = (pw[i - 1] * base) % MOD;
    For(i, 1, n, 1) For(j, 1, str[i].length() - 1, 1) hash_str[i][j] = (hash_str[i][j - 1] * base + str[i][j] - 'A' + 1) % MOD;
}

void sub1(void) {
    init();
    For(i, 1, q, 1) {
        int type = que[i].type;
        if (type == 1) {
            int idx = que[i].idx, valu = que[i].new_val;
            val[idx] = valu;
        }
        else {
            string xc = que[i].xc;
            int len = xc.length() - 1; ll hash_xc = 0;
            For(i, 1, len, 1) hash_xc = (hash_xc * base + xc[i] - 'A' + 1) % MOD;
            ll sum = 0;
            For(i, 1, n, 1) {
                int cnt = 0;
                For(j, 1, str[i].length() - len, 1) if (hash_xc == get_hash(j, j + len - 1, i))
                    ++cnt;
                sum += 1ll * cnt * val[i];
            }
            cout << sum << '\n';
        }
    }
}

void sub2(void) {
    init();

}

void sub3(void) {}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("function.inp", "r", stdin);
    freopen("function.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    bool check_sub1 = true, check_sub3 = true; int sum = 0;
    For(i, 1, n, 1) cin >> val[i];
    For(i, 1, n, 1) {
        cin >> str[i];
        sum += str[i].length();
        str[i] = "h" + str[i];
    }
    if (sum > 1e3) check_sub1 = false;
    sum = 0;
    For(i, 1, q, 1) {
        cin >> que[i].type;
        if (que[i].type == 1) {
            cin >> que[i].idx >> que[i].new_val;
            check_sub3 = false;
        }
        else {
            cin >> que[i].xc;
            sum += que[i].xc.length();
            que[i].xc = "h" + que[i].xc;
        }
    }
    if (sum > 1e3) check_sub1 = false;

    //if (check_sub1)
        sub1();
    //else if (n <= 1e3 && q <= 1e3)
    //    sub2();
    //else if (check_sub3)
    //    sub3();

    return 0;
}
