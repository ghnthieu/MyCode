#include <bits/stdc++.h>
using namespace std;

#define NAME ""
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
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define vec(kdl) vector <kdl>
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1,kdl2>,kdl3>>
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
typedef long double lde;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;

int n, m, start, k, a[N], cnt = 0;
vii(int, int) inp[N];
ll diem = 0;
bool vit[N];

void dfs(int u) {
    if (!vit[u]) {
        ++cnt;
        diem += a[u];
        vit[u] = true;
    }
    for (ii(int, int) v : inp[u]) {
        if (v.se <= diem && !vit[v.fi])
            dfs(v.fi);
    }
}

void sub1(void) {
    cnt = 1;
    ll diem = a[start], last = 0;
    int l = start - 1, r = start + 1;
    while (true) {
        while (l >= 1 && inp[l][0].se <= diem) {
            ++cnt;
            diem += a[l];
            --l;
        }
        while (r <= n && inp[r][0].se <= diem) {
            ++cnt;
            diem += a[r];
            ++r;
        }
        if (last == diem)
            break;
        last = diem;
    }
    cout << cnt;
}

void sub2(void) {
    memset(vit, false, sizeof(vit));
    int last = -1;
    for (int i=1; i<=n; ++i) {
        dfs(start);
        if (last == diem)
            break;
        last = diem;
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);

    cin >> n >> m >> start >> k;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    bool dk = true;
    for (int i=1; i<=m; ++i) {
        int x, y, w; cin >> x >> y >> w;
        if (x != i || y != i + 1)
            dk = false;
        inp[x].pub({y, w});
        inp[y].pub({x, w});
    }

    if (m == n - 1 && n <= 1e3 && dk)
        sub1();
    else
        sub2();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
