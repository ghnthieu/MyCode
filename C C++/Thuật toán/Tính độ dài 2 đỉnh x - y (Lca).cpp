void dfs(int u) {
    for (ii(int, int) v : inp[u]) {
        if (v.fi != par[u][0]) {
            par[v.fi][0] = u;
            high[v.fi] = high[u] + 1;
            sum[v.fi] = sum[u] + v.se;
            dfs(v.fi);
        }
    }
}

int lca(int u, int v) {
    if (high[v] > high[u])
        return lca(v, u);
    for (int i=M; i>=0; --i) {
        if (high[par[u][i]] >= high[v])
            u = par[u][i];
    }
    if (u == v)
        return u;
    for (int i=M; i>=0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

dfs(1);
for (int j=1; j<=M; ++j) {
    for (int i=1; i<=n; ++i)
        par[i][j] = par[par[i][j - 1]][j - 1];
}
high[0] = -1;

cout << sum[x] + sum[y] - 2 * sum[lca(x, y)] << '\n';