for (int i=2; i<=sqrt(n); i++) {
    while (n % i == 0) {
        cout << i << " ";
        n /= i;
    }
}
if (n > 1) cout << n;
