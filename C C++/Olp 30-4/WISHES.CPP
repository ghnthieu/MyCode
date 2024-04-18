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

int n, m, cnt = 0;
vec(int) inp[N];
map <ii(int, int), bool> datung;
bool vit[N];

void dfs(int u) {
    ++cnt;
    vit[u] = true;
    for (int v : inp[u]) {
        if (!vit[v])
            dfs(v);
    }
}

ii(int, int) luubb[N];
void sub1(void) {
    for (int i=1; i<=n; ++i) {
        memset(vit, false, (n + 1) * sizeof(bool));
        cnt = 0;
        dfs(i);
        luubb[i].fi = --cnt;
        luubb[i].se = i;
    }
    sort(luubb + 1, luubb + n + 1, greater <ii(int, int)>());
    memset(vit, false, (n + 1) * sizeof(bool));
    int ans = 0;
    for (int i=1; i<=n; ++i) {
        if (!vit[luubb[i].se]) {
            ++ans;
            dfs(luubb[i].se);
        }
    }
    cout << ans;
}

void sub2(void) {}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("WISHES.INP", "r", stdin);
    freopen("WISHES.OUT", "w", stdout);

    cin >> n >> m;
    for (int i=1; i<=m; ++i) {
        int x, y; cin >> x >> y;
        if (!datung[{x, y}]) {
            inp[x].pub(y);
            datung[{x, y}] = true;
        }
    }

    // if (n <= 1e3 && m <= 1e4)
        sub1();
    // else
        // sub2();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
