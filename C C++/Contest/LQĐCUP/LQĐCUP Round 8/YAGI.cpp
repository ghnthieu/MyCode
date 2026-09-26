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
const int N = (int) 2e1 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, k, gift[N], sum[N][N];
char a[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("YAGI.inp", "r", stdin);
    freopen("YAGI.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    int si, sj;
    For(i, 1, n, 1) For(j, 1, m, 1) {
        cin >> a[i][j];
        if ('0' <= a[i][j] && a[i][j] <= '9') maximize(k, a[i][j] - '0');
        if (a[i][j] == 'S') { si = i; sj = j; }
    }
    For(i, 1, k, 1) cin >> gift[i];

    For(i, 1, n, 1) For(j, 1, m, 1) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        if ('0' <= a[i][j] && a[i][j] <= '9') sum[i][j] += gift[a[i][j] - '0'];
    }

    /*For(i, 1, n, 1) {
        For(j, 1, m, 1) cout << sum[i][j] << " ";
        cout << '\n';
    }*/
    //cout << sum[h2][c2] - sum[h1-1][c2] - sum[h2][c1-1] + sum[h1-1][c1-1] << endl;

    //cout << sum[4][5] - sum[1][5] - sum[4][1] + sum[1][1] << '\n';

    int ans = INT_MIN;
    For(i, 1, n, 1) For(j, 1, m, 1) {
        if (si == i || sj == j)
            maximize(ans, 0);
        else if (si < i) {
            int itl = si, jtl = sj, itr = si, jtr = j, idl = i, jdl = sj, idr = i, jdr = j; // si < i && sj < j
            if (sj > j) { // si < i && sj > j
                swap(itl, itr); swap(jtl, jtr);
                swap(idl, idr); swap(jdl, jdr);
            }
            bool check = true;
            For(ti, itl, idr, 1) {
                if (!check) break;
                For(tj, jtl, jdr, 1) if (a[ti][tj] == 'B') { check = false; break; }
            }
            if (!check) continue;
            int kc = jtr - jtl;
            For(j, jtl, jtr, 1) if (a[itl][j] != '.' && a[itl][j] != 'S') { check = false; break; }
            if (!check) continue;
            kc += idr - itr;
            For(i, itr, idr, 1) if (a[i][jtr] != '.' && a[i][jtr] != 'S') { check = false; break; }
            if (!check) continue;
            kc += jdr - jdl;
            For(j, jdl, jdr, 1) if (a[idl][j] != '.' && a[idl][j] != 'S') { check = false; break; }
            if (!check) continue;
            kc += idl - itl;
            For(i, itl, idl, 1) if (a[i][jtl] != '.' && a[i][jtl] != 'S') { check = false; break; }
            if (!check) continue;
            if (check) maximize(ans, sum[idr][jdr] - sum[itl - 1][jdr] - sum[idr][jtl - 1] + sum[itl - 1][jtl - 1] - kc);
        }
        else if (si > i) {
            int idl = si, jdl = sj, idr = si, jdr = j, itl = i, jtl = sj, itr = i, jtr = j; // si > i && sj < j
            //cout << itl << " " << jtl << " " << idr << " " << jdr << '\n';
            if (sj > j) { // si > i && sj > j
                swap(itl, itr); swap(jtl, jtr);
                swap(idl, idr); swap(jdl, jdr);
            }
            bool check = true;
            For(ti, itl, idr, 1) {
                if (!check) break;
                For(tj, jtl, jdr, 1) if (a[ti][tj] == 'B') { check = false; break; }
            }
            if (!check) continue;
            int kc = jtr - jtl;
            For(j, jtl, jtr, 1) if (a[itl][j] != '.' && a[itl][j] != 'S') { check = false; break; }
            if (!check) continue;
            kc += idr - itr;
            For(i, itr, idr, 1) if (a[i][jtr] != '.' && a[i][jtr] != 'S') { check = false; break; }
            if (!check) continue;
            kc += jdr - jdl;
            For(j, jdl, jdr, 1) if (a[idl][j] != '.' && a[idl][j] != 'S') { check = false; break; }
            if (!check) continue;
            kc += idl - itl;
            For(i, itl, idl, 1) if (a[i][jtl] != '.' && a[i][jtl] != 'S') { check = false; break; }
            if (!check) continue;
            if (check) maximize(ans, sum[idr][jdr] - sum[itl - 1][jdr] - sum[idr][jtl - 1] + sum[itl - 1][jtl - 1] - kc);
        }
    }
    cout << ans;

    return 0;
}
