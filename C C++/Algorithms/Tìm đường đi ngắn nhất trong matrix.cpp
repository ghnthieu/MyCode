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

int n, s, t, u, v, a[N][N], d[N][N];
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void bfs(int i, int j) {
    queue <pair <int,int>> qp;
    qp.push({i, j});
    a[i][j] = 0;
    d[i][j] = 0;
    while (!qp.empty()) {
        pair <int,int> tmp = qp.fr();
        qp.pop();
        for (int k=0; k<8; ++k) {
            int it = tmp.fi + dx[k];
            int jt = tmp.se + dy[k];
            if (it >= 1 && it <= n && jt >= 1 && jt <= n && a[it][jt] != 0) {
                d[it][jt] = d[tmp.fi][tmp.se] + 1;
                if (it == u && jt == v )
                    return;
                qp.push({it, jt});
                a[it][jt] = 0;
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

    cin >> n >> s >> t >> u >> v;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j)
            cin >> a[i][j];
    }
    bfs(s, t);
    if (d[u][v])
        cout << d[u][v];
    else
        cout << -1;

    return 0;
}