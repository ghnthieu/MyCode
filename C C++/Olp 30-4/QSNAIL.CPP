#include <bits/stdc++.h>
using namespace std;

#define NAME ""
#define fi first
#define se second
#define fr front
#define bk back
#define pf pop_front
#define pb pop_back
#define puf push_front
#define pub push_back
#define NOT 18446744073709551615
#define __Trung_Hieu___ signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define vec(kdl) vector <kdl>
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1,kdl2>,kdl3>>
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
typedef long double lde;
const int MOD = (int) 1e9 + 7;
const int N = (int) 5e5 + 7;

int n, q, a[N];
bool ocsen[N];
ll sum[N], sumos[N];

void sub1(int l, int r) {
    cout << sumos[r] - sumos[l - 1] << '\n';
}

void sub2(int l, int r) {
    int cnt = 0;
    for (int i=l; i<=r; ++i) {
        if (ocsen[i]) {
            if (i == l) {
                if (ocsen[i + 1])
                    ++cnt;
            }
            else if (i == r) {
                if (ocsen[i - 1])
                    ++cnt;
            }
            else if (ocsen[i - 1] && ocsen[i + 1])
                ++cnt;
        }
    }
    cout << cnt;
}

// iii(int, int, bool) check[N];
void sub3(int l, int r) {
    // for (int i=l; i<=r; ++i)
    //     check[i].se = false;
    // for (int i=l; i<=r; ++i) {
    //     if (ocsen[i]) {
    //         ll sum = a[i];
    //         if (sum >= 0)
    //             check[i] = true;
    //         int left = i - 1, right = i + 1;
    //         while (sum < 0) {
    //             if (a[left] >= a[right] && !ocsen[left] && left >= l) {
    //                 sum += a[left];
    //                 --left;
    //             }
    //             else {
    //                 if (!ocsen[right]) {
    //                     sum += a[right];
    //                     ++right;
    //                 }
    //             }
    //         }
    //     }
    // }
}

void sub4(int l, int r) {}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("QSNAIL.INP", "r", stdin);
    freopen("QSNAIL.OUT", "w", stdout);

    cin >> n >> q;
    sumos[0] = 0;
    for (int i=1; i<=n; ++i) {
        char ch; cin >> ch;
        ocsen[i] = ((ch == '1') ? true : false);
        sumos[i] = sumos[i - 1] + ((ocsen[i]) ? 1 : 0);
    }
    sum[0] = 0;
    bool dk1 = true, dk2 = true;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        if (a[i] < 0)
            dk1 = false;
        if (ocsen[i]) {
            if (a[i] != 0)
                dk2 = false;
        }
        else if (a[i] >= 0)
            dk2 = false;
    }
    for (int i=1; i<=q; ++i) {
        int l, r; cin >> l >> r;
        if (dk1 && n <= 8e3 && q == 1)
            sub1(l, r);
        else if (dk2 && n <= 8e3 && q == 1)
            sub2(l, r);
        else if (n <= 8e3 && q == 1)
            sub3(l, r);
        else if (n <= 8e3 && q <= 8e3)
            sub4(l, r);
    }

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
