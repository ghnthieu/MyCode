#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pub push_back
#define pb pop_back
#define mask(i) (1ll << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n  = (n); i < _n; ++i)
template <typename T1, typename T2> bool maximize(T1 &x, T2 y) { if (x < y) { x = y; return true; } return false; }
template <typename T1, typename T2> bool minimize(T1 &x, T2 y) { if (x > y) { x = y; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 3e5 + 7;

int n, k, a[N];
bool choose[N];

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

vii(int, ll) inp[N];
ii(int, int) edge[N];
map <ii(int, int), ll> w;
int cnt = 0;

void init(void) {
    For(i, 1, n, 1) For(j, i + 1, n, 1) {
        edge[++cnt] = {i, j};
        if (j == i + 1) {
            inp[i].pub({j, lcm(a[i], a[j])});
            inp[j].pub({i, lcm(a[i], a[j])});
            w[{i, j}] = lcm(a[i], a[j]); w[{j, i}] = lcm(a[i], a[j]);
        }
        else {
            ll dist = lcm(a[i], a[i + 1]);
            For(k, i + 2, j, 1) dist = lcm(dist, a[k]);
            inp[i].pub({j, dist});
            inp[j].pub({i, dist});
            w[{i, j}] = dist; w[{j, i}] = dist;
        }
    }
}

bool vit[N];
map <ii(int, int), bool> can;

void dfs(int u) {
    vit[u] = true;
    for (ii(int, ll) v : inp[u]) if (!vit[v.fi] && !can[{u, v.fi}] && !can[{v.fi, u}])
        dfs(v.fi);
}

void sub1(void) {
    init();
    ll ans = LLONG_MAX; int cnt_ans = 0; vii(int, int) luu_ans;
    For(k, 0, mask(cnt) - 1, 1) {
        can.clear();
        Rep(i, cnt) if (bit(k, i)) {
            can[{edge[i + 1].fi, edge[i + 1].se}] = true;
            can[{edge[i + 1].se, edge[i + 1].fi}] = true;
        }
        memset(vit, false, (n + 1) * sizeof(bool));
        For(i, 1, n, 1) if (choose[i]) {
            dfs(i);
            break;
        }
        bool ok = true;
        For(i, 1, n, 1) if (choose[i] && !vit[i]) {
            ok = false;
            break;
        }
        if (ok) {
            //Rep(i, cnt) cout << bit(k, i) << " ";
            //cout << '\n';
            ll sum = 0;
            For(i, 1, cnt, 1) if (!can[{edge[i].fi, edge[i].se}])
                sum += w[{edge[i].fi, edge[i].se}];
            if (minimize(ans, sum)) {
                cnt_ans = 0;
                Rep(i, cnt) if (!bit(k, i)) ++cnt_ans;
                luu_ans.clear();
                For(i, 1, cnt, 1) if (!can[{edge[i].fi, edge[i].se}])
                    luu_ans.pub({edge[i].fi, edge[i].se});
            }
        }
    }
    cout << ans << '\n' << cnt_ans << '\n';
    for (ii(int, int) x : luu_ans) cout << x.fi << " " << x.se << '\n';
}

void sub2(void) {}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("LCMGRAPH.INP", "r", stdin);
    freopen("LCMGRAPH.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> k;
    For(i, 1, n, 1) cin >> a[i];
    memset(choose, false, (n + 1) * sizeof(bool));
    For(i, 1, k, 1) {
        int x; cin >> x;
        choose[x] = true;
    }

    //if (n <= 6)
        sub1();
    //else
    //    sub2();

    return 0;
}
