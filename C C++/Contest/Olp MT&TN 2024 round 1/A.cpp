#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
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
#define __Trung_Hieu___ signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define bit(n, i) ((n >> i) & 1)
#define mask(i) (1ll << i)
#define vec(kdl) vector <kdl>
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1,kdl2>,kdl3>>
template <typename T1, typename T2> void maximize(T1 &a, T2 b) { if (a < b) a = b; }
template <typename T1, typename T2> void minimize(T1 &a, T2 b) { if (a > b) a = b; }

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
typedef long double lde;
const int MOD = (int) 1e9 + 7;
const int N = (int) 3e1 + 7;

int n, m, q, a[N][N];

int chuyen(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        return (ch - 'A') + 1;
    if (ch >= 'a' && ch <= 'z')
        return (ch - 'a') + 1;
}

void solve(string s) {
    string phep = "";
    phep += s[0]; phep += s[1]; phep += s[2];
    if (phep == "SUM")
        cout << a[s[5] - '0'][chuyen(s[4])] + a[s[8] - '0'][chuyen(s[7])] << '\n';
    else
        cout <<  max(a[s[5] - '0'][chuyen(s[4])], a[s[8] - '0'][chuyen(s[7])]) << '\n';
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j)
            cin >> a[i][j];
    }
    cin >> q;
    cin.ignore();
    while (q--) {
        string s; getline(cin, s);
        solve(s);
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
