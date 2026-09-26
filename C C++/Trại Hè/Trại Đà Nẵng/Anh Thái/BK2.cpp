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
#define __Trung_Hieu___ signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
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

int k;
string s;

bool check(string st) {
    int cnt = 0;
    Rep(i, st.length()) {
        if (st[i] == '(') ++cnt;
        else --cnt;
        if (cnt < 0) return false;
    }
    return (cnt == 0);
}

int maxx(string st) {
    int cnt = 0, res = 0, hehe = 0;
    Rep(i, st.length()) {
        if (st[i] == '(') {
            ++cnt; maximize(res, cnt);
        }
        else --cnt;
        if (cnt == 0) {
            maximize(hehe, res);
            res = 0;
        }
    }
    return hehe;
}

set <string> ans;

void sub1(int i, vec(int) luu) {
    if (!luu.empty() && luu.size() % 2 == 0) {
        string don = "";
        for (int x : luu) don += s[x];
        if (check(don) && maxx(don) == k)
            ans.insert(don);
    }

    For(j, i + 1, s.length() - 1, 1) {
        luu.pub(j);
        sub1(j, luu);
        luu.pb();
    }
}

void sub2(void) {}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> k >> s;

    //if (s.length() <= 10) {
        vec(int) tmp;
        sub1(-1, tmp);
        cout << (int) ans.size();
    //}
    //else
    //    sub2();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
