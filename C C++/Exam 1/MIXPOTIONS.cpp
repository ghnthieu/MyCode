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
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n;
ll k, chh[N];

void sub1(void) {
    vec(ll) luu;
    luu.pub(0);
    For(i, 1, n, 1) For(j, i + 1, n, 1)
        luu.pub(chh[i] ^ chh[j]);
    sort(all(luu));
    cout << luu[k];
}

map <ll, int> cnt;
map <ll, ll> ans;
vii(ll, int) luu;

void sub3(void) {
    //Init
    For(i, 1, n, 1) ++cnt[chh[i]];
    For(i, 1, n, 1) if (cnt[chh[i]]) {
        luu.pub({chh[i], cnt[chh[i]]});
        cnt[chh[i]] = 0;
    }

    //Calc
    Rep(i, luu.size()) For(j, i, luu.size() - 1, 1) {
        if (luu[i].fi == luu[j].fi)
            ans[0] += (1ll * luu[i].se * (luu[i].se - 1) / 2);
        else
            ans[luu[i].fi + luu[j].fi] += (1ll * luu[i].se * luu[j].se);
    }

    //Ans
    for (auto idx_ans : ans) {
        if (idx_ans.se >= k) {
            cout << idx_ans.fi;
            return;
        }
        k -= idx_ans.se;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("MIXPOTIONS.inp", "r", stdin);
    freopen("MIXPOTIONS.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> k;
    For(i, 1, n, 1) cin >> chh[i];

    if (n <= 1e3)
        sub1();
    else
        sub3();

    return 0;
}
