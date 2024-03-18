void init() {
    check[1] = 0;
    for (int i=2; i<M; ++i) {
        if (!check[i]) {
            for (int j=i; j<M; j+=i)
                check[j] = i;
        }
    }
}

void solve(ll n) {
    while (n > 1) {
        ll tmp = check[n];
        while (n % tmp == 0) {
            cout << tmp << " ";
            n /= tmp;
        }
    }
}