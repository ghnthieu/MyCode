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

int n, m, a[N];
ll need[N];
vec(int) luu;
bool nt[N + 1];

void pt_gcd(int x) {
    For(i, 1, sqrt(x), 1) if (x % i == 0) {
        if (i == (x / i))
            luu.pub(i);
        else {
            luu.pub(i);
            luu.pub(x / i);
        }
    }
}

void sub1(void) {
    luu.pub(0);
    For(i, 1, n, 1) pt_gcd(a[i]);
    sort(all(luu));
    For(i, 1, m, 1) cout << luu[need[i]] << " ";
}

void init(void) {
    For(i, 1, N, 1) nt[i] = true;
    nt[0] = nt[1] = false;
    For(i, 2, sqrt(N), 1) if (nt[i]) {
        For(j, i * i, N, i)
            nt[j] = false;
    }
}

void sub2(void) {
    sort(a + 1, a + n + 1);
    For(i, 1, m, 1) cout << ((need[i] <= n) ? 1 : a[need[i] - n]) << " ";
}

int cnt[N];
ll pre[N];

void sub3(void) {
    For(i, 1, 1000000, 1) {
        For(j, i, 1000000, i) pre[i] += cnt[j];
        pre[i] += pre[i - 1];
    }

    For(i, 1, m, 1) {
        ll x = need[i];
        int l = 1, r = 1e6, res = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (pre[mid] >= x) {
                res = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        cout << res << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("DIV.INP", "r", stdin);
    freopen("DIV.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    init();

    cin >> n >> m;
    bool check = true;
    For(i, 1, n, 1) {
        cin >> a[i];
        ++cnt[a[i]];
        if (!nt[a[i]]) check = false;
    }
    For(i, 1, m, 1) cin >> need[i];

    if (check)
        sub2();
    else if (n <= 1e3 && m <= 1e3)
        sub1();
    else
        sub3();

    return 0;
}
