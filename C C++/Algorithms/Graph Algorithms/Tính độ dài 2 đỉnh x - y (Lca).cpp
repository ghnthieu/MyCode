int par[N][M + 1], high[N];

void dfs(int u) {
    vit[u] = true;
    for (ii(int, int) v : inp[u]) if (!vit[v.fi]) {
        duong[v.fi] = duong[u] + v.se;
        dfs(v.fi);
    }
}

void dfs_lca(int u) {
    for (ii(int, int) v : inp[u]) {
        if (v.fi != par[u][0]) {
            par[v.fi][0] = u;
            high[v.fi] = high[u] + 1;
            dfs_lca(v.fi);
        }
    }
}

int lca(int u, int v) {
    if (high[v] > high[u]) return lca(v, u);
    Ford (i, M, 0, 1) if (high[par[u][i]] >= high[v])
        u = par[u][i];
    if (u == v) return u;
    Ford(i, M, 0, 1) if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

ll get_sum(int u, int v) {
    return duong[u] + duong[v] - (duong[lca(u, v)] * 2);
}

dfs(1);
dfs_lca(1);
For(j, 1, M, 1) For(i, 1, n, 1)
    par[i][j] = par[par[i][j - 1]][j - 1];
high[0] = -1;

