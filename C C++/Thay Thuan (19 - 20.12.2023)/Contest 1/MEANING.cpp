#include <bits/stdc++.h>
using namespace std;

#define NAME "MEANING"
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
const int N = (int) 2e3 + 7;

int n, k;
ll ans = 0;
string s[N];

int demcap(vec(string) v) {
	int cnt = 0;
	for (int i=0; i<v.size(); ++i) {
		for (int j=i+1; j<v.size(); ++j) {
			if (v[i] == v[j]) {
				++cnt;
				if (cnt > k)
					return -1;
			}
		}
	}
	return cnt;
}

void sub12(int i, vec(string) v) {
	if (demcap(v) == k) {
		++ans;
		ans %= MOD;
	}
	if (i > n)
		return;
	for (int j=i+1; j<=n; ++j) {
		v.pub(s[j]);
		sub12(j, v);
		v.pb();
	}
}

void sub3() {}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP", "r", stdin);
    freopen(NAME".OUT", "w", stdout);

    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
    	cin >> s[i];
    	sort(all(s[i]));
    }
    //if (n <= 15 || k <= 3) {
    	vec(string) tmp;
    	sub12(0, tmp);
    	cout << ans;
    // }
    // else
    // 	sub3();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
