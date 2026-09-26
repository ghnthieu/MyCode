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

struct Data {
    ll x;
    ll y;
};

int n, m;
Data a[N], b[N];

bool cmp(Data a, Data b) {
    return (a.x > b.x);
}

ll ltbinary(int a, int b) {
    if (b == 0)
        return 1;
    ll x = ltbinary(a, b/2);
    if (b%2 == 1)
        return (((x%MOD) * (x%MOD))%MOD * (a%MOD))%MOD;
    else
        return ((x%MOD) * (x%MOD))%MOD;
}

void solve() {
    if (n <= m) {
        cout << a[0].y;
        return;
    }
    for (int i=0; i<m; ++i) {
        b[i].x = a[i].x;
        b[i].y = a[i].y;
    }
    int left = m, right = m - 1;
    while (left < n) {
        if (right == -1)
            right = m - 1;
        b[right].x += a[left].x;
        b[right].x %= MOD;
        b[right].y += a[left].y;
        b[right].y %= MOD;
        --right;
        ++left;
    }
    ll mx = 0, index = 0;
    for (int i=0; i<m; ++i) {
        if (b[i].x > mx) {
            mx = b[i].x;
            index = b[i].y;
        }
    }
    cout << index;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);

    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        a[i].x = x;
        a[i].y = ltbinary(2, x);
    }
    sort(a, a+n, cmp);
    solve();

    return 0;
}
