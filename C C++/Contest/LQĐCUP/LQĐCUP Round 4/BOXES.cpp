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
const int MOD = (int) 998244353;
const int N = (int) 1e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, col[N], idx[N], ans = 0;
bool check[N];

void sub1(vec(int) luu) {
    if (luu.size() == m + 1) {
        bool res = true;
        For(i, 1, n, 1) {
            For(j, idx[i - 1] + 1, idx[i], 1) if (luu[j] == i) {
                res = false;
                break;
            }
            if (!res) break;
        }
        if (res) ++ans;
        return;
    }

    For(i, 1, m, 1) if (!check[i]) {
        check[i] = true;
        luu.pub(col[i]);
        sub1(luu);
        luu.pb();
        check[i] = false;
    }
}

void sub2(void) {}

ll dp3[N];

void sub3(void) {
    dp3[1] = 0; dp3[2] = 1;
    For(i, 3, m, 1) dp3[i] = 1ll * (i - 1) * ((dp3[i - 1] + dp3[i - 2]) % MOD) % MOD;
    cout << dp3[m];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BOXES.inp", "r", stdin);
    freopen("BOXES.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    idx[0] = 0;
    bool check_sub3 = true;
    For(i, 1, n, 1) {
        int sl; cin >> sl;
        idx[i] = idx[i - 1] + sl;
        For(j, idx[i - 1] + 1, idx[i], 1) col[j] = i;
        if (sl != 1) check_sub3 = false;
    }

    if (n <= 10 && m <= 10) {
        vec(int) tmp; tmp.pub(0);
        sub1(tmp);
        cout << ans;
    }
    else if (n <= 20 && m <= 20)
        sub2();
    else if (check_sub3)
        sub3();

    return 0;
}
