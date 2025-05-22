#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb pop_back
#define pub push_back
#define __Trung_Hieu___ signed main()
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
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

const int MAX = 205;
bool ok[MAX][MAX];
int n, m, k;
ii(int, int) save[20];
string res = "";
ii(int, int) nxt[MAX][MAX];
bool check[MAX][MAX];
int row[4] = {-1, 0, 1, 0}, col[4] = {0, 1, 0, -1};
char wow[4] = {'U', 'R', 'D', 'L'};

void build() {
    queue<ii(int, int)> qu;
    qu.push({1, 1});
    check[1][1] = 1;
    while (!qu.empty()) {
        ii(int, int) tmp = qu.front();
        qu.pop();
        For(i, 0, 3, 1) {
            int x = tmp.fi + row[i], y = tmp.se + col[i];
            if (!ok[x][y] && !check[x][y]) {
                check[x][y] = 1;
                nxt[x][y] = tmp;
                qu.push({x, y});
            }
        }
    }
}

string calc(ii(int, int) x, ii(int, int) y) {
    string tmp = "";
    while (x.fi + x.se != 2 || y.fi + y.se != 2) {
        if (x.fi + x.se == 2) swap(x, y);
        string ans = "";
        while (x.fi + x.se != 2) {
            ii(int, int) p = nxt[x.fi][x.se];
            int le = x.fi - p.fi, ri = x.se - p.se;
            For(i, 0, 3, 1) if (le == -row[i] && ri == -col[i]) ans += wow[i];
            x = p;
        }
        for (auto P : ans) {
            For(i, 0, 3, 1) if (P == wow[i]) {
                int le = y.fi + row[i], ri = y.se + col[i];
                if (!ok[le][ri]) y = {le, ri};
            }
        }
        tmp += ans;
    }
    return tmp;
}

void solve(void) {
    build();
    ii(int, int) duytri = save[1];
    For(i, 1, k, 1) {
        ii(int, int) &y = save[i];
        for (auto P : res) {
            For(j, 0, 3, 1) if (P == wow[j]) {
                int le = y.fi + row[j], ri = y.se + col[j];
                if (!ok[le][ri]) y = {le, ri};
            }
        }
        res += calc(duytri, save[i]);
        duytri = {1, 1};
    }
    cout << res;
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);

    memset(ok, 1, sizeof(ok));
    cin >> n >> m >> k;
    For(i, 1, n, 1) For(j, 1, m, 1) cin >> ok[i][j];
    For(i, 1, k, 1) {
        cin >> save[i].fi >> save[i].se;
        save[i].fi++, save[i].se++;
    }

    solve();

    return 0;
}
