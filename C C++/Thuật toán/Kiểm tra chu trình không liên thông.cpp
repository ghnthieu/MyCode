#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define fr front
#define bk back
#define NAME ""

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e3 + 7;

int n, m;
bool vit[N];
vector <int> inp[N];

bool dfs(int i, int par) {
    vit[i] = true;
    for (int x : inp[i]) {
        if (!vit[x]) {
            if (dfs(x, i))
                return true;
        }
        else if (x != par)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

    cin >> n >> m;
    while (m--) {
        int x, y; cin >> x >> y;
        inp[x].push_back(y);
        inp[y].push_back(x);
    }
    memset(vit, false, sizeof(vit));
    for (int i=1; i<=n; ++i) {
        if (!vit[i]) {
            if (dfs(i, 0)) {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;

    return 0;
}