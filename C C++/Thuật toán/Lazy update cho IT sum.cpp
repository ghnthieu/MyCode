void fix(int v, int l, int r) {
    if (!lazy[v])
        return;
    tree[v] += (r - l + 1) * lazy[v];
    if (l != r) {
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
}
(Lazy update cho segment tree sum)