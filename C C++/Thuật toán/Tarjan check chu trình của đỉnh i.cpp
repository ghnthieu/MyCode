void dfs(int u) {
    low[u] = num[u] = ++cnt;
    st.push(u);
    for (int v : inp[u]) {
        if (!tid[v]) {
            if (!num[v]) {
                dfs(v);
                minimize(low[u], low[v]);
            }
            else
                minimize(low[u], num[v]);
        }
    }
    if (low[u] == num[u]) {
        ++tpltm;
        int v = 0, tcnt = 0;
        do {
            v = st.top(); st.pop();
            tid[v] = 1;
            if (++tcnt > 1)
                check[tpltm] = true;
        } while (u != v);
    }
}

for (int i=1; i<=n; ++i) {
    if (!num[i])
        dfs(i);
}