ll modulo(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2 != 0) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return res;
}
ll revmodulo = modulo(..., MOD-2);