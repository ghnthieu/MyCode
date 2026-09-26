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
const int N = (int) 1e5 + 7;

struct canh {
    int x, y, z;
};

int n, m, prt[N], d[N];
bool use[N], vit[N];
vector <pair <int,int>> inp[N];

void prim(int u) {
    priority_queue <pair <int,int>, vector <pair <int,int>>, greater <pair <int,int>>> q;
    vector <canh> mst;
    ll res = 0;
    q.push({0, u});
    while (!q.empty()) {
        pair <int,int> tmp = q.top();
        q.pop();
        int dh = tmp.se, ts = tmp.fi;
        if (use[dh])
            continue;
        res += ts;
        use[dh] = true;
        if (u != dh)
            mst.push_back({dh, prt[dh], ts});
        for (auto it : inp[dh]) {
            int y = it.fi, z = it.se;
            if (!use[y] && z < d[y]) {
                q.push({z, y});
                d[y] = z;
                prt[y] = dh;
            }
        }
    }
    if ((int) mst.size() == 0)
        cout << "IMPOSSIBLE";
    else
        cout << res;
}

void dfs(int u) {
    vit[u] = true;
    for (pair <int,int> v : inp[u]) {
        if (!vit[v.fi])
            dfs(v.fi);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

    cin >> n >> m;
    while (m--) {
        int x, y, z; cin >> x >> y >> z;
        inp[x].push_back({y, z});
        inp[y].push_back({x, z});
    }
    memset(vit, false, sizeof(vit));
    int cnt = 0;
    for (int i=1; i<=n; ++i) {
        if (!vit[i]) {
            ++cnt;
            if (cnt == 2) {
                cout << "IMPOSSIBLE";
                return 0;
            }
            dfs(i);
        }
    }
    memset(use, false, sizeof(use));
    for (int i=1; i<=n; ++i)
        d[i] = INT_MAX;
    prim(1);

    return 0;
}