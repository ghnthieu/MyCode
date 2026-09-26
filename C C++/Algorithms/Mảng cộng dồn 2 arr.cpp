cin >> n >> m;
for (int i=1; i<=n; ++i) {
    for (int j=1; j<=m; ++j) {
        cin >> a[i][j];
        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
    }
}
cin >> q;
while (q--) {
    int h1, h2, c1, c2;
    cin >> h1 >> h2 >> c1 >> c2;
    cout << sum[h2][c2] - sum[h1-1][c2] - sum[h2][c1-1] + sum[h1-1][c1-1] << endl;
}