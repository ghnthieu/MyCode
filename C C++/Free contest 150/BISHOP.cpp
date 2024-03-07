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
const int N = (int) 1e3 + 7;

int n, m, a[N][N], sum = 0;

void solve1(int i, int j) {
    if (i == n || j == m || i == -1 || j == -1)
        return;
    sum += a[i][j];
    solve1(i + 1, j + 1);
}

void solve2(int i, int j) {
    if (i == n || j == m || i == -1 || j == -1)
        return;
    sum += a[i][j];
    solve2(i - 1, j - 1);
}

void solve3(int i, int j) {
    if (i == n || j == m || i == -1 || j == -1)
        return;
    sum += a[i][j];
    solve3(i - 1, j + 1);
}

void solve4(int i, int j) {
    if (i == n || j == m || i == -1 || j == -1)
        return;
    sum += a[i][j];
    solve4(i + 1, j - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);

    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j)
            cin >> a[i][j];
    }
    int mx = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            int summ = 0;
            sum = 0;
            solve1(i, j);
            summ += sum;
            sum = 0;
            solve2(i - 1, j - 1);
            summ += sum;
            sum = 0;
            solve3(i - 1, j + 1);
            summ += sum;
            sum = 0;
            solve4(i + 1, j - 1);
            summ += sum;
            mx = max(mx, summ);
        }
    }
    cout << mx;

    return 0;
}
