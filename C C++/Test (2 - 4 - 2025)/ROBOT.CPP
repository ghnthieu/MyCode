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
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, s, k, point[N];
ii(int, int) nexto[N];
vii(int, int) inp[N];

void sub1(void) {
    ll have_point = point[s]; nexto[n] = {n + 1, 2303};
    while (have_point >= nexto[s].se && s != n + 1) {
        have_point += point[nexto[s].fi];
        s = nexto[s].fi;
    }
    cout << have_point;
}

bool vit[N];
ll ans = 0;

void dfs(int u) {
    vit[u] = true; ans += point[u]; point[u] = 0;
    for (ii(int, int) v : inp[u]) if (ans >= v.se && !vit[v.fi])
        dfs(v.fi);
}

void sub2(void) {
    For(i, 1, n, 1) {
        ll last = ans;
        dfs(s); memset(vit, false, (n + 1) * sizeof(bool));
        if (ans == last) break;
    }
    cout << ans;
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> s >> k;
    For(i, 1, n, 1) cin >> point[i];
    bool check_sub1 = true;
    For(i, 1, m, 1) {
        int u, v, w; cin >> u >> v >> w;
        inp[u].pub({v, w});
        inp[v].pub({u, w});

        if (u != i && v != i + 1) check_sub1 = false;
        nexto[u] = {v, w};
    }

    if (m == n - 1 && m < 1e3 && k == 0 && check_sub1)
        sub1();
    else
        sub2();

    return 0;
}
