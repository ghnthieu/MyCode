#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define bk back
#define fr front
#define pb pop_back
#define pf pop_front
#define pub push_back
#define puf push_front
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1, kdl2>, kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1, kdl2>, kdl3>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 5e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int len, q;
string s;

struct Data {
    int l, r; char cha;
} que[N];

bool check(int l, int r) {
    int cnt = 0;
    For(i, l, r, 1) {
        cnt += ((s[i] == '(') ? 1 : (-1));
        if (cnt < 0) return false;
    }
    return ((cnt == 0) ? true : false);
}

void sub1(void) {
    For(i, 1, q, 1) {
        if (que[i].cha == '(') {
            For(j, que[i].l, que[i].r, 1) s[j] = '(';
        }
        else if (que[i].cha == ')') {
            For(j, que[i].l, que[i].r, 1) s[j] = ')';
        }
        else if (que[i].cha == '-') {
            For(j, que[i].l, que[i].r, 1) s[j] = ((s[j] == '(') ? ')' : '(');
        }
        else {
            cout << ((check(que[i].l, que[i].r)) ? "yes" : "no") << '\n';
        }
    }
}

struct Node {
    int open, close;
};

Node tree[4 * N];

Node calc(Node l, Node r) {
    int tmp = min(l.open, r.close);
    return {l.open + r.open - tmp, l.close + r.close - tmp};
}

void build(int id, int l, int r) {
    if (l == r) {
        if (s[l] == '(') tree[id] = {1, 0};
        else tree[id] = {0, 1};
    }
    else {
        int m = l + r >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        tree[id] = calc(tree[id << 1], tree[id << 1 | 1]);
    }
}

Node get_ans(int id, int l, int r, int u, int v) {
    if (l > v || u > r) return {0, 0};
    if (l >= u && v >= r) return tree[id];
    int m = l + r >> 1;
    return calc(get_ans(id << 1, l, m, u, v), get_ans(id << 1 | 1, m + 1, r, u, v));
}

void sub2(void) {
    build(1, 1, len);
    For(i, 1, q, 1) {
        Node tmp = get_ans(1, 1, len, que[i].l, que[i].r);
        cout << ((tmp.open == 0 && tmp.close == 0) ? "yes" : "no") << '\n';
    }
}

void update(int id, int l, int r, int pos, char ch) {
    if (l == r) {
        if (ch == '(') tree[id] = {1, 0};
        else tree[id] = {0, 1};
    }
    else {
        int m = l + r >> 1;
        if (pos <= m)
            update(id << 1, l, m, pos, ch);
        else
            update(id << 1 | 1, m + 1, r, pos, ch);
        tree[id] = calc(tree[id << 1], tree[id << 1 | 1]);
    }
}

void sub3(void) {
    build(1, 1, len);
    For(i, 1, q, 1) {
        if (que[i].cha == '(') {
            update(1, 1, len, que[i].l, '(');
            s[que[i].l] = '(';
        }
        else if (que[i].cha == ')') {
            update(1, 1, len, que[i].r, ')');
            s[que[i].r] = ')';
        }
        else if (que[i].cha == '-') {
            if (s[que[i].l] == '(') update(1, 1, len, que[i].l, ')');
            else update(1, 1, len, que[i].r, '(');
            s[que[i].l] = ((s[que[i].r] == '(') ? ')' : '(');
        }
        else {
            Node tmp = get_ans(1, 1, len, que[i].l, que[i].r);
            cout << ((tmp.open == 0 && tmp.close == 0) ? "yes" : "no") << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("QBRAC.INP", "r", stdin);
    freopen("QBRAC.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> len >> q >> s;
    s = "h" + s;
    bool check_sub2 = true, check_sub3 = true;
    For(i, 1, q, 1) {
        cin >> que[i].l >> que[i].r >> que[i].cha;
        if (que[i].cha != '?') check_sub2 = false;
        if (que[i].cha != '?' && que[i].l != que[i].r) check_sub3 = false;
    }

    if (1ll * len * q <= 1e6)
        sub1();
    else if (check_sub2)
        sub2();
    else if (check_sub3)
        sub3();
    else
        sub1();

    return 0;
}
