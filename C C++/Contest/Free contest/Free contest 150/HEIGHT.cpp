#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define fr front
#define bk back
#define NAME ""
#define ii pair <int,int>
#define vii vector <pair <int,int>>
#define iii pair <pair <int,int>,int>
#define viii vector <pair <pair <int,int>,int>>

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;

int n, a[N], b[N];

void solve() {
    vector <int> ans;
    int mx = 0;
    for (int i=1; i<=n; ++i) {
        if (b[i] - a[i] == mx)
            ans.push_back(i);
        else if (b[i] - a[i] > mx) {
            ans.clear();
            ans.push_back(i);
            mx = b[i] - a[i];
        }
    }
    for (int x : ans)
        cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);

    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=1; i<=n; ++i)
        cin >> b[i];
    solve();

    return 0;
}
