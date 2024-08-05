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
const int N = (int) 1e7 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, d, mx_len = 0;
bool use[N], vit[N];
vec(vec(int)) ans;

void sub1(int i, vec(int) luu) {
    if (!luu.empty()) {
        if (luu.size() >= mx_len) {
            bool check = true;
            Rep(it, luu.size()) {
                Rep(j, luu.size()) {
                    if (it != j && abs(luu[it] - luu[j]) <= d) {
                        check = false;
                        break;
                    }
                }
                if (!check) break;
            }
            if (check) {
                ans.pub(luu);
                maximize(mx_len, luu.size());
            }
            else
                return;
        }
    }

    For(j, i + 1, n, 1) {
        if (!use[j] && !vit[j]) {
            vit[j] = true;
            luu.pub(j);
            sub1(j, luu);
            luu.pb();
            vit[j] = false;
        }
    }
}

void sub2(void) {}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("opset.inp", "r", stdin);
    //freopen("opset.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> d;
    For(i, 1, m, 1) {
        int x; cin >> x;
        use[x] = true;
    }

    //if (n - m <= 20) {
        vec(int) tmp;
        sub1(0, tmp);
        int mx = 0;
        Rep(i, ans.size()) maximize(mx, ans[i].size());
        int cnt = 0;
        Rep(i, ans.size()) if (ans[i].size() == mx)
            ++cnt;
        cout << mx << '\n' << cnt;
    //}
    //else
    //    sub2();

    return 0;
}
