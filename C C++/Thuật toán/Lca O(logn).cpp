void dfs(int u) {
    for (int v : inp[u]) {
        if (v != par[u][0]) {
            par[v][0] = u;
            high[v] = high[u] + 1;
            dfs(v);
        }
    }
}
dfs(1);
for (int j=1; j<=M; ++j) {
    for (int i=1; i<=n; ++i)
        par[i][j] = par[par[i][j - 1]][j - 1];
}
high[0] = -1;
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