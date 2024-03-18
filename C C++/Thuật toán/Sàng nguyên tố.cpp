for (int i=2; i<=n; ++i)
    nt[i] = true;
for (int i=2; i<=sqrt(n); ++i) {
    if (nt[i]) {
         for (int j=i*i; j<=n; j+=i)
            nt[j] = false;
    }
}