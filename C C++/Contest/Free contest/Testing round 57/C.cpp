#include <bits/stdc++.h>
using namespace std;

#define NAME "GRIDCOLOR"
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
const int N = (int) 1e3 + 7;

int n, m, k, mau[N][N];
char a[N][N], b[N][N], c[N][N];

void sub1() {
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j)
            cout << 1 << " ";
        cout << '\n';
    }
}

void sub2() {

}

void sub3() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);

    cin >> n >> m >> k;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j)
            cin >> a[i][j];
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<m; ++j)
            b[i][j] = a[i][j];
    }
    for (int i=1; i<n; ++i) {
        for (int j=1; j<=m; ++j)
            c[i][j] = a[i][j];
    }
    memset(mau, 0, sizeof(mau));
    if (k == 1)
        sub1();
    else if (n * m <= 15)
        sub2();
    else
        sub3();

    return 0;
}
