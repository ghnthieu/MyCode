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

int n, m, col[N];
vector <int> inp[N];

bool bfs(int u) {
    queue <int> q;
    q.push(u);
    col[u] = 0;
    while (!q.empty()) {
        int v = q.fr();
        q.pop();
        for (int x : inp[v]) {
            if (col[x] == -1) {
                col[x] = 1 - col[v];
                q.push(x);
            }
            else if (col[x] == col[v])
                return false;
        }
    }
    return true;
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
    memset(col, -1, sizeof(col));
    bool check = true;
    for (int i=1; i<=n; ++i) {
        if (col[i] == -1) {
            if (!bfs(i)) {
                check = false;
                break;
            }
        }
    }
    if (check)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}