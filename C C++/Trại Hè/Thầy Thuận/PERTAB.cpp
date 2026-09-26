#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
#define bk back
#define fr front
#define pb pop_back
#define pf pop_front
#define pub push_back
#define puf push_front
#define sz(x) (ll)(x.size())
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define biti(i, x) ((1ll << (i)) & (x))
#define boolbit(i, x) (biti(i, x) != 0)
#define optm(v) v.resize(unique(all(v)) - v.begin())
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define vec(kdl) vector <kdl>
#define ii pair<int,int>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1, kdl2>, kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1, kdl2>, kdl3>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define forr(i, l, r) for (int i = l; i <= r; i++)
#define fodd(i, l, r) for (int i = l; i >= r; i--)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e3 + 7;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int n, m, a[N][N], stt[N];
string s;

void sub1(void) {
    For(k, 1, m, 1) {
        if (s[k] == 'R') {
            vec(int) luu;
            For(i, 1, n, 1) luu.pub(a[i][n]);
            Ford(j, n, 2, 1) For(i, 1, n, 1) a[i][j] = a[i][j - 1];
            Rep(i, n) a[i + 1][1] = luu[i];
        }
        else if (s[k] == 'L') {
            vec(int) luu;
            For(i, 1, n, 1) luu.pub(a[i][1]);
            For(j, 1, n - 1, 1) For(i, 1, n, 1) a[i][j] = a[i][j + 1];
            Rep(i, n) a[i + 1][n] = luu[i];
        }
        else if (s[k] == 'D') {
        vec(int) luu;
            For(j, 1, n, 1) luu.pub(a[n][j]);
            Ford(i, n, 2, 1) For(j, 1, n, 1) a[i][j] = a[i - 1][j];
            Rep(j, n) a[1][j + 1] = luu[j];
        }
        else if (s[k] == 'U') {
            vec(int) luu;
            For(j, 1, n, 1) luu.pub(a[1][j]);
            For(i, 1, n - 1, 1) For(j, 1, n, 1) a[i][j] = a[i + 1][j];
            Rep(j, n) a[n][j + 1] = luu[j];
        }
        else if (s[k] == 'I') {
            For(i, 1, n, 1) {
                For(j, 1, n, 1) stt[a[i][j]] = j;
                For(j, 1, n, 1) a[i][j] = stt[j];
            }
        }
        else if (s[k] == 'C') {
            For(j, 1, n, 1) {
                For(i, 1, n, 1) stt[a[i][j]] = i;
                For(i, 1, n, 1) a[i][j] = stt[i];
            }
        }
    }
    For(i, 1, n, 1) {
        For(j, 1, n, 1) cout << a[i][j] << " ";
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PERTAB.INP", "r", stdin);
    freopen("PERTAB.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    For(i, 1, n, 1) For(j, 1, n, 1) cin >> a[i][j];
    cin >> s; s = "h" + s;

    if (m <= 10)
        sub1();

    return 0;
}
