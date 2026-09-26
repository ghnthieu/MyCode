#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pub push_back
#define pb pop_back
#define mask(i) (1ll << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n  = (n); i < _n; ++i)
template <typename T1, typename T2> bool maximize(T1 &x, T2 y) { if (x < y) { x = y; return true; } return false; }
template <typename T1, typename T2> bool minimize(T1 &x, T2 y) { if (x > y) { x = y; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

int a, b, c;
vec(vec(int)) luu_1, luu_2;

void backtrack_1(vec(int) luu) {
    if (!luu.empty()) {
        int sum = 0;
        for (int x : luu) {
            sum += x * x;
            if (sum > a) break;
        }
        if (sum == a) luu_1.pub(luu);
        else if (sum > a) return;
        if (luu.size() == 20) return;
    }

    For(i, 1, 10, 1) {
        luu.pub(i);
        backtrack_1(luu);
        luu.pb();
    }
}

void backtrack_2(vec(int) luu) {
    if (!luu.empty()) {
        int sum = 0;
        for (int x : luu) {
            sum += x * x;
            if (sum > b) break;
        }
        if (sum == b) luu_2.pub(luu);
        else if (sum > b) return;
        if (luu.size() == 20) return;
    }

    For(i, 1, 10, 1) {
        luu.pub(i);
        backtrack_2(luu);
        luu.pb();
    }
}

void solve(void) {
    //Init
    Rep(i, luu_1.size()) luu_1[i].clear();
    Rep(i, luu_2.size()) luu_2[i].clear();
    vec(int) tmp;
    backtrack_1(tmp);
    backtrack_2(tmp);

    //Calc
    For(len, 1, 20, 1) {
        Rep(i1, luu_1.size()) if (luu_1[i1].size() == len) {
            Rep(i2, luu_2.size()) if (luu_2[i2].size() == len) {
                vec(int) tluu_1, tluu_2;
                for (int x : luu_1[i1]) tluu_1.pub(x);
                for (int x : luu_2[i2]) tluu_2.pub(x);
                int sum = 0;
                Rep(i, len) {
                    sum += tluu_1[i] * tluu_2[i];
                    if (sum > c) break;
                }
                if (sum == c) {
                    cout << len << '\n';
                    for (int x : tluu_1) cout << x << " ";
                    cout << '\n';
                    for (int x : tluu_2) cout << x << " ";
                    cout << '\n';
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("GIFT.INP", "r", stdin);
    freopen("GIFT.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    Rep(tcase, 2) {
        cin >> a >> b >> c;
        solve();
    }

    return 0;
}
