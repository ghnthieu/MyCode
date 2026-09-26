#include <bits/stdc++.h>
using namespace std;

#define NAME "BARNSHEEP"
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
const int N = (int) 3e3 + 7;

int n, a[N], b[N];
ll ans = 0;
bool check[N];

void sub1(int i) {
    bool ok = false;
    for (int j=n; j>=1; --j) {
        if (check[j])
            continue;
        if (a[i] <= b[j]) {
            ok = true;
            check[j] = true;
            sub1(i + 1);
            check[j] = false;
        }
        else if (!ok) {
            ++ans;
            ans %= MOD;
            return;
        }
    }
}

void sub2() {}

void sub3() {}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=1; i<=n; ++i)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    //if (n <= 8) {
        sub1(1);
        cout << ans;
    // }
    // else if (n <= 50)
    //     sub2();
    // else
    //     sub3();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
