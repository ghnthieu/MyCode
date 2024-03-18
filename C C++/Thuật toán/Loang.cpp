#include <bits/stdc++.h>
#define ll long long
#define NAME ""
using namespace std;

int n, m, a[61][61];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void Try(int i, int j) {
    a[i][j] = 0;
    for (int k=0; k<8; ++k) {
        int it = i + dx[k];
        int jt = j + dy[k];
        if (it >= 0 && it < n && jt >= 0 && jt < m && a[it][jt])
            Try(it, jt);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j)
            cin >> a[i][j];
    }

    int cnt = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (a[i][j]) {
                ++cnt;
                Try(i, j);
            }
        }
    }
    cout << cnt << endl;

    return 0;
}