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

int n, m, s;
bool vit[N];
vector <int> inp[N];

void bfs(int i) {
    queue <int> q;
    q.push(i);
    vit[i] = true;
    while (!q.empty()) {
        int tmp = q.fr();
        q.pop();
        cout << tmp << " ";
        for (int x : inp[tmp]) {
            if (!vit[x]) {
                q.push(x);
                vit[x] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

    cin >> n >> m >> s;
    for (int i=0; i<m; ++i) {
        int x, y; cin >> x >> y;
        inp[x].push_back(y);
        inp[y].push_back(x);
    }
    for (int i=1; i<=n; ++i)
        sort(inp[i].begin(), inp[i].end());
    memset(vit, false, sizeof(vit));
    bfs(s);

    return 0;
}