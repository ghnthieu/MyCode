#include <bits/stdc++.h>
using namespace std;

#define NAME ""
#define fi first
#define se second
#define bk back
#define fr front
#define pb pop_back
#define pf pop_front
#define pub push_back
#define puf push_front
#define NOT 18446744073709551615
#define __Trung_Hieu___ signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define vec(kdl) vector <kdl>
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1,kdl2>,kdl3>>
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;

int n, k, cnt[N], con[N], ans[N];
bool den[N];
vec(int) inp[N];

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
        int x; cin >> x;
        den[i] = ((x) ? true : false);
    }
    for (int i=1; i<n; ++i) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        con[x] = y;
        ++cnt[y];
    }
    while (k--) {
        int start; cin >> start;
        ++ans[con[start]];
    }

    queue <int> tlist;
    for (int i=1; i<=n; ++i) {
        if (!cnt[i])
            tlist.push(i);
    }
    vec(int) stopo;
    while (!tlist.empty()) {
        int u = tlist.fr(); tlist.pop();
        stopo.pub(u);
        for (int v : inp[u]) {
            if (--cnt[v] == 0)
                tlist.push(v);
        }
    }
    for (int x : stopo)
        ans[con[x]] += ans[x];

    int res = ((den[1]) ? 1 : 0);
    for (int i=2; i<=n; ++i) {
        if (den[i] && ans[i] % 2 == 0)
            ++res;
        else if (!den[i] && ans[i] % 2 != 0)
            ++res;
    }
    cout << res;

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
