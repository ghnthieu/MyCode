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
const int N = (int) 1e2 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n;
ll start_time, end_time, exam_time;
ii(ll, ll) good[N];

void sub1(void) {
    ll ans = LLONG_MAX;

    //Th 1 mon 1, mon 2, mon 3
    ll sum = 0, res = 0;
    res += abs(start_time + good[1].fi - exam_time) * good[1].se;
    sum += start_time + good[1].fi;
    res += abs(sum + good[2].fi - exam_time) * good[2].se;
    sum += good[2].fi;
    res += abs(sum + good[3].fi - exam_time) * good[3].se;
    minimize(ans, res);

    //Th 2 mon 1, mon 3, mon 2
    sum = 0, res = 0;
    res += abs(start_time + good[1].fi - exam_time) * good[1].se;
    sum += start_time + good[1].fi;
    res += abs(sum + good[3].fi - exam_time) * good[3].se;
    sum += good[3].fi;
    res += abs(sum + good[2].fi - exam_time) * good[2].se;
    minimize(ans, res);

    //Th 3 mon 2, mon 1, mon 3
    sum = 0, res = 0;
    res += abs(start_time + good[2].fi - exam_time) * good[2].se;
    sum += start_time + good[2].fi;
    res += abs(sum + good[1].fi - exam_time) * good[1].se;
    sum += good[1].fi;
    res += abs(sum + good[3].fi - exam_time) * good[3].se;
    minimize(ans, res);

    //Th 4 mon 2, mon 3, mon 1
    sum = 0, res = 0;
    res += abs(start_time + good[2].fi - exam_time) * good[2].se;
    sum += start_time + good[2].fi;
    res += abs(sum + good[3].fi - exam_time) * good[3].se;
    sum += good[3].fi;
    res += abs(sum + good[1].fi - exam_time) * good[1].se;
    minimize(ans, res);

    //Th 5 mon 3, mon 1, mon 2
    sum = 0, res = 0;
    res += abs(start_time + good[3].fi - exam_time) * good[3].se;
    sum += start_time + good[3].fi;
    res += abs(sum + good[1].fi - exam_time) * good[1].se;
    sum += good[1].fi;
    res += abs(sum + good[2].fi - exam_time) * good[2].se;
    minimize(ans, res);

    //Th 6 mon 3, mon 2, mon 1
    sum = 0, res = 0;
    res += abs(start_time + good[3].fi - exam_time) * good[3].se;
    sum += start_time + good[3].fi;
    res += abs(sum + good[2].fi - exam_time) * good[2].se;
    sum += good[2].fi;
    res += abs(sum + good[1].fi - exam_time) * good[1].se;
    minimize(ans, res);

    cout << ans;
}

vec(vec(int)) luu;
bool check[N];

void sinh(vec(int) tmp) {
    if (tmp.size() == n) {
        luu.pub(tmp);
        return;
    }

    For(i, 1, n, 1) {
        if (!check[i]) {
            check[i] = true;
            tmp.pub(i);
            sinh(tmp);
            tmp.pb();
            check[i] = false;
        }
    }
}

void sub2(void) {
    vec(int) tmp;
    sinh(tmp);

    ll ans = LLONG_MAX;
    Rep(i, luu.size()) {
        ll sum = 0, res = 0;
        if (n >= 1) {
            res += abs(start_time + good[luu[i][0]].fi - exam_time) * good[luu[i][0]].se;
            sum += start_time + good[luu[i][0]].fi;
        }
        if (n >= 2) {
            res += abs(sum + good[luu[i][1]].fi - exam_time) * good[luu[i][1]].se;
            sum += good[luu[i][1]].fi;
        }
        if (n >= 3) {
            res += abs(sum + good[luu[i][2]].fi - exam_time) * good[luu[i][2]].se;
            sum += good[luu[i][2]].fi;
        }
        if (n >= 4) {
            res += abs(sum + good[luu[i][3]].fi - exam_time) * good[luu[i][3]].se;
            sum += good[luu[i][3]].fi;
        }
        if (n >= 5) {
            res += abs(sum + good[luu[i][4]].fi - exam_time) * good[luu[i][4]].se;
            sum += good[luu[i][4]].fi;
        }
        if (n >= 6) {
            res += abs(sum + good[luu[i][5]].fi - exam_time) * good[luu[i][5]].se;
            sum += good[luu[i][5]].fi;
        }
        if (n >= 7) {
            res += abs(sum + good[luu[i][6]].fi - exam_time) * good[luu[i][6]].se;
            sum += good[luu[i][6]].fi;
        }
        if (n >= 8) {
            res += abs(sum + good[luu[i][7]].fi - exam_time) * good[luu[i][7]].se;
            sum += good[luu[i][7]].fi;
        }
        minimize(ans, res);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("C.inp", "r", stdin);
    //freopen("C.out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> start_time >> end_time >> exam_time;
    For(i, 1, n, 1) cin >> good[i].fi >> good[i].se;

    if (n == 3)
        sub1();
    else if (n <= 8)
        sub2();

    return 0;
}
