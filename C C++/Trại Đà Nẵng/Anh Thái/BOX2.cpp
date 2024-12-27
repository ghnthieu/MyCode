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
const int INF = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n;

struct Data {
    int x, y, idx;
} a[N];

bool cmp(Data x, Data y) {
    if (x.x == y.x) return (x.y > y.y);
    return (x.x < y.x);
}

int tid[N];
vec(int) pb[N];
multiset <ii(int, int)> mst;

void solve(void) {
    int cnt = 1;
    mst.insert({INF, 0});
    For(i, 1, n, 1) {
        if (mst.empty()) {
            mst.insert({a[i].y, a[i].idx});
            tid[a[i].idx] = cnt;
            pb[cnt++].pub(a[i].idx);
        }
        else {
            auto tk = mst.lower_bound({a[i].y, 0});
            if (*tk == *mst.begin()) {
                mst.insert({a[i].y, a[i].idx});
                tid[a[i].idx] = cnt;
                pb[cnt++].pub(a[i].idx);
            }
            else {
                --tk; int tmp = tid[(*tk).se];
                pb[tmp].pub(a[i].idx);
                tid[a[i].idx] = tmp;
                mst.insert({a[i].y, a[i].idx});
                mst.erase(*tk);
            }
        }
    } --cnt;
    For(i, 1, cnt, 1) reverse(all(pb[i]));

    cout << cnt << '\n';
    For(i, 1, cnt, 1) {
        cout << pb[i].size() << " ";
        for (int x : pb[i]) cout << x << " ";
        cout << '\n';
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) { cin >> a[i].x >> a[i].y; a[i].idx = i; }
    sort(a + 1, a + n + 1, cmp);
    solve();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
