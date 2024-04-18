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
typedef double de;
typedef long double lde;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

ll n, m;

ll somod(ll n) {
    ll res = 1;
    while (n) {
        res *= 10;
        n /= 10;
    }
    return res;
}

void sub1(void) {
    ll mod = somod(n), ans = 0;
    for (ll i=n+1; i<=m; ++i) {
        if (i % mod == n)
            ++ans;
    }
    cout << ans;
}

void sub2(void) {
    ll mod = somod(n);
    cout << (ll) (m - (n + mod)) / mod + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("LIKENUM.INP", "r", stdin);
    freopen("LIKENUM.OUT", "w", stdout);

    cin >> n >> m;
    if (m <= 1e5)
        sub1();
    else
        sub2();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
