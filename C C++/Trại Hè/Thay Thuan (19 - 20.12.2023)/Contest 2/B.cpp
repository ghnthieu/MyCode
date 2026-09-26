#include <bits/stdc++.h>
using namespace std;

#define NAME "RECTAREA"
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
#define iiii(kdl1, kdl2, kdl3, kdl4) pair <pair <kdl1, kdl2>,pair <kdl3, kdl4>>
#define viiii(kdl1, kdl2, kdl3, kdl4) vector <pair <pair <kdl1, kdl2>,pair <kdl3, kdl4>>>

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
typedef long double lde;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;

int n;
ll ans = 0;
ii(int, int) it[8 * N];
viiii(int, int, int, int) inp;		

void update(int u, int l, int r, int i, int j, int v) {
	if (r <= i || j <= l)
		return;
	if (i <= l && r <= j)
		it[u].fi += v;
	else {
		int mid = (l + r) >> 1;
		update(u << 1, l, mid, i, j, v);
		update((u << 1) | 1, mid, r, i, j, v);
	}
	if (it[u].fi == 0)
		it[u].se = it[u << 1].se + it[(u << 1) | 1].se;
	else
		it[u].se = r - l;
}

void solve() {
	int tmp1, tmp2, tt, leng, tmpp; 
	for (int i=0; i<((int) inp.size()-1); ++i) {
		tmp1 = inp[i].se.fi; tmp2 = inp[i].se.se;
		tt = inp[i].fi.se;
		update(1, 0, N, tmp1, tmp2, tt);
		leng = inp[i + 1].fi.fi - inp[i].fi.fi;
		tmpp = it[1].se;
		ans += leng * tmpp;
	}
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> n;
    for (int i=0; i<n; ++i) {
    	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    	inp.pub({{x1, 1}, {y1, y2}});
    	inp.pub({{x2, -1}, {y1, y2}});
    }
    sort(all(inp));

    solve();
    cout << ans;

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
