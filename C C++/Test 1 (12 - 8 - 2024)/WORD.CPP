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
ll k;
string s;

void sub12(void) {
    s = "v" + s;
    int ans = 0;
    For(i, 1, n, 1) {
        ll sum = 0;
        map <char, int> cnt;
        For(j, i, n, 1) {
            sum -= 1ll * cnt[s[j]] * cnt[s[j]];
            ++cnt[s[j]];
            sum += 1ll * cnt[s[j]] * cnt[s[j]];
            if (sum <= k) ++ans;
        }
    }
    cout << ans;
}

void sub3(void) {
    s = "v" + s;
    ll sum = 0, ans = 0;
    map <char, int> cnt;
    int last = 0, i = 1;
    while (i <= n) {
        sum -= 1ll * cnt[s[i]] * cnt[s[i]];
        ++cnt[s[i]];
        sum += 1ll * cnt[s[i]] * cnt[s[i]];
        while (sum > k) {
            ++last;
            sum -= 1ll * cnt[s[last]] * cnt[s[last]];
            --cnt[s[last]];
            sum += 1ll * cnt[s[last]] * cnt[s[last]];
        }
        ans += (i - last);
        ++i;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("WORD.INP", "r", stdin);
    freopen("WORD.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> k >> s;

    if (n <= 1000)
        sub12();
    else
        sub3();

    return 0;
}
