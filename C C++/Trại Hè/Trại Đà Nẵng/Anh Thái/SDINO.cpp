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
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, a[N];
stack <int> sk;
deque <int> dq;

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) cin >> a[i];
    Ford(i, n, 1, 1) sk.push(a[i]);

    string ans = "";
    Ford(i, n, 1, 1) {
        int cnt = i;
        vec(int) luu;
        while (cnt--) { luu.pub(sk.top()); sk.pop(); }
        if (luu.bk() == i) {
            Ford(j, luu.size() - 1, 0, 1) sk.push(luu[j]);
            continue;
        }
        else {
            deque <int> dq;
            for (int x : luu) {
                dq.pub(x);
                ans += "C";
            }
            while (dq.fr() != i) {
                ans += "HC";
                dq.pub(dq.fr());
                dq.pf();
            }
            while (!dq.empty()) {
                sk.push(dq.fr());
                dq.pf();
                ans += "H";
            }
        }
    }
    cout << ans;

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
