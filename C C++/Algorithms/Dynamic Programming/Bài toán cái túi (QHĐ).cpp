#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define NAME ""

typedef long long ll;
typedef double de;
const int MOD = (int) 1e9+7;

int n, s, dp[1011][1011] = {0};
vector <pair <int,int>> vp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

    cin >> n >> s;
    vp.push_back({0, 0});
    for (int i=1; i<=n; ++i) {
        int x; cin >> x;
        vp.push_back({x, 0});   //Trong luong do vat thu i
    }
    for (int i=1; i<=n; ++i)
        cin >> vp[i].se;   //Gia tri do vat thu i
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=s; ++j) {
            dp[i][j] = dp[i-1][j];
            if (vp[i].fi <= j)
                dp[i][j] = max(dp[i][j], dp[i-1][j-vp[i].fi] + vp[i].se);
        }
    }
    cout << dp[n][s];

    return 0;
}