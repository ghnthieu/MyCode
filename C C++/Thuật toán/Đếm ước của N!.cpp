int degree(int n, int p) {
    int ans = 0;
    for (int i=p; i<=n; i*=p)
        ans += n/i;
    return ans;
}

int nt(int n) {
    for (int i=2; i<=sqrt(n); ++i) {
        if (n%i == 0)
            return 0;
    }
    return (n > 1);
}

ll count(int n) {
    ll res = 1;
    for (int i=1; i<=n; ++i) {
        if (nt(i))
            res = ((res%r)*((degree(n, i)+1)%r))%r;
    }
    return res;
}