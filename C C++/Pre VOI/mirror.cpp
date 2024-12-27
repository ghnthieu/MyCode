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
const int N = (int) 25e4 + 7;
const int M = (int) 1e7 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q;
multiset <ll> muti;
ll ans[M + 7];

void init(void) {
    ans[0] = 0; bool huong = true; ll idx = 0;
    For(i, 1, M, 1) {
        if (huong == true) ++idx;
        else if (huong == false) --idx;

        ans[i] = idx;

        if (muti.find(idx) != muti.end()) {
            if (huong == true) huong = false;
            else huong = true;
            muti.erase(muti.find(idx));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("mirror.inp", "r", stdin);
    freopen("mirror.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    For(i, 1, n, 1) {
        char type; ll val, len; cin >> type >> val >> len;
        if (type == 'L') { For(i, 1, len, 1) muti.insert((-1ll) * i * val); }
        else { For(i, 1, len, 1) muti.insert(1ll * i * val); }
    }

    init();

    Rep(query, q) {
        ll sec; cin >> sec;
        cout << ans[sec] << '\n';
    }

    return 0;
}
