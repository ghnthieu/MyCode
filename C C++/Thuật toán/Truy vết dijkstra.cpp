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

int n, m, q, ans[N];
vector <pair <int,int>> inp[N];

void distra(int s, int t) {
    vector <ll> d(n + 1, 1e9);
    d[s] = 0;
    ans[s] = s;
    priority_queue <pair <int,int>, vector <pair <int,int>>, greater <pair <int,int>>> q;
    q.push({0, s});
    while (!q.empty()) {
        pair <int,int> top = q.top();
        q.pop();
        int u = top.se, kc = top.fi;
        if (kc > d[u])
            continue;
        for (auto it : inp[u]) {
            int v = it.fi, w = it.se;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
                ans[v] = u;
            }
        }
    }
    cout << d[t] << '\n';
    vector <int> path;
    while (true) {
        path.push_back(t);
        if (t == s)
            break;
        t = ans[t];
    }
    reverse(path.begin(), path.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

    cin >> n >> m;
    while (m--) {
        int x, y, w; cin >> x >> y >> w;
        inp[x].push_back({y, w});
        inp[y].push_back({x, w});
    }
    cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        distra(x, y);
    }

    return 0;
}