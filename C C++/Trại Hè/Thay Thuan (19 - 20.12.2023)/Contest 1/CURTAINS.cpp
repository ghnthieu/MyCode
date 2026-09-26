#include <bits/stdc++.h>
using namespace std;

#define NAME "CURTAINS"
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
const int N = (int) 5e5 + 7;

int n, m, q, che1[N];
ii(int, int) che[N];

int tknp(int l, int r, int x) {
	int res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (che1[mid] == x) {
			res = mid;
			l = mid + 1;
		}
		else if (che1[mid] < x)
			l = mid + 1;
		else 
			r = mid - 1;
	}
	return res;
}

void sub1(int l, int r) {
	int tmp = upper_bound(che1 + 1, che1 + m + 1, l - 1) - che1;
	if (che1[tmp] != l) {
		cout << "NO" << '\n';
		return;
	}
	int nxt = che[tmp].se;
	bool check = false;
	for (int i=tmp; i<=m; ++i) {
		if (che[i].fi <= nxt + 1) {
			if (che[i].se <= r) {
				nxt = max(nxt, che[i].se);
				if (nxt == r) {
					cout << "YES" << '\n';
					return;
				}
			}
		}
	}
	cout << "NO" << '\n';
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> n >> m >> q;
    for (int i=1; i<=m; ++i) {
    	cin >> che[i].fi >> che[i].se;
    	che1[i] = che[i].fi;
    }
    sort(che + 1, che + m + 1);
    sort(che1 + 1, che1 + m + 1);
    while (q--) {
    	int l, r; cin >> l >> r;
    	sub1(l, r);
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
