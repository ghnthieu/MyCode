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
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m;
vec(vec(int)) a;
int dx[4] = {1, 0, 0, -1},
    dy[4] = {0, 1, -1, 0};

int calc(int x, int y) {
    return (x - 1) * m + y;
}

bool check(int x, int y) {
    if (1 <= x && x <= n && 1 <= y && y <= m) return true;
    return false;
}

ll duong[N];
bool ck[N], tcheck[N];

void solve(int s, int t) {
    memset(duong, 0x3f, sizeof(duong)); duong[calc(s, t)] = 0;
    priority_queue <ii(ll, ii(int, int)), vii(ll, ii(int, int)), greater <ii(ll, ii(int, int))>> pq; pq.push({0, {s, t}});
    ll ans = 0;
    while (!pq.empty()) {
        ii(ll, ii(int, int)) top = pq.top(); pq.pop();
        ll val = top.fi; int x = top.se.fi, y = top.se.se;
        if (duong[calc(x, y)] < val) continue;
        if (tcheck[calc(x, y)]) {
            if (ck[calc(x, y)]) continue;
            ans += duong[calc(x, y)];
            ck[calc(x, y)] = true;
            duong[calc(x, y)] = 0;
        }
        Rep(i, 4) {
            int tx = x + dx[i], ty = y + dy[i];
            if (check(tx, ty)) if (minimize(duong[calc(tx, ty)], duong[calc(x, y)] + a[tx][ty]))
                pq.push({duong[calc(tx, ty)], {tx, ty}});
        }
    }
    cout << ans;
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m; int st, en, cnt = 0;
    a.resize(n + 5);
    For(i, 1, n, 1) {
        a[i].resize(m + 5);
        For(j, 1, m, 1) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                tcheck[calc(i, j)] = true;
                st = i; en = j;
                ++cnt;
            }
        }
    }

    solve(st, en);

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
