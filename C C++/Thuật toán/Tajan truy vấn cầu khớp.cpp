void dfs(int u, int par) {
    int child = 0;
    num[u] = low[u] = ++cnt;
    for (int v : inp[u]) {
        if (v == par)
            continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v])
                cau.pub({u, v});
            ++child;
            if (u == par) {
                if (child > 1)
                    check[u] = true;
            }
            else if (low[v] >= num[u])
                check[u] = true;
        }
        else
            low[u] = min(low[u], num[v]);
    }
}
memset(check, false, sizeof(check));
for (int i=1; i<=n; ++i) {
    if (!num[i])
        dfs(i, i);
    if (check[i])
        khop.pub(i);
}
for (ii(int, int) x : cau)
    cout << x.fi << " " << x.se << '\n';
cout << '\n';
for (int x : khop)
    cout << x << " ";