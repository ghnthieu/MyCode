#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define bk back
#define fr front
#define pb pop_back
#define pf pop_front
#define pub push_back
#define puf push_front
#define __Trung_Hieu___ signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1, kdl2>, kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1, kdl2>, kdl3>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, par[N];
vec(int) nen;

struct Data {
    int l, r, type;
} a[N];

void init(void) {
    For(i, 1, N - 1, 1) par[i] = i;
}

int find_par(int u) {
    if (par[u] == u) return u;
    return par[u] = find_par(par[u]);
}

void add_par(int u, int v) {
    u = find_par(u); v = find_par(v);
    if (u == v) return;
    par[v] = u;
}

void solve(void) {
    sort(all(nen));
    nen.resize(unique(all(nen)) - nen.begin());
    init();

    For(i, 1, m, 1) {
        int l = upper_bound(all(nen), a[i].l - 1) - nen.begin();
        int r = upper_bound(all(nen), a[i].r - 1) - nen.begin();
        a[i] = {l, r, a[i].type};
    }

    For(i, 1, m, 1) {
        int l = a[i].l, r = a[i].r, type = a[i].type;
        if (type == 0) {
            add_par((l - 1) * 2, r * 2);
            add_par((l - 1) * 2 + 1, r * 2 + 1);
        }
        if (type == 1) {
            add_par((l - 1) * 2, r * 2 + 1);
            add_par((l - 1) * 2 + 1, r * 2);
        }
        if (find_par((l - 1) * 2) == find_par((l - 1) * 2 + 1)) {
            cout << i - 1;
            return;
        }
        if (find_par(r * 2) == find_par(r * 2 + 1)) {
            cout << i - 1;
            return;
        }
    }
    cout << m;
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    nen.pub(0); nen.pub(1);
    For(i, 1, m, 1) {
        cin >> a[i].l >> a[i].r;
        string s; cin >> s;
        a[i].type = ((s == "odd") ? 1 : 0);
        nen.pub(a[i].l);
        nen.pub(a[i].r);
    }

    solve();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
