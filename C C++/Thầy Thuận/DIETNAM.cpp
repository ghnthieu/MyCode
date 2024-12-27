#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
#define bk back
#define fr front
#define pb pop_back
#define pf pop_front
#define pub push_back
#define puf push_front
#define sz(x) (ll)(x.size())
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define biti(i, x) ((1ll << (i)) & (x))
#define boolbit(i, x) (biti(i, x) != 0)
#define optm(v) v.resize(unique(all(v)) - v.begin())
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define vec(kdl) vector <kdl>
#define ii pair<int,int>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1, kdl2>, kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1, kdl2>, kdl3>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define forr(i, l, r) for (int i = l; i <= r; i++)
#define fodd(i, l, r) for (int i = l; i >= r; i--)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int n;
ll arr[N];
bool nt[N];

void init(void) {
    For(i, 1, N - 1, 1) nt[i] = true;
    nt[0] = nt[1] = false;
    For(i, 2, sqrt(N - 1), 1) if (nt[i]) For(j, i * i, N - 1, i)
        nt[j] = false;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct Dsu {
    vec(int) par;

    void init(int n) {
        par.resize(n + 5, 0);
        For(i, 1, n, 1) par[i] = i;
    }

    int findpar(int u) {
        if (par[u] == u) return u;
        return (par[u] = findpar(par[u]));
    }

    bool addpar(int u, int v) {
        u = findpar(u); v = findpar(v);
        if (u == v) return false;
        par[v] = u; return true;
    }
} dsu;

bool check(ll a, ll b) {
    bool ok = false;
    if (a * a + b * b == sqrt(a * a + b * b) * sqrt(a * a + b * b)) {
        ll c = sqrt(a * a + b * b);
        if (nt[gcd(a, b)] && nt[gcd(b, c)] && nt[gcd(c, a)])
            ok = true;
    }
    if (b * b - a * a == sqrt(b * b - a * a) * sqrt(b * b - a * a)) {
        ll c = sqrt(b * b - a * a);
        if (nt[gcd(a, b)] && nt[gcd(b, c)] && nt[gcd(c, a)])
            ok = true;
    }
    if (a * a - b * b == sqrt(a * a - b * b) * sqrt(a * a - b * b)) {
        ll c = sqrt(a * a - b * b);
        if (nt[gcd(a, b)] && nt[gcd(b, c)] && nt[gcd(c, a)])
            ok = true;
    }
    return ok;
}

void solve(void) {
    init(); dsu.init(n);
    int res = 0;
    For(i, 1, n, 1) For(j, i + 1, n, 1) if (check(arr[i], arr[j])) if (dsu.addpar(i, j))
        ++res;
    cout << res << '\n';
    cout << n - res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) cin >> arr[i];

    solve();

    return 0;
}
