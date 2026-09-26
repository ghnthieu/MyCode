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
const int N = (int) 1e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q, k, l, r, match[N][N];
ii(int, int) que[N];
bool tt[N];
vec(int) ans;

void th1(vec(int) luu) {
    if (!luu.empty() && luu.size() > ans.size()) {
        Rep(i, luu.size() - 1) if (match[luu[i]][luu[i + 1]] == 0) return;
        ans.clear();
        for (int x : luu) ans.pub(x);
    }

    For(i, l, r, 1) if (!tt[i]) {
        tt[i] = true;
        luu.pub(i);
        th1(luu);
        luu.pb();
        tt[i] = false;
    }
}

void th2(vec(int) luu) {
    if (!luu.empty() && luu.size() < ans.size() && luu.size() >= 2) {
        Rep(i, luu.size() - 1) if (match[luu[i]][luu[i + 1]] == 0) return;
        if (match[luu[luu.size() - 1]][luu[0]] == 1) {
            ans.clear();
            for (int x : luu) ans.pub(x);
        }
    }

    For(i, l, r, 1) if (!tt[i]) {
        tt[i] = true;
        luu.pub(i);
        th2(luu);
        luu.pb();
        tt[i] = false;
    }
}

bool cmp(int x, int y) {
    return (match[x][y] == 1);
}

void fth1(void) {
    ans.clear();
    For(i, l, r, 1) ans.pub(i);
    sort(all(ans), cmp);
    cout << r - l + 1 << " ";
    for (int x : ans) cout << x << " ";
}

void fth2(void) {
    For(i, l, r, 1) For(j, i + 1, r, 1) For(k, j + 1, r, 1) {
        if (match[i][j] == 1 && match[j][k] == 1 && match[k][i] == 1) {
            cout << 3 << " " << i << " " << j << " " << k;
            return;
        }
        if (match[i][k] == 1 && match[k][j] == 1 && match[j][i] == 1) {
            cout << 3 << " " << i << " " << k << " " << j;
            return;
        }
        if (match[j][i] == 1 && match[i][k] == 1 && match[k][j] == 1) {
            cout << 3 << " " << j << " " << i << " " << k;
            return;
        }
        if (match[j][k] == 1 && match[k][i] == 1 && match[i][j] == 1) {
            cout << 3 << " " << j << " " << k << " " << i;
            return;
        }
        if (match[k][i] == 1 && match[i][j] == 1 && match[j][k] == 1) {
            cout << 3 << " " << k << " " << i << " " << j;
            return;
        }
        if (match[k][j] == 1 && match[j][i] == 1 && match[i][k] == 1) {
            cout << 3 << " " << k << " " << j << " " << i;
            return;
        }
    }
    cout << -1;
}

/*1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1*/

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

    cin >> n >> q >> k;
    For(i, 1, q, 1) cin >> que[i].fi >> que[i].se;
    For(i, 1, n, 1) For(j, 1, n, 1) cin >> match[i][j];

    For(i, 1, q, 1) {
        l = que[i].fi; r = que[i].se;

        if (n <= 10 && k == 1) {
            vec(int) tmp; ans.clear();
            th1(tmp);
            cout << ans.size() << " ";
            for (int x : ans) cout << x << " ";
        }
        else if (k == 1)
            fth1();

        if (n <= 10 && k == 2) {
            vec(int) tmp; ans.clear();
            For(i, 1, n + 1, 1) ans.pub(i);
            th2(tmp);
            if (ans.empty() || ans.size() == n + 1) {
                cout << -1 << '\n';
                continue;
            }
            cout << ans.size() << " ";
            for (int x : ans) cout << x << " ";
        }
        else if (k == 2)
            fth2();

        cout << '\n';
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
