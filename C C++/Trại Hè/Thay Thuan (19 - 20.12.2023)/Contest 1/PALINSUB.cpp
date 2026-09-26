#include <bits/stdc++.h>
using namespace std;

#define NAME "PALINSUB"
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

int n;
ll ans = 0;
string a[N];

bool check(string s) {
	int i = 0, j = s.length() - 1;
	while (i < j) {
		if (s[i] != s[j])
			return false;
		++i;
		--j;
	}
	return true;
}

void sub1(int i, string st) {
	if (check(st)) {
		++ans;
		ans %= MOD;
	}
	if (i > n)
		return;
	for (int j=i+1; j<=n; ++j)
		sub1(j, st + a[j]);
}

void sub2() {}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP", "r", stdin);
    freopen(NAME".OUT", "w", stdout);

    cin >> n;
    for (int i=1; i<=n; ++i)
    	cin >> a[i];

    //if (n <= 10) {
    	sub1(0, "");
    	cout << ans;
    // }
    // else
    // 	sub2();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
