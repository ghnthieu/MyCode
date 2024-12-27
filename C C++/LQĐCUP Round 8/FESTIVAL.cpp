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
const int N = (int) 5e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, cnt[N], ans = 0;
vec(int) inp[N];
ii(int, int) edge[N];

void sub1(void) {
    cout << ((n % 2 == 0) ? (n / 2) : ((n - 1) / 2));
}

bool festi[N];

void sub2(int i, vec(int) luu) {
    if (!luu.empty() && luu.size() > ans) {
        //for (int x : luu) cout << x << " ";
        //cout << '\n';
        memset(festi, false, (n + 1) * sizeof(bool));
        bool check = true;
        for (int x : luu) {
            if (festi[edge[x].fi]) { check = false; break; }
            else festi[edge[x].fi] = true;
            if (festi[edge[x].se]) { check = false; break; }
            else festi[edge[x].se] = true;
        }
        if (check) maximize(ans, luu.size());
    }

    For(j, i + 1, n, 1) {
        luu.pub(j);
        sub2(j, luu);
        luu.pb();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FESTIVAL.inp", "r", stdin);
    freopen("FESTIVAL.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    bool check_sub1 = true;
    For(i, 1, n, 1) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
        edge[i] = {x, y};
        ++cnt[x]; ++cnt[y];
        if (cnt[x] > 2 || cnt[y] > 2) check_sub1 = false;
    }

    if (check_sub1)
        sub1();
    else if (n <= 30) {
        vec(int) tmp;
        sub2(0, tmp);
        cout << ans;
    }

    return 0;
}
