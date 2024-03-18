ll sum(int x) {
    ll ans = 0;
    while (x > 0) {
        ans += bit[x];
        x -= (x & (-x));
    }
    return ans;
}
(Tính tổng từ 1 -> x trong fenwick tree)

void update(int x, int value) {
    while (x <= n) {
        bit[x] += value;
        x += (x & (-x));
    }
}
(Cập nhật phần tử x lên một lượng value trong fenwick tree)

update(x, value - a[x]);
a[x] = value;
(Gán phần tử x thành value trong fenwick tree)