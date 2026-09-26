#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define NAME ""

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e3 + 7;

int n, x, a[N];
unordered_map <int, pair <int,int>> um;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

    cin >> n >> x;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j)
            um[a[i] + a[j]] = {i, j};
    }
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            int sum = a[i] + a[j];
            if (um.find(x - sum) != um.end()) {
                pair <int, int> p = um[x - sum];
                if (p.fi != i && p.fi != j && p.se != i && p.se != j) {
                    cout << i + 1 << " " << j + 1 << " " << p.fi + 1 << " " << p.se + 1;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}