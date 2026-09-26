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
const int N = (int) 2e6 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q, a[N];
ll pre[N];

struct Data {
    int type, x, y;
} que[N];

void sub1(void) {
    For(i, 1, q, 1) {
        int type = que[i].type;
        if (type == 1) {
            int idx = que[i].x, val = que[i].y;
            a[idx] = val; pre[0] = 0;
            For(i, 1, n, 1) pre[i] = pre[i - 1] + a[i];
        }
        else {
            int l = que[i].x, r = que[i].y;
            ll ans = pre[n];
            For(i, 1, n, 1) minimize(ans, abs((pre[i] - pre[l - 1]) - (pre[r] - pre[i])));
            cout << ans << '\n';
        }
    }
}

void sub2(void) {
    For(i, 1, q, 1) {
        int l = que[i].x, r = que[i].y;
        ll sum = pre[r] - pre[l - 1]; ll can = sum / 2ll;
        int left = l, right = r; ll ans1 = 0;
        while (left <= right) {
            int mid = left + right >> 1;
            if (pre[mid] - pre[l - 1] <= can) {
                maximize(ans1, pre[mid] - pre[l - 1]);
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        left = l, right = r; ll ans2 = 0;
        while (left <= right) {
            int mid = left + right >> 1;
            if (pre[r] - pre[mid - 1] <= can) {
                maximize(ans2, pre[r] - pre[mid - 1]);
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        cout << min(abs(ans1 - (sum - ans1)), abs(ans2 - (sum - ans2))) << '\n';
    }
}

ll tree[4 * N], lazy[4 * N];

void build(int id, int l, int r) {
    if (l == r)
        tree[id] = pre[l];
    else {
        int mid = l + r >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
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
}

ll find_index(int v, int treel, int treer, int index) {
    while (treel <= treer) {
        fix(v, treel, treer);
        if (treel == treer) break;
        int treem = treel + treer >> 1;
        if (index <= treem) {
            v <<= 1;
            treer = treem;
        }
        else {
            v = v << 1 | 1;
            treel = treem + 1;
        }
    }
    return tree[v];
}

void sub3(void) {
    build(1, 1, n);
    For(i, 1, q, 1) {
        int type = que[i].type;
        if (type == 1) {
            int idx = que[i].x, val = que[i].y;
            update(1, 1, n, idx, n, -a[idx]);
            a[idx] = val;
            update(1, 1, n, idx, n, val);
        }
        else {
            int l = que[i].x, r = que[i].y;
            ll cal_l = ((l - 1 == 0) ? 0 : find_index(1, 1, n, l - 1));
            ll sum = find_index(1, 1, n, r) - cal_l; ll can = sum / 2ll;
            int left = l, right = r; ll ans1 = 0;
            while (left <= right) {
                int mid = left + right >> 1;
                ll cal_l = ((l - 1 == 0) ? 0 : find_index(1, 1, n, l - 1));
                if (find_index(1, 1, n, mid) - cal_l <= can) {
                    maximize(ans1, find_index(1, 1, n, mid) - cal_l);
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            left = l, right = r; ll ans2 = 0;
            while (left <= right) {
                int mid = left + right >> 1;
                ll cal_m = ((mid - 1 == 0) ? 0 : find_index(1, 1, n, mid - 1));
                if (find_index(1, 1, n, r) - cal_m <= can) {
                    maximize(ans2, find_index(1, 1, n, r) - cal_m);
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            cout << min(abs(ans1 - (sum - ans1)), abs(ans2 - (sum - ans2))) << '\n';
        }
    }
}

void sub4(void) {}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TOY.inp", "r", stdin);
    freopen("TOY.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    pre[0] = 0;
    For(i, 1, n, 1) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    bool check_sub2 = true;
    For(i, 1, q, 1) {
        cin >> que[i].type >> que[i].x >> que[i].y;
        if (que[i].type == 1) check_sub2 = false;
    }

    if (n <= 5e3 && q <= 5e3)
        sub1();
    else if (check_sub2)
        sub2();
    else if (n <= 2e5 && q <= 2e5)
        sub3();
    else
        sub4();

    return 0;
}
