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
const int N = (int) 1e2 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int l, r, n = 16;
ll fibo[N];

void solve(int x) {
    int min_use = n + 1;
    vec(ll) left, right;
    for (int k = 1; k < mask(n); ++k) {
        vec(ll) t_left, t_right;
        t_left.pub(x);
        ll sumleft = x, sumright = 0;
        int cntleft = 1, cntright = 0;
        Rep(i, n) {
            if (bit(k, i)) {
                sumleft += fibo[i + 1];
                t_left.pub(fibo[i + 1]);
                ++cntleft;
            }
            else {
                sumright += fibo[i + 1];
                t_right.pub(fibo[i + 1]);
                ++cntright;
            }
            if (sumleft == sumright && cntleft + cntright < min_use) {
                min_use = cntleft + cntright;
                left.clear();
                for (ll v : t_left) left.pub(v);
                right.clear();
                for (ll v : t_right) right.pub(v);
            }
        }
    }

    cout << min_use << '\n';
    cout << left.size() << " ";
    sort(all(left), greater <ll>());
    for (ll v : left) cout << v << " ";
    cout << '\n';
    cout << right.size() << " ";
    sort(all(right), greater <ll>());
    for (ll v : right) cout << v << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> l >> r;
    fibo[1] = 1;
    fibo[2] = 2;
    For(i, 3, n, 1) fibo[i] = fibo[i - 1] + fibo[i - 2];

    For(i, l, r, 1) solve(i);

    return 0;
}
