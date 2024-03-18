void dfs1(int u, int prt) {
    dp1[u] = 0;
    for (int v : inp[u]) {
        if (v != prt && !kdb[v]) {
            dfs1(v, u);
            maximize(dp1[u], dp1[v] + 1);
        }
    }
}

void dfs2(int u, int prt) {
    ii(int, int) tmp = {-1, -1};
    for (int v : inp[u]) {
        if (v != prt && !kdb[v]) {
            if (dp1[v] > tmp.fi) {
                tmp.se = tmp.fi;
                tmp.fi = dp1[v];
            }
            else
                maximize(tmp.se, dp1[v]);
        }
    }
    for (int v : inp[u]) {
        if (v != prt && !kdb[v]) {
            dp2[v] = dp2[u] + 1;
            maximize(dp2[v], ((dp1[v] != tmp.fi) ? tmp.fi : tmp.se) + 2);
            dfs2(v, u);
        }
    }
}

int goc = 1;
while (kdb[goc])
    ++goc;
dfs1(goc, -1);
dfs2(goc, -1);
int mxdi = -1;
for (int i=1; i<=n; ++i) {
    if (mxdi < max(dp1[i], dp2[i]))
        maximize(mxdi, max(dp1[i], dp2[i]));
}