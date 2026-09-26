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

int n, m, k, low[N], num[N], tid[N], cnt = 0, tpltm = 0;
vec(int) inp[N];
stack <int> st;

vec(int) luu[N];
void dfs(int u) {
    low[u] = num[u] = ++cnt;
    st.push(u);
    for (int v : inp[u]) {
        if (!tid[v]) {
            if (!num[v]) {
                dfs(v);
                minimize(low[u], low[v]);
            }
            else
                minimize(low[u], num[v]);
        }
    }
    if (low[u] == num[u]) {
        ++tpltm;
        int v = 0;
        do {
            v = st.top(); st.pop();
            tid[v] = tpltm;
            luu[tpltm].pub(v);
        } while (u != v);
    }
}

void sub1(void) {   
    for (int i=1; i<=n; ++i) {
        if (!num[i])
            dfs(i);
    }
    int mx = 0;
    for (int i=1; i<=tpltm; ++i)
        maximize(mx, (int) luu[i].size());
    cout << mx;
}

vec(int) tluu[N];
bool cmp(int a, int b) {
    if (luu[tid[a]].size() == luu[tid[b]].size())
        return (a < b);
    return (luu[tid[a]].size() > luu[tid[b]].size());
}

bool check[N];
void sub2(void) {
    for (int i=1; i<=n; ++i) {
        if (!num[i])
            dfs(i);
    }
    int mx = 0, cs = 0;
    for (int i=1; i<=n; ++i) {
        tluu[(int) inp[i].size()].pub(i);
        if (maximize(mx, (int) tluu[(int) inp[i].size()].size()))
            cs = (int) inp[i].size();
    }
    sort(all(tluu[cs]), cmp);
    int ans = 0;
    memset(check, false, (n + 1) * sizeof(bool));
    for (int i=0; i<tluu[cs].size(); ++i) {
        if (k <= 0)
            break;
        if (!check[tluu[cs][i]]) {
            --k;
            ans += (int) luu[tid[tluu[cs][i]]].size();
            for (int x : luu[tid[tluu[cs][i]]])
                check[x] = true;
        }
    }
    cout << ans;
}

bool vit[N];
set <int> tst[N];
void tdfs(int u, int par) {
    vit[u] = true;
    tst[inp[u].size()].insert(par);
    for (int v : inp[u]) {
        if (!vit[v])
            tdfs(v, par);
    }
    ++cnt;
}

bool comp(int a, int b) {
    return (tid[a] > tid[b]);
}

void sub3(void) {
    for (int i=1; i<=n; ++i) {
        if (!vit[i]) {
            cnt = 0;
            tdfs(i, i);
            tid[i] = cnt;
        }
    }
    ll ans = 0;
    for (int i=0; i<=n; ++i) {
        vec(int) tluut;
        for (auto x : tst[i])
            tluut.pub(x);
        if (tluut.empty()) continue;
        sort(all(tluut), comp);
        ll res = 0;
        res += tid[tluut[0]];
        for (int j=1; j<tluut.size() && j<k; ++j)
            res += tid[tluut[j]];
        maximize(ans, res);
    }
    cout << ans;
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("DUONGONG.INP", "r", stdin);
    freopen("DUONGONG.OUT", "w", stdout);

    cin >> n >> m >> k;
    for (int i=1; i<=m; ++i) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
    }

    if (k == 1)
        sub1();
    else if (n <= 1e2)
        sub2();
    else
        sub3();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
