#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define NAME ""

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e1 + 7;

ll n, f[2][2], m[2][2];

void Mul(ll f[2][2], ll m[2][2]) {
    ll x = (f[0][0] * m[0][0] % MOD + f[0][1] * m[1][0] % MOD) % MOD;
    ll y = (f[0][0] * m[0][1] % MOD + f[0][1] * m[1][1] % MOD) % MOD;
    ll z = (f[1][0] * m[0][0] % MOD + f[1][1] * m[1][0] % MOD) % MOD;
    ll t = (f[1][0] * m[0][1] % MOD + f[1][1] * m[1][1] % MOD) % MOD;
    f[0][0] = x;
    f[0][1] = y;
    f[1][0] = z;
    f[1][1] = t;
}

void Pow(ll f[2][2], ll n) {
    if (n <= 1)
        return;
    Pow(f, n/2);
    Mul(f, f);
    if (n&1)
        Mul(f, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

    cin >> n;
    f[0][0] = f[0][1] = f[1][0] = 1;
    f[1][1] = 0;
    m[0][0] = m[0][1] = m[1][0] = 1;
    m[1][1] = 0;
    if (n == 0)
        cout << 0;
    else {
        Pow(f, n - 1);
        cout << f[0][0];
    }

    return 0;
}