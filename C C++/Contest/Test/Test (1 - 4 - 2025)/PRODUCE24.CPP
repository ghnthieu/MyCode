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

int n, m, k, have[N];
vec(int) inp[N];

void sub1(void) {
    ll ans = 0;
    sort(have + 1, have + n + 1, greater <int> ());
    For(i, 1, (int) min(n, k), 1) ans += have[i];
    cout << ans;
}

bool vit[N];
int give_end = 0;

void dfs(int u) {
    vit[u] = true;
    for (int v : inp[u]) if (!vit[v]) {
        maximize(give_end, have[v]);
        dfs(v);
    }
}

void sub2(void) {
    ll ans = 0;
    For(i, 1, n, 1) {
        memset(vit, false, (n + 1) * sizeof(bool)); give_end = 0; dfs(i);
        maximize(ans, 1ll * have[i] + give_end);
    }
    cout << ans;
}

vec(vec(int)) luu;

void tdfs(int u, vec(int) &tluu) {
    vit[u] = true;
    for (int v : inp[u]) if (!vit[v]) {
        tluu.pub(v); luu.pub(tluu);
        tdfs(v, tluu);
        tluu.pb();
    }
}

bool cmp(int a, int b) {
    return (have[a] >= have[b]);
}

void sub3(void) {
    For(i, 1, n, 1) {
        memset(vit, false, (n + 1) * sizeof(bool));
        vec(int) tmp; tmp.pub(i); tdfs(i, tmp);
    }

    /*Rep(i, luu.size()) {
        sort(all(luu[i]), cmp);
        for (int x : luu[i]) cout << x << " ";
        cout << '\n';
    }*/

    ll ans = 0;
    Rep(i, luu.size()) {
        sort(all(luu[i]), cmp);
        ll sum = 0;
        For(j, 0, min((int) luu[i].size() - 1, k - 1), 1)
            sum += have[luu[i][j]];
        maximize(ans, sum);
    }
    cout << ans;
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("PRODUCE24.INP", "r", stdin);
    freopen("PRODUCE24.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> k;
    For(i, 1, n, 1) cin >> have[i];
    bool check_sub1 = true;
    For(i, 1, m, 1) {
        int u, v; cin >> u >> v;
        inp[u].pub(v);
        if ((u != i || v != i + 1) && i < n) check_sub1 = false;
    }

    if (n <= 20 && m <= 20 && check_sub1)
        sub1();
    else if (n <= 1e2 && m <= 1e2 && k == 2)
        sub2();
    else
        sub3();

    return 0;
}
