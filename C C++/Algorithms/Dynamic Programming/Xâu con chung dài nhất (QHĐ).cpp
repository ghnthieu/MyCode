#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define NAME ""

typedef long long ll;
typedef double de;
const int MOD = (int) 1e9+7;

string s1, s2;
int xc[1011][1011];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

    cin >> s1 >> s2;
    int len1 = s1.length();
    int len2 = s2.length();
    s1 = " " + s1;
    s2 = " " + s2;
    memset(xc, 0, sizeof(xc));
    for (int i=1; i<=len1; ++i) {
        for (int j=1; j<=len2; ++j) {
            if (s1[i] == s2[j])
                xc[i][j] = xc[i-1][j-1] + 1;
            else
                xc[i][j] = max(xc[i][j-1], xc[i-1][j]);
        }
    }
    cout << xc[len1][len2];

    return 0;
}