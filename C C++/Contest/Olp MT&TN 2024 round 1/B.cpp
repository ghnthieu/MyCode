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
const int N = (int) 4e5 + 7;

int n, k, dep[N];

ll dp1[N];
void sub1() {
    dp1[1] = dep[1];
    for (int i=0; i<=n; ++i) {
        for (int j=i+1; j<=n; ++j) {
            if (j - i == dep[j] - dep[i])
                maximize(dp1[j], dp1[i] + dep[j]);
        }
    }
    cout << dp1[n];
}

ll dp2[N][2];
void sub2() {
    for (int i=1; i<=n; ++i)
        dp2[i][0] = dep[i];
    for (int i=1; i<=n; ++i) {
        for (int j=i+1; j<=n; ++j) {
            for (int tk=0; tk<2; ++tk) {
                if (!tk) {
                    if (j - i == dep[j] - dep[i])
                        maximize(dp2[j][tk], dp2[i][tk] + dep[j]);
                    maximize(dp2[j][tk + 1], dp2[i][tk] + dep[j]);
                }
                else {
                    if (j - i == dep[j] - dep[i])
                        maximize(dp2[j][tk], dp2[i][tk] + dep[j]);
                }
            }
        }
    }
    ll res = LLONG_MIN;
    for (int i=1; i<=n; ++i) {
        maximize(res, dp2[i][0]);
        maximize(res, dp2[i][1]);
    }
    cout << res;
}

ll dp3[N][31];
void sub3() {
    for (int i=1; i<=n; ++i)
        dp3[i][0] = dep[i];
    for (int i=1; i<=n; ++i) {
        for (int j=i+1; j<=n; ++j) {
            for (int tk=0; tk<k; ++tk) {
                if (tk < k - 1) {
                    for (int ttk=tk+1; ttk<k; ++ttk) {
                        if (j - i == dep[j] - dep[i])
                            maximize(dp3[j][ttk], dp3[i][ttk] + dep[j]);
                        maximize(dp3[j][ttk], dp3[i][ttk] + dep[j]);
                    }
                }
                else {
                    if (j - i == dep[j] - dep[i])
                        maximize(dp3[j][tk], dp3[i][tk] + dep[j]);
                }
            }
        }
    }
    ll res = LLONG_MIN;
    for (int i=1; i<=n; ++i) {
        for (int j=0; j<k; ++j)
            maximize(res, dp3[i][j]);
    }
    cout << res;
}

void sub4() {}

void sub5() {}

void sub6() {}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> n >> k;
    for (int i=1; i<=n; ++i)
        cin >> dep[i];

    if (n <= 1e3 && !k)
        sub1();
    else if (n <= 1e3 && k == 1)
        sub2();
    else if (n <= 1e3)
        sub3();
    else if (!k)
        sub4();
    else if (k == 1)
        sub5();
    else
        sub6();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
