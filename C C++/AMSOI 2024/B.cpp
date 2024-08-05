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
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m;
ll a[N], b[N];

void sub1(void) {
    int il = 1, ir = n - m + 1;
    while (il <= ir) {
        if (il == ir) {
            int jl = 1, jr = m;
            while (jl <= jr) {
                if (jl == jr)
                    a[il + jl - 1] += b[jl];
                else {
                    a[il + jl - 1] += b[jl];
                    a[il + jr - 1] += b[jr];
                }
                ++jl; --jr;
            }
        }
        else {
            int jl = 1, jr = m;
            while (jl <= jr) {
                if (jl == jr)
                    a[il + jl - 1] += b[jl];
                else {
                    a[il + jl - 1] += b[jl];
                    a[il + jr - 1] += b[jr];
                }
                ++jl; --jr;
            }
            jl = 1, jr = m;
            while (jl <= jr) {
                if (jl == jr)
                    a[ir + jl - 1] += b[jl];
                else {
                    a[ir + jl - 1] += b[jl];
                    a[ir + jr - 1] += b[jr];
                }
                ++jl; --jr;
            }
        }
        ++il; --ir;
    }
    For(i, 1, n, 1) cout << a[i] << " ";
}

void sub2(void) {
    if (n == m) {
        For(i, 1, n, 1) cout << a[i] + b[i] << " ";
        return;
    }

    if (n == m + 1) {
        For(i, 1, n, 1) cout << a[i] + b[i] + b[i - 1] << " ";
        return;
    }

    if (n % 2 == 0) {
        //Left
        ll sum = 0;
        int j = 0;
        For(i, 1, n / 2, 1) {
            ++j;
            if (j <= m) sum += b[j];
            a[i] += sum;
        }

        //Right
        sum = 0;
        j = m + 1;
        Ford(i, n, n / 2 + 1, 1) {
            --j;
            if (j >= 1) sum += b[j];
            a[i] += sum;
        }

        For(i, 1, n, 1) cout << a[i] << " ";
        return;
    }

    //Left
    ll sum = 0;
    int j = 0;
    For(i, 1, n / 2 + 1, 1) {
        ++j;
        if (j <= m) sum += b[j];
        a[i] += sum;
        cout << sum << " ";
    }
    cout << '\n';

    //Right
    sum = 0;
    j = m + 1;
    Ford(i, n, n / 2 + 2, 1) {
        --j;
        if (j >= 1) sum += b[j];
        a[i] += sum;
        cout << sum << " ";
    }
    cout << '\n';

    For(i, 1, n, 1) cout << a[i] << " ";
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    For(i, 1, n, 1) cin >> a[i];
    For(i, 1, m, 1) cin >> b[i];

    //if (n <= 1e3 && m <= 1e3)
        sub1();
    //else
        //sub2();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
