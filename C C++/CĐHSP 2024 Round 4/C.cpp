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

int n, q, a[N];

void mege(int idx) {
    vec(int) ta, tb, res;
    For(i, 1, idx, 1) ta.pub(a[i]);
    For(i, idx + 1, n, 1) tb.pub(a[i]);
    reverse(all(ta));
    reverse(all(tb));
    while (!ta.empty() && !tb.empty()) {
        if (ta[ta.size() - 1] > tb[tb.size() - 1]) {
            res.pub(tb[tb.size() - 1]);
            tb.pb();
        }
        else {
            res.pub(ta[ta.size() - 1]);
            ta.pb();
        }
    }
    while (!ta.empty()) {
        res.pub(ta[ta.size() - 1]);
        ta.pb();
    }
    while (!tb.empty()) {
        res.pub(tb[tb.size() - 1]);
        tb.pb();
    }
    Rep(i, n) a[i + 1] = res[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    For(i, 1, n, 1) cin >> a[i];

    Rep(query, q) {
        int type, idx; cin >> type >> idx;
        if (type == 1)
            cout << a[idx] << '\n';
        else
            mege(idx);
    }

    return 0;
}
