int tree[4 * N];
void build(int id, int l, int r) {
    if (l == r)
        tree[id] = a[l];
    else {
        int mid = l + r >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        tree[id] = min(tree[id << 1], tree[id << 1 | 1]);
    }
}

int find_min(int id, int l, int r, int u, int v) {
    if (u > r || l > v) return INT_MAX;
    if (u <= l && r <= v) 
        return tree[id];
    else {
        int m = l + r >> 1;
        return max(find_min(id << 1, l, m, u, v), find_min(id << 1 | 1, m + 1, r, u, v));
    }
}

void update(int id, int l, int r, int pos, int value) {
    if (l == r)
        tree[id] = value;
    else {
        int m = l + r >> 1;
        if (pos <= m)
            update(id << 1, l, m, pos, value);
        else
            update(id << 1 | 1, m + 1, r, pos, value);
        tree[id] = min(tree[id << 1], tree[id << 1 | 1]);
    }
}
