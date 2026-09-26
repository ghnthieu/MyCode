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
const int N = (int) 1e6 + 7;

int n, m, k;
string a[N];

void sub1(void) {
    int ans = 0;
    for (int i=1; i<=n; ++i) {
        int j1 = i + 1, j2 = n;
        while (j1 <= j2) {
            if (j1 == j2) {
                int cnt = 0;
                for (int tk=0; tk<m; ++tk) {
                    if (a[i][tk] != a[j1][tk])
                        ++cnt;
                    if (cnt > k)
                        break;
                }
                if (cnt == k)
                    ++ans;
            }
            else {
                int cnt = 0;
                for (int tk=0; tk<m; ++tk) {
                    if (a[i][tk] != a[j1][tk])
                        ++cnt;
                    if (cnt > k)
                        break;
                }
                if (cnt == k)
                    ++ans;
                cnt = 0;
                for (int tk=0; tk<m; ++tk) {
                    if (a[i][tk] != a[j2][tk])
                        ++cnt;
                    if (cnt > k)
                        break;
                }
                if (cnt == k)
                    ++ans;
            }
            ++j1;
            --j2;
        }
    }
    cout << ans;
}

void sub2(void) {}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("SAMPLE.INP", "r", stdin);
    freopen("SAMPLE.OUT", "w", stdout);

    cin >> n >> m >> k;
    for (int i=1; i<=n; ++i)
        cin >> a[i];

    // if (m <= 10)
        sub1();
    // else
        // sub2();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}
