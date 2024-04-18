#include <bits/stdc++.h>
using namespace std;

#define NAME ""
#define fi first
#define se second
#define fr front
#define bk back
#define pf pop_front
#define pb pop_back
#define puf push_front
#define pub push_back
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
const int MOD = (int) 1e9 + 19972207;
const int N = (int) 2e5 + 7;
const int M = (int) 17; //M là max của 2^M < N

int n, q, a[N], mn[M + 1][N];

void buildmn(void) {
    for (int i=1; i<=n; ++i)
        mn[0][i] = a[i];
    for (int j=1; j<=M; ++j) {
        for (int i=1; (i + mask(j) - 1)<=n; ++i)
            mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + mask(j - 1)]);
    }
}

int getmn(int l, int r) {
    int m = __lg(r - l + 1);
    return min(mn[m][l], mn[m][r - mask(m) + 1]);
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> n >> q;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    buildmn();
    while (q--) {
        int l, r; cin >> l >> r;
        cout << getmn(l, r) << '\n';
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
