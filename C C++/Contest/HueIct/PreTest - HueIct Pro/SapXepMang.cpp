#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb pop_back
#define pub push_back
#define __Trung_Hieu___ signed main()
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, k, a[N], par[N], sz[N];
unordered_map<int, vec(int)> grp;

int find_par(int u) {
    if (par[u] == u) return u;
    return par[u] = find_par(par[u]);
}

void add_par(int u, int v) {
    u = find_par(u), v = find_par(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u; sz[u] += v;
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> k;
    For(i, 1, n, 1) {
        cin >> a[i];
        par[i] = i; sz[i] = 1;
    }
    Rep(new_swap, k) {
        int x, y; cin >> x >> y;
        add_par(x, y);
    }

    For(i, 1, n, 1) grp[find_par(i)].pub(i);
    for (auto& [root, arr] : grp) {
        vec(int) luu;
        for (int idx : arr) luu.pub(a[idx]);
        sort(rall(luu, int)); sort(all(arr));
        Rep(i, arr.size()) a[arr[i]] = luu[i];
    }

    For(i, 1, n - 1, 1) if (a[i] < a[i + 1]) {
        cout << "NO";
        return 0;
    }
    cout << "YES";

    return 0;
}

