#include <bits/stdc++.h>
using namespace std;

#define NAME "Noel"
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

int n, a[N];
multiset <int> v;
multiset <multiset <int>> ve;

void solve(int i, int cl, int ke) {
    ve.insert(v);
    for (int j=i+1; j<=n; ++j) {
        if (a[j] - ke == cl) {
            v.insert(j);
            solve(j, cl, a[j]);
            v.erase(v.find(j));
        }
    }
}

void sub1() {
    for (int i=1; i<n; ++i) {
        v.insert(i);
        for (int j=i+1; j<=n; ++j) {
            v.insert(j);
            solve(j, a[j] - a[i], a[j]);
            v.erase(v.find(j));
        }
        v.erase(v.find(i));
    }
    for (auto it : ve) {
        multiset <int> ms;
        for (int i=1; i<=n; ++i) {
            if (it.find(i) == it.end())
                ms.insert(i);
        }
        if (ve.find(ms) != ve.end()) {
            cout << it.size() << '\n';
            for (auto x : it)
                cout << a[x] << " ";
            cout << '\n';
            cout << ms.size() << '\n';
            for (auto x : ms)
                cout << a[x] << " ";
            return;
        }
    }
    cout << -1;
}

void sub2() {}

void sub3() {}

void sub4() {}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    if (n <= 15)
        sub1();
    // else if (n <= 300)
    //     sub1();
    // else if (n <= 1e5)
    //     sub3();
    // else
    //     sub4();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
