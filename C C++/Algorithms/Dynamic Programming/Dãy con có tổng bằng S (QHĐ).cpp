#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define NAME ""

typedef long long ll;
typedef double de;
const int MOD = (int) 1e9+7;

int n, s, a[1011];
bool dp[1011];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

    cin >> n >> s;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i=0; i<n; ++i) {
        for (int j=s; j>=a[i]; --j) {
            if (dp[j - a[i]])
                dp[j] = true;
        }
    }
    if (dp[s])
        cout << "YES";
    else
        cout << "NO";

    return 0;
}