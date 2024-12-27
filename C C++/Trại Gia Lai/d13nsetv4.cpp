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
#define __Trung_Hieu___ signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
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
const int N = (int) 1e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int q;
set <int> st;

void init(void) {
    string mau1 = "0000068";
    For(i1, 0, 3, 1) For(i2, 0, 9, 1) For(i3, 0, 9, 1) For(i4, 0, 9, 1) For(i5, 0, 9, 1) {
        string tmp = mau1;
        tmp[0] = char(i1 + '0');
        tmp[1] = char(i2 + '0');
        tmp[2] = char(i3 + '0');
        tmp[3] = char(i4 + '0');
        tmp[4] = char(i5 + '0');
        int ttmp = stoi(tmp);
        st.insert(ttmp);
    }

    string mau2 = "0000680";
    For(i1, 0, 3, 1) For(i2, 0, 9, 1) For(i3, 0, 9, 1) For(i4, 0, 9, 1) For(i5, 0, 9, 1) {
        string tmp = mau2;
        tmp[0] = char(i1 + '0');
        tmp[1] = char(i2 + '0');
        tmp[2] = char(i3 + '0');
        tmp[3] = char(i4 + '0');
        tmp[6] = char(i5 + '0');
        int ttmp = stoi(tmp);
        st.insert(ttmp);
    }

    string mau3 = "0006800";
    For(i1, 0, 3, 1) For(i2, 0, 9, 1) For(i3, 0, 9, 1) For(i4, 0, 9, 1) For(i5, 0, 9, 1) {
        string tmp = mau3;
        tmp[0] = char(i1 + '0');
        tmp[1] = char(i2 + '0');
        tmp[2] = char(i3 + '0');
        tmp[5] = char(i4 + '0');
        tmp[6] = char(i5 + '0');
        int ttmp = stoi(tmp);
        st.insert(ttmp);
    }

    string mau4 = "0068000";
    For(i1, 0, 3, 1) For(i2, 0, 9, 1) For(i3, 0, 9, 1) For(i4, 0, 9, 1) For(i5, 0, 9, 1) {
        string tmp = mau4;
        tmp[0] = char(i1 + '0');
        tmp[1] = char(i2 + '0');
        tmp[4] = char(i3 + '0');
        tmp[5] = char(i4 + '0');
        tmp[6] = char(i5 + '0');
        int ttmp = stoi(tmp);
        st.insert(ttmp);
    }

    string mau5 = "0680000";
    For(i1, 0, 3, 1) For(i2, 0, 9, 1) For(i3, 0, 9, 1) For(i4, 0, 9, 1) For(i5, 0, 9, 1) {
        string tmp = mau5;
        tmp[0] = char(i1 + '0');
        tmp[3] = char(i2 + '0');
        tmp[4] = char(i3 + '0');
        tmp[5] = char(i4 + '0');
        tmp[6] = char(i5 + '0');
        int ttmp = stoi(tmp);
        st.insert(ttmp);
    }
}

int n, a[N];
ii(int, int) tree[4 * N];

void build(int id, int l, int r) {
    if (l == r)
        tree[id] = {a[l], l};
    else {
        int m = l + r >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        tree[id] = min(tree[id << 1], tree[id << 1 | 1]);
    }
}

ii(int, int) find_idx(int id, int l, int r, int idx) {
    while (l <= r) {
        if (l == r) break;
        int m = l + r >> 1;
        if (idx <= m) {
            id <<= 1;
            r = m;
        }
        else {
            id = id << 1 | 1;
            l = m + 1;
        }
    }
    return tree[id];
}

ii(int, ll) que[N];

void sub1(void) {
    n = 0;
    for (auto x : st) a[++n] = x;
    build(1, 1, n);
    For(i, 1, q, 1) {
        ll idx = que[i].se;
        cout << find_idx(1, 1, n, idx).fi << '\n';
    }
}

void sub2(void) {
    For(i, 1, q, 1) {
        int type = que[i].fi;
        if (type == 1) {
            ll val = que[i].se;
            if (st.find(val) != st.end())
                st.erase(st.find(val));
            else
                st.insert(val);
        }
        else {
            ll idx = que[i].se; int cnt = 0;
            for (auto x : st) if (++cnt == idx) {
                cout << x << '\n';
                break;
            }
        }
    }
}

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    init();

    cin >> q;
    bool check_sub1 = true;
    For(i, 1, q, 1) {
        cin >> que[i].fi >> que[i].se;
        if (que[i].fi == 1) check_sub1 = false;
    }

    if (check_sub1)
        sub1();
    else
        sub2();

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
