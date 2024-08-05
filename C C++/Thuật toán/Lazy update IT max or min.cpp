int tree[4 * N];
void build(int id, int l, int r) {
    if (l == r)
        tree[id] = a[l];
    else {
        int mid = l + r >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
    }
}

void fix(int id, int l, int r) {
    if (!lazy[id]) return;
    tree[id] += lazy[id];
    if (l != r) {
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    fix(id, l, r);
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        lazy[id] += val;
        fix(id, l, r);
        return;
    }
    int m = l + r >> 1;
    update(id << 1, l, m, u, v, val);
    update(id << 1 | 1, m + 1, r, u, v, val);
    tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
}

int find_max(int id, int l, int r, int u, int v) {
    fix(id, l, r);
    if (u > r || l > v) return 0;
    if (u <= l && r <= v) 
        return tree[id];
    else {
        int m = l + r >> 1;
        return max(find_max(id << 1, l, m, u, v), find_max(id << 1 | 1, m + 1, r, u, v));
    }
}
