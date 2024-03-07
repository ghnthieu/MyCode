#include <bits/stdc++.h>
using namespace std;

#define NAME "NETWORK"
#define fi first
#define se second
#define fr front
#define bk back
#define pf pop_front
#define pb pop_back
#define puf push_front
#define pub push_back
#define NOT 18446744073709551615
#define __Trung_Hieu___ signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define vec(kdl) vector <kdl>
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1,kdl2>,kdl3>>

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
typedef long double lde;
const int MOD = (int) 1e9 + 7;
const int N = (int) 2e5 + 7;

int n, m, u[N], v[N], a[N], b[N];
map <int, int> mp;

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> n >> m;
    for (int i=1; i<n; ++i)
        cin >> u[i] >> v[i];
    for (int i=0; i<m; ++i) {
        cin >> a[i] >> b[i];
        ++mp[a[i]];
    }
    int cnt = 0;
    for (auto x : mp) {
        if (x.fi == 1)
            ++cnt;
    }
    cout << cnt;

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
