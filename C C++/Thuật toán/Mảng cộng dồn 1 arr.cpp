cin >> n;
sum[0] = 0;
for (int i=1; i<=n; ++i) {
    cin >> a[i];
    sum[i] = sum[i-1] + a[i];
}
cin >> q;
while (q--) {
    int l, r; cin >> l >> r;
    cout << sum[r] - sum[l-1] << endl;
}