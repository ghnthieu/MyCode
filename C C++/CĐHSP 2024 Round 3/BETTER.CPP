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
const int N = (int) 2e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

struct Data {
    int ton, van, anh;
};

int n, q, need = 0;
Data stu[N];
vec(int) better[N];
bool vit[N], check = false;

void dfs(int u) {
    if (check) return;
    if (u == need) { check = true; return; }
    vit[u] = true;
    for (int v : better[u]) if (!vit[v])
        dfs(v);
}

void solve(int x, int y) {
    need = y;
    check = false;
    memset(vit, false, (n + 1) * sizeof(bool));
    dfs(x);

    cout << ((check) ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("BETTER.INP", "r", stdin);
    freopen("BETTER.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) cin >> stu[i].ton >> stu[i].van >> stu[i].anh;

    //Init
    For(i, 1, n, 1) For(j, 1, n, 1) if (i != j) {
        if (stu[i].ton < stu[j].ton && stu[i].van < stu[j].van ||
            stu[i].van < stu[j].van && stu[i].anh < stu[j].anh ||
            stu[i].anh < stu[j].anh && stu[i].ton < stu[j].ton)
        better[i].pub(j);
    }

    cin >> q;
    Rep(query, q) {
        int x, y; cin >> x >> y;
        solve(x, y);
    }

    return 0;
}
