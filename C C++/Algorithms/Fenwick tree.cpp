ll get_lit(int x) {
    ll res = 0;
    for (; x >= 1; x &= x - 1) res += tree[x];
    return res;
}
(Tính tổng từ 1 -> x trong fenwick tree)

ll get_mul(int l, int r) {
    return (get_lit(r) - get_lit(l - 1));
}
(Tính tổng từ l -> r trong fenwick tree)

void update(int x, int v) {
    for (; x <= n; x += x & -x) tree[x] += v;
}
(Cập nhật phần tử x lên một lượng value trong fenwick tree)

update(x, value - a[x]);
a[x] = value;
(Gán phần tử x thành value trong fenwick tree)
