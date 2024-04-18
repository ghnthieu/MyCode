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
const int N = (int) 3e6 + 7;

class DisjointSet {
private:
    vec(int) lab;

public:
    DisjointSet(int n = 0) {
        lab.assign(n + 7, -1);
    }

    int find(int x) {
        return ((lab[x] < 0) ? x : (lab[x] = find(lab[x])));
    }

    bool join(int u, int v) {
        int x = find(u), y = find(v);
        if (x == y) return false;
        if (lab[x] > lab[y]) swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }

};

int ondinh, n, a[N], treemx[4 * N], treemn[4 * N];

void build(int id, int l, int r) {
    if (l == r) {
        treemx[id] = a[l];
        treemn[id] = a[l];
    }
    else {
        int m = l + r >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        treemx[id] = max(treemx[id << 1], treemx[id << 1 | 1]);
        treemn[id] = min(treemn[id << 1], treemn[id << 1 | 1]);
    }
}

int getmx(int id, int l, int r, int u, int v) {
    if (u > v)
        return INT_MIN;
    if (l == u && r == v)
        return treemx[id];
    else {
        int m = l + r >> 1;
        return max(getmx(id << 1, l, m, u, min(m, v)), getmx(id << 1 | 1, m + 1, r, max(m + 1, u), v));
    }
}

int getmn(int id, int l, int r, int u, int v) {
    if (u > v)
        return INT_MAX;
    if (l == u && r == v)
        return treemn[id];
    else {
        int m = l + r >> 1;
        return min(getmn(id << 1, l, m, u, min(m, v)), getmn(id << 1 | 1, m + 1, r, max(m + 1, u), v));
    }
}

void sub12(void) {
    build(1, 1, n);
    int i = 1, j = 1, ans = 0;
    while (j <= n) {
        if (abs(getmx(1, 1, n, i, j) - getmn(1, 1, n, i, j)) <= ondinh) {
            maximize(ans, j - i + 1);
            ++j;
        }
        else if (i < j && i <= n)
            ++i;
    }
    cout << ans;
}

void sub3(void) {
    deque <int> dmx, dmn;
    int i = 1, j = 1, ans = 0;
    while (j <= n) {
        while (dmn.size() && a[dmn.bk()] >= a[j])
            dmn.pb();
        dmn.pub(j);
        while (dmx.size() && a[dmx.bk()] <= a[j])
            dmx.pb();
        dmx.pub(j);
        if (abs(a[dmx.fr()] - a[dmn.fr()]) <= ondinh) {
            maximize(ans, j - i + 1);
            ++j;
        }
        else {
            ++i;
            if (dmn.fr() < i)
                dmn.pf();
            if (dmx.fr() < i)
                dmx.pf();
        }
    }
    cout << ans;
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);

    cin >> ondinh >> n;
    for (int i=1; i<=n; ++i)
        cin >> a[i];

    if (n <= 5e5)
        sub12();
    else
        sub3();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
