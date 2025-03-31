#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb pop_back
#define pub push_back
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
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

ll n, q, mon[N], sum_mon[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    ll sum_day = 0;
    For(i, 1, n, 1) {
        cin >> mon[i];
        sum_day += mon[i];
        sum_mon[i] = sum_mon[i - 1] + mon[i];
    }

    Rep(query, q) {
        ll st_d, st_m, st_y, en_d, en_m, en_y; cin >> st_d >> st_m >> st_y >> en_d >> en_m >> en_y;
        ll ve_st = (st_y - 1) * sum_day, ve_en = (en_y - 1) * sum_day;
        ve_st += sum_mon[st_m - 1]; ve_en += sum_mon[en_m - 1];
        ve_st += st_d; ve_en += en_d;
        ll ans = ve_en - ve_st + 1;
        cout << ans << '\n';
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb pop_back
#define pub push_back
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
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

ll n, q, mon[N], sum_mon[N];

ll calc_y(ll st, ll en) {
    return (en - st + 1) * sum_mon[n];
}

ll calc_m(ll st, ll en) {
    return sum_mon[en] - sum_mon[st - 1];
}

ll calc_d(ll st, ll en) {
    return en - st + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    ll sum_day = 0;
    For(i, 1, n, 1) {
        cin >> mon[i];
        sum_day += mon[i];
        sum_mon[i] = sum_mon[i - 1] + mon[i];
    }

    Rep(query, q) {
        ll st_d, st_m, st_y, en_d, en_m, en_y; cin >> st_d >> st_m >> st_y >> en_d >> en_m >> en_y;

        if (st_y != en_y) {
            cout << calc_y(st_y + 1, en_y - 1) + calc_m(st_m + 1, n) + calc_d(st_d, mon[st_m]) + calc_d(1, en_d) << '\n';
            continue;
        }

        if (st_m != en_m){
            cout << calc_m(st_m + 1 , en_m - 1) + calc_d(st_d , mon[st_m]) + calc_d(1, en_d) << '\n';
            continue;
        }

        cout << calc_d(st_d, en_d) << '\n';
    }

    return 0;
}
