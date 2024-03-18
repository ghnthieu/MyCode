cin >> n >> q;
a[0] = 0;
for (int i=1; i<=n; ++i) {
    cin >> a[i];
    d[i] = a[i] - a[i-1];
}
while (q--) {
    int l, r, k; cin >> l >> r >> k;
    d[l+1] += k;
    d[r+2] -= k;
}
for (int i=1; i<=n; ++i) {
    a[i] = d[i] + a[i-1];
    cout << a[i] << " ";
}