#include <bits/stdc++.h>
using namespace std;

#define NAME "MAGICWISH"
#define fi first
#define se second
#define fr front
#define bk back
#define pf pop_front
#define pb pop_back
#define puf push_front
#define pub push_back
#define NOT 18446744073709551615
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
const int N = (int) 1e5 + 7;

int test, n, p, q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);

    cin >> test;
    while (test--) {
        cin >> n >> p >> q;
        for (int i=1; i<=n; ++i)
            cin >> a[i];
        if (n == 2) {
            cout << max(a[1], a[n]) - min(a[1], a[n]) << '\n';
            continue;
        }
        sort(a + 1, a + n + 1);
        if (a[n] > 0 && a[n - 1] < 0) {
            cout << a[n] - a[1] << '\n';
            continue;
        }
        if ()
    }

    return 0;
}
