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
#define NOT 18446744073709551615
#define v(kdl) vector <kdl>
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <kdl1,kdl2>,kdl3>>

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

int n, m;
vii(int, int) tt;

bool cmp(ii(int, int) a, ii(int, int) b) {
    if (a.se == b.se)
        return a.fi > b.fi;
    return a.se > b.se;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int x, y; cin >> x >> y;
        tt.pub({x, y});
    }
    sort(all(tt), cmp);
    for (int i=0; i<tt.size(); ++i)
        cout << tt[i].fi << " " << tt[i].se << '\n';

    return 0;
}
