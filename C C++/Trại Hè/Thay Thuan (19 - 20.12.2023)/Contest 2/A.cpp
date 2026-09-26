#include <bits/stdc++.h>
using namespace std;

#define NAME "SHARK"
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
const int N = (int) 1e5 + 7;

int n;
vec(int) inp[N];

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> n;
    inp[1].pub(n);
    inp[1].pub(2);
    inp[n].pub(1);
    inp[n].pub(n - 1);
    for (int i=2; i<n; ++i) {
    	inp[i].pub(i + 1);
    	inp[i].pub(i - 1);
    }
    for (int i=0; i<n-3; ++i) {
    	int x, y; cin >> x >> y;
    	inp[x].pub(y);
    	inp[y].pub(x);
    }
    for (int i=1; i<=n; ++i) 
    	sort(all(inp[i]));
    int mx = 0;
    for (int i=1; i<=n; ++i)
        mx = max(mx, (int) inp[i].size());
    cout << mx;
    

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
Tìm đường đi dài nhất trên cây
