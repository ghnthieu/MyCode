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
const int N = (int) 3e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, k, a[N];

void sub12(void) {
    vec(int) luu; luu.pub(0);
    For(i, 1, n, 1) luu.pub(a[i]);

    int ans = 0;
    For(i, 1, n, 1) {
        int sl = k;
        For(j, i + 1, n, 1) {
            if (sl == 0) break;
            if (a[j] != a[i]) {
                a[j] = a[i];
                --sl;
            }
        }
        /*For(j, 1, n, 1) cout << a[j] << " ";
        cout << '\n';*/
        int last = 1, r = 1;
        while (r <= n) {
            int cnt = 0;
            while (a[last] == a[r] && r <= n) {
                ++r; ++cnt;
            }
            maximize(ans, cnt);
            cnt = 0; last = r;
        }
        For(j, 1, n, 1) a[j] = luu[j];
    }
    cout << ans;
}

map <int, int> cnt;

bool check(int len) {
    cnt.clear();
    int mx = 0;
    For(i, 1, len, 1) {
        ++cnt[a[i]];
        maximize(mx, cnt[a[i]]);
    }
    if (len - mx <= k) return true;
    For(i, len + 1, n, 1) {
        --cnt[a[i - len]];
        maximize(mx, cnt[a[i - len]]);
        if (len - mx <= k) return true;
        ++cnt[a[i]];
        maximize(mx, cnt[a[i - len]]);
        if (len - mx <= k) return true;
    }
    return false;
}

void sub3(void) {
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int m = l + r >> 1;
        if (check(m)) {
            maximize(ans, m);
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seq.inp", "r", stdin);
    freopen("seq.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> k;
    For(i, 1, n, 1) cin >> a[i];

    if (n <= 5e3 && k <= 5e3)
        sub12();
    else
        sub3();

    return 0;
}
