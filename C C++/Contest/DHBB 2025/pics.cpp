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
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, s[N];

struct Data {

    int disk_1, disk_2;
    vec(bool) don_like;

} info[N];

vec(vec(int)) luu;

void sinh_th(vec(int) th) {
    if (th.size() == n) {
        luu.pub(th);
        return;
    }

    For(i, 0, 2, 1) {
        th.pub(i);
        sinh_th(th);
        th.pb();
    }
}

void sub1(void) {
    vec(int) tmp;
    sinh_th(tmp);

    /*For(fri, 1, m, 1) {
        For(i, 1, n, 1) cout << info[fri].don_like[i] << " ";
        //cout << info[fri].disk_1 << " " << info[fri].disk_2;
        cout << '\n';
    }*/

    For(fri, 1, m, 1) {
        int ans = 0; string test_1 = "";
        Rep(i, luu.size()) {
            int sum_disk1 = 0, sum_disk2 = 0, cnt = 0; bool check = true;
            For(j, 0, luu[i].size() - 1, 1) {
                if (luu[i][j] != 0 && info[fri].don_like[j + 1]) {
                    check = false;
                    break;
                }
                if (luu[i][j] == 1) sum_disk1 += s[j + 1];
                else if (luu[i][j] == 2) sum_disk2 += s[j + 1];
                if (luu[i][j] != 0) ++cnt;
            }
            if (check && sum_disk1 <= info[fri].disk_1 && sum_disk2 <= info[fri].disk_2) {
                if (fri == 1 && maximize(ans, cnt)) {
                    test_1 = "";
                    For(j, 0, luu[i].size() - 1, 1) test_1 += to_string(luu[i][j]);
                }
                else maximize(ans, cnt);
            }
        }
        if (fri == 1)
            cout << ans << '\n' << test_1 << '\n';
        else
            cout << ans << " ";
    }
}

ii(int, int) luu_a[N];
int use[N];

void sub2(void) {
    For(i, 1, n, 1) luu_a[i] = {s[i], i};
    sort(luu_a + 1, luu_a + n + 1);

    For(fri, 1, m, 1) {
        if (fri == 1) {
            ll sum_disk1 = 0, sum_disk2 = 0, ans = 0;
            For(i, 1, n, 1)  if (!info[fri].don_like[luu_a[i].se]) {
                if (sum_disk1 + luu_a[i].fi <= info[fri].disk_1) {
                    sum_disk1 += luu_a[i].fi;
                    ++ans; use[luu_a[i].se] = 1;
                }
                else if (sum_disk2 + luu_a[i].fi <= info[fri].disk_2) {
                    sum_disk2 += luu_a[i].fi;
                    ++ans; use[luu_a[i].se] = 2;
                }
            }
            cout << ans << '\n';
            For(i, 1, n, 1) cout << use[i];
            cout << '\n';
        }
        else {
            ll sum_disk1 = 0, sum_disk2 = 0, ans = 0;
            For(i, 1, n, 1) if (!info[fri].don_like[luu_a[i].se]) {
                if (sum_disk1 + luu_a[i].fi <= info[fri].disk_1) {
                    sum_disk1 += luu_a[i].fi;
                    ++ans;
                }
                else if (sum_disk2 + luu_a[i].fi <= info[fri].disk_2) {
                    sum_disk2 += luu_a[i].fi;
                    ++ans;
                }
            }
            cout << ans << " ";
        }
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("pics.inp", "r", stdin);
    //freopen("pics.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    For(i, 1, n, 1) cin >> s[i];
    bool check_sub1 = true;
    For(i, 1, m, 1) {
        int sz; cin >> info[i].disk_1 >> info[i].disk_2 >> sz;
        info[i].don_like.resize(n + 1, false);
        For(j, 1, sz, 1) {
            int x; cin >> x;
            info[i].don_like[x] = true;
        }

        //if (info[i].disk_1 > 1e3 || info[i].disk_2 > 1e3) check_sub1 = false;
    }

    if (n <= 20 && m <= 10)
        sub1();
    else
        sub2();

    return 0;
}
