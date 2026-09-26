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
const int N = (int) 3e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

struct Data {
    int pos, type, time_begin, time_end;
} a[N];

int n, k, q;
ii(int, int) que[N];
vec(int) onl;

bool check(int x, int pos) {
    set <int> st;
    for (int i : onl) if (abs(a[i].pos - pos) <= x)
        st.insert(a[i].type);
    return (st.size() == k);
}

void sub12(void) {
    For(i, 1, q, 1) {
        int pos = que[i].fi, time = que[i].se;
        onl.clear(); set <int> pb;
        For(i, 1, n, 1) if (a[i].time_begin <= time && time <= a[i].time_end) {
            onl.pub(i);
            pb.insert(a[i].type);
        }
        if (pb.size() != k) {
            cout << -1 << '\n';
            continue;
        }
        int l = 0, r = 1e8, res = 1e8 + 7;
        while (l <= r) {
            int m = l + r >> 1;
            if (check(m, pos)) {
                minimize(res, m);
                r = m - 1;
            }
            else
                l = m + 1;
        }
        cout << res << '\n';
    }
}

void sub3(void) {

}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PIZZASHOP.INP", "r", stdin);
    freopen("PIZZASHOP.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> k >> q;
    For(i, 1, n, 1) cin >> a[i].pos >> a[i].type >> a[i].time_begin >> a[i].time_end;
    For(i, 1, q, 1) cin >> que[i].fi >> que[i].se;

    //if ((n <= 4e2 && q <= 4e2) || (n <= 6e4 && q <= 6e4 && k <= 4e2))
        sub12();
    //else
    //    sub3();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
