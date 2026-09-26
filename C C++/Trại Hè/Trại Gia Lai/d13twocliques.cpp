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
const int N = (int) 2e2 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int tcase, n;
bool tt[N], edge[N][N], rev_edge[N][N];

bool conti = true;

void solve(int i, vec(int) a) {
    if (conti == false) return;
    if (i == n) return;

    if (!a.empty()) {
        vec(int) b;
        For(i, 1, n, 1) if (!tt[i])
            b.pub(i);

        bool check = true;

        if (b.empty()) check = false;

        if (check) Rep(i, a.size()) For(j, i + 1, a.size() - 1, 1) if (!edge[a[i]][a[j]] || !edge[a[j]][a[i]]) {
            check = false;
            break;
        }

        if (check) Rep(i, b.size()) For(j, i + 1, b.size() - 1, 1) if (!edge[b[i]][b[j]] || !edge[b[j]][b[i]]) {
            check = false;
            break;
        }

        if (check) {
            Rep(i, a.size()) For(j, i + 1, a.size() - 1, 1) if (!edge[a[i]][a[j]] || !edge[a[j]][a[i]]) {
                check = false;
                break;
            }

            if (check) Rep(i, b.size()) For(j, i + 1, b.size() - 1, 1) if (!edge[b[i]][b[j]] || !edge[b[j]][b[i]]) {
                check = false;
                break;
            }

            if (check) {
                //for (int x : a) cout << x << " ";
                //cout << '\n';
                //for (int x : b) cout << x << " ";
                //cout << '\n';
                conti = false;
                return;
            }
        }
    }

    For(j, i + 1, n, 1) if (!tt[j]) {
        tt[j] = true;
        a.pub(j);
        solve(j, a);
        a.pb();
        tt[j] = false;
    }
}

void solvee(void) {
    memset(tt, false, (n + 1) * sizeof(bool));
    vec(int) luu;
    while (true) {
        int last = luu.size();
        For(i, 1, n, 1) if (!tt[i]) {
            if (!luu.empty()) {
                bool ok = true;
                for (int x : luu) if (!edge[x][i] || !edge[i][x]) {
                    ok = false;
                    break;
                }
                if (ok) {
                    tt[i] = true;
                    luu.pub(i);
                }
            }
            else {
                luu.pub(i);
                tt[i] = true;
            }
        }
        if (luu.size() == last) break;
    }

    //for (int x : luu) cout << x << " ";
    //cout << '\n';

    vec(int) tluu;
    For(i, 1, n, 1) if (!tt[i])
        tluu.pub(i);
    bool check = true;
    Rep(i, tluu.size()) For(j, i + 1, tluu.size() - 1, 1) if (!edge[tluu[i]][tluu[j]] || !edge[tluu[j]][tluu[i]]) {
        check = false;
        break;
    }

    cout << ((check) ? "YES" : "NO") << '\n';
}

bool vit[N];
int col[N];

bool dfs(int u, int val) {
    vit[u] = true;
    col[u] = val;
    For(v, 1, n, 1) if (rev_edge[u][v]) {
        if (!vit[v]) {
            if (!dfs(v, 1 - val)) return false;
        }
        else if (col[v] == col[u])
            return false;
    }
    return true;
}

void solveee(void) {
    For(i, 1, n, 1) For(j, 1, n, 1) if (i != j)
        rev_edge[i][j] = ((edge[i][j] == true) ? false : true);

    memset(vit, false, (n + 1) * sizeof(bool));
    bool check = true;
    For(i, 1, n, 1) if (!vit[i]) if (!dfs(i, 0)) {
        check = false;
        break;
    }

    cout << ((check) ? "YES" : "NO") << '\n';
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> tcase;
    Rep(test_case, tcase) {
        cin >> n;
        For(i, 1, n, 1) For(j, 1, n, 1) {
            int x; cin >> x;
            if (x == 1) edge[i][j] = true;
            else edge[i][j] = false;
        }

        /*vec(int) tmp;
        solve(0, tmp);
        cout << ((conti == true) ? "NO" : "YES") << '\n';
        conti = true;*/

        //solvee();

        solveee();
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
