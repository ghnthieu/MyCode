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
const int N = (int) 2e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, k, q;
vec(int) inp[N];
ii(int, int) ckhai[N];

void solve(void) {
    For(i, 1, q, 1) {
        int st; cin >> st;
        int ans = 0;
        For(en, 1, n, 1) {
            For(j, 1, k, 1) if ((st <= ckhai[j].fi && ckhai[j].se <= en) || (en <= ckhai[j].fi && ckhai[j].se <= st)) {
                ++ans;
                break;
            }
        }
        cout << ans << " ";
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("dtour.inp", "r", stdin);
    //freopen("dtour.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> k >> q;
    For(i, 1, n - 1, 1) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
    }
    For(i, 1, k, 1) {
        cin >> ckhai[i].fi >> ckhai[i].se;
        if (ckhai[i].fi > ckhai[i].se) swap(ckhai[i].fi, ckhai[i].se);
    }

    solve();

    return 0;
}
