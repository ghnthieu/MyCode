cin >> n;
for (int i=1; i<=n; ++i) {
    cin >> a[i];
    sum[i] = sum[i-1] + a[i];
}
ll ans = -1e18, Min = 1e18;
for (int i=1; i<=n; ++i) {
    ans = max(ans, sum[i] - Min);
    Min = min(Min, sum[i-1]);
}
cout << ans;