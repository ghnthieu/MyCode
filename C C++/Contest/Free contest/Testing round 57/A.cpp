#include <bits/stdc++.h>
using namespace std;

#define NAME "CLIMBING"
#define fi first
#define se second
#define fr front
#define bk back
#define pf pop_front
#define pb pop_back
#define puf push_front
#define pub push_back
#define NOT 18446744073709551615
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <kdl1,kdl2>,kdl3>>

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

int n, m, k, a[N], tree1[4 * N], tree2[4 * N];

void build1(int v, int l, int r) {
    if (l == r)
        tree1[v] = a[l];
    else {
        int mid = (l + r) / 2;
        build1(2 * v, l, mid);
        build1(2 * v + 1, mid + 1, r);
        tree1[v] = max(tree1[2 * v], tree1[2 * v + 1]);
    }
}

int findmax(int v, int treel, int treer, int l, int r) {
    if (l > r)
        return -MOD;
    if (treel == l && treer == r)
        return tree1[v];
    else {
        int treem = (treel + treer) / 2;
        return max(findmax(2 * v, treel, treem, l, min(treem, r)), findmax(2 * v + 1, treem + 1, treer, max(treem + 1, l), r));
    }
}

void build2(int v, int l, int r) {
    if (l == r)
        tree2[v] = a[l];
    else {
        int mid = (l + r) / 2;
        build2(2 * v, l, mid);
        build2(2 * v + 1, mid + 1, r);
        tree2[v] = min(tree2[2 * v], tree2[2 * v + 1]);
    }
}

int findmin(int v, int treel, int treer, int l, int r) {
    if (l > r)
        return MOD;
    if (treel == l && treer == r)
        return tree2[v];
    else {
        int treem = (treel + treer) / 2;
        return min(findmin(2 * v, treel, treem, l, min(treem, r)), findmin(2 * v + 1, treem + 1, treer, max(treem + 1, l), r));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);

    cin >> n >> m >> k;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    build1(1, 1, n);
    build2(1, 1, n);
    bool check = true;
    for (int i=1; i<=n; ++i) {
        if (i + m - 1 <= n) {
            if (findmax(1, 1, n, i, i + m - 1) - findmin(1, 1, n, i, i + m - 1) <= k) {
                cout << i << '\n';
                check = false;
            }
        }
    }
    if (check)
        cout << "NONE";

    return 0;
}
