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
const int N = (int) 1e1 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, k, a[N];
bool check[N];
vec(vec(int)) ans;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve(vec(int) luu) {
    if (luu.size() == n) {
        bool t_check = true;
        Rep(idx, luu.size() - 1) {
            if (gcd(luu[idx], luu[idx + 1]) < k) {
                t_check = false;
                break;
            }
        }
        if (t_check) ans.pub(luu);
        return;
    }

    For(i, 1, n, 1) {
        if (!check[i]) {
            check[i] = true;
            luu.pub(a[i]);
            solve(luu);
            luu.pb();
            check[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("A.inp", "r", stdin);
    //freopen("A.out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> k;
    For(i, 1, n, 1) cin >> a[i];

    vec(int) tmp;
    solve(tmp);
    sort(all(ans));
    if (m > ans.size())
        cout << -1;
    else
        for (int x : ans[m - 1]) cout << x << " ";

    /*Rep(idx, ans.size()) {
        for (int x : ans[idx]) cout << x << " ";
        cout << '\n';
    }*/

    return 0;
}
