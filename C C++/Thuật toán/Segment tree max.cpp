void build(int v, int l, int r) {
    if (l == r)
        tree[v] = a[l];
    else {
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
}
(Xây dựng segment tree cho truy vấn max)

int findmax(int v, int treel, int treer, int l, int r) {
    if (l > r)
        return -1;
    if (treel == l && treer == r)
        return tree[v];
    else {
        int treem = (treel + treer) / 2;
        return max(findmax(2 * v, treel, treem, l, min(treem, r)), findmax(2 * v + 1, treem + 1, treer, max(treem + 1, l), r));
    }
}
(Truy vấn max từ l -> r)

void update(int v, int l, int r, int pos, int value) {
    if (l == r)
        tree[v] = value;
    else {
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * v, l, mid, pos, value);
        else
            update(2 * v + 1, mid + 1, r, pos, value);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
}
(Thay đổi giá trị pos trong mảng thành giá trị value cho truy vấn max)