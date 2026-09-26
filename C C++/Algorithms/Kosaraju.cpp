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
stack <int> st;
vector <int> inp[N], rinp[N];

void dfs1(int u) {
    vit[u] = true;
    for (int v : inp[u]) {
        if (!vit[v])
            dfs1(v);
    }
    st.push(u);
}

void dfs2(int u) {
    vit[u] = true;
    //cout << u << " ";
    for (int v : rinp[u]) {
        if (!vit[v])
            dfs2(v);
    }
}

void scc() {
    memset(vit, false, sizeof(vit));
    for (int i=1; i<=n; ++i) {
        if (!vit[i])
            dfs1(i);
    }
    memset(vit, false, sizeof(vit));
    int cnt = 0;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!vit[u]) {
            dfs2(u);
            ++cnt;
        }
    }
    if (cnt == 1)
        cout << 1;
    else
        cout << 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);

    cin >> n >> m;
    while (m--) {
        int x, y; cin >> x >> y;
        inp[x].push_back(y);
        rinp[y].push_back(x);
    }
    scc();

    return 0;
}