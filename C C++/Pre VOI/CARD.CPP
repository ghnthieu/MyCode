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
#define For(i, l, r, up) for (long long i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

ll n, m;
ll may[N], nguoi[N];
map <ii(ll, ll), vec(ll)> new_may, new_nguoi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("CARD.INP", "r", stdin);
    freopen("CARD.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    For(i, 1, n, 1) cin >> may[i];
    For(i, 1, n, 1) cin >> nguoi[i];

    For(i, 0, m / n, 1) For(j, 1, n, 1) {
        vec(ll) luu; luu.pub(7);
        For(k, 1, n, 1) luu.pub(may[k]);
        For(k, 1, n, 1) {
            if (k == j) luu[k] += m - n * i;
            luu[k] += i;
        }
        new_may[{i, j}] = luu;
    }

    For(i, 0, m / n, 1) For(j, 1, n, 1) {
        vec(ll) luu; luu.pub(7);
        For(k, 1, n, 1) luu.pub(nguoi[k]);
        For(k, 1, n, 1) {
            if (k == j) luu[k] += m - n * i;
            luu[k] += i;
        }
        new_nguoi[{i, j}] = luu;
    }

    map <ii(int, int), int> cnt;

    for (auto x : new_nguoi) {
        int win = 0;
        for (auto y : new_may) {
            int cnt = 0;
            For(i, 1, n, 1) {
                if (x.se[i] > y.se[i]) ++cnt;
                else --cnt;
            }
            if (cnt > 0) ++win;
        }
        cnt[x.fi] = win;
    }

    int maxx = 0;
    for (auto x : cnt) maximize(maxx, x.se);
    //for (auto x : cnt) cout << x.fi.fi << " " << x.fi.se << " " << x.se << '\n';
    for (auto x : cnt) if (x.se == maxx) {
        cout << x.fi.fi << " " << x.fi.se << " " << x.se;
        return 0;
    }

    return 0;
}
