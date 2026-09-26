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
const int INF = (int) 2e9 + 7;
const int N = (int) 5e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, k;
vec(int) inp[N], duong_a, duong_b, cnt_a, cnt_b;
double ans[N];

void bfs(int st, vec(int) &duong, vec(int) &cnt) {
    queue <int> q; q.push(st);
    cnt.assign(n + 5, 0);
    duong.assign(n + 5, INF);
    duong[st] = 0; cnt[st] = 1;
    while (!q.empty()) {
        int u = q.fr(); q.pop();
        for (int v : inp[u]) {
            if (duong[v] > duong[u] + 1) {
                duong[v] = duong[u] + 1;
                cnt[v] = cnt[u];
                q.push(v);
            }
            else if (duong[v] == duong[u] + 1)
                cnt[v] += cnt[u];
        }
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TRAINCENTRE.INP", "r", stdin);
    freopen("TRAINCENTRE.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    For(i, 1, m, 1) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
    }
    cin >> k;
    For(i, 1, k, 1) {
        int x, y; cin >> x >> y;
        bfs(x, duong_a, cnt_a); bfs(y, duong_b, cnt_b);
        int tmp = cnt_a[y];
        Rep(i, n) if (duong_a[i] + duong_b[i] == duong_a[y])
            ans[i] += (double) cnt_a[i] * (double) cnt_b[i] / (double) tmp;
    }

    int mx = 0;
    For(i, 1, n - 1, 1) if (ans[mx] < ans[i])
        mx = i;
    cout << mx;

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
