#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define NAME ""

typedef long long ll;
typedef double de;
const int MOD = (int) 1e9+7;

string s;
bool dx[1011][1011];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

    cin >> s;
    int len = s.length();
    s = " " + s;
    memset(dx, false, sizeof(dx));
    for (int i=1; i<=len; ++i)
        dx[i][i] = true;
    int ans = 1;
    for (int length = 2; length <= len; ++length) {
        for (int i = 1; i <= len - length + 1; ++i) {
            int j = i + length - 1;
            if (length == 2 && s[i] == s[j])
                dx[i][j] = true;
            else
                dx[i][j] = dx[i+1][j-1] && (s[i] == s[j]);
            if (dx[i][j])
                ans = max(ans, length);
        }
    }
    cout << ans;

    return 0;
}