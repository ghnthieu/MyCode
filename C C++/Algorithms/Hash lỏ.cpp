int pw[N], hs[N];
//Chuẩn bị mảng hash
void solve() {
    pw[0] = 1;
    for (int i=1; i<N; ++i)
        pw[i] = 1ll * pw[i - 1] * Sl % MOD;
    s = " " + s;
    for (int i=1; i<s.length(); ++i)
        hs[i] = (hs[i - 1] + 1ll * s[i] * pw[i]) % MOD;
}

//Lấy mã đoạn hash [l .. r]
int gethash(int l, int r) {
    return ((1ll * (hs[r] - hs[l - 1] + MOD) * pw[N - r]) % MOD);
}

//Kiểm tra xâu dài len từ vị trí u và v có bằng nhau không
bool check(int u, int v, int len) {
    return ((gethash(u, u + len - 1) == gethash(v, v + 1 - len)) ? true : false);
}

//MOD = 1e9 + 7;
//N = 1e6 + 7;
//Sl = 256;

//Trả về độ dài tiền tố dài nhất bắt đầu từ u và v
int getlcp(int u, int v) {
    s = " " + s;
    if (s[u] != s[v]) return 0;
    int l = 1, r = s.length() - max(u, v);
    while (true) {
        if (l == r) return r;
        if (r - l == 1) return ((gethash(u, u + r - 1) == gethash(v, v + r - 1)) ? r : l);
        int mid = l + r >> 1;
        if (gethash(u, u + mid - 1) == gethash(v, v + mid - 1))
            l = mid;
        else
            r = mid - 1;
    }
}

//So sánh thứ tự từ điển của 2 xâu [l .. r] và [u .. v]
//Trả về -1 nếu [l .. r] < [u .. v]
//Trả về 0 nếu [l .. r] == [u .. v]
//Trả về 1 nếu [l .. r] > [u .. v]
int cmp(int l, int r, int u, int v) {
    if (r - l > v - u) return -cmp(u, v, l, r);
    int tmp = getlcp(l, u);
    if (tmp >= r - l + 1) return ((r - l == v - u) ? 0 : -1);
    s = " " + s;
    if (s[l + tmp] > s[u + tmp]) return 1;
    if (s[l + tmp] == s[u + tmp]) return 0;
    if (s[l + tmp] < s[u + tmp]) return -1;
}
