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

int n, m, cnt[N];
vec(int) inp[N];
bool vit[N], tvit[N];

void dfs(int u) {
    vit[u] = true;
    for (int v : inp[u]) if (!vit[v])
        dfs(v);
}

void tdfs(int u) {
    tvit[u] = true;
    for (int v : inp[u]) if (!tvit[v])
        tdfs(v);
}

void sub1(void) {
    ll ans = 0;
    For(a, 1, n, 1) For(b, a + 1, n, 1) For(c, b + 1, n, 1) {
        memset(vit, false, (n + 1) * sizeof(bool)); dfs(a);
        memset(tvit, false, (n + 1) * sizeof(bool)); tdfs(b);
        if (vit[b] && vit[c] && tvit[a] && tvit[c]) ++ans;
    }
    cout << ans * 2ll;
}

ll nCk(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    if (k == 2) return 1ll * n * (n - 1) / 2ll;
    if (k == 3) return 1ll * n * (n - 1) * (n - 2) / 6ll;
}

void sub2(void) {
    //Th 1
    if (n <= 2) {
        cout << 0;
        return;
    }

    //Th 2
    if (m == n - 1) {
        cout << nCk(n, 3) * 2ll;
        return;
    }

    //Th 3
    if (m == n) {
        cout << 1ll * n * (n - 1) * (n - 2) / 3ll;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("BIKERACE.inp", "r", stdin);
    freopen("BIKERACE.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    bool check_sub2 = true;
    For(i, 1, m, 1) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
        ++cnt[x]; ++cnt[y];
        if (cnt[x] > 2 || cnt[y] > 2) check_sub2 = false;
    }

    if (n <= 50 && m <= 100)
        sub1();
    else if (check_sub2)
        sub2();
    else
        sub1();

    return 0;
}
