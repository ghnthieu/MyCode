#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
#define bk back
#define fr front
#define pb pop_back
#define pf pop_front
#define pub push_back
#define puf push_front
#define sz(x) (ll)(x.size())
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define biti(i, x) ((1ll << (i)) & (x))
#define boolbit(i, x) (biti(i, x) != 0)
#define optm(v) v.resize(unique(all(v)) - v.begin())
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define vec(kdl) vector <kdl>
#define ii pair<int,int>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1, kdl2>, kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1, kdl2>, kdl3>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define forr(i, l, r) for (int i = l; i <= r; i++)
#define fodd(i, l, r) for (int i = l; i >= r; i--)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }

typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 3e5 + 7;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int n, a[N], b[N], tree[mask(20) + 7];

void update(int id, int l, int r, int u, int val) {
    while (l < r) {
        int m = l + r >> 1;
        if (m >= u) {
            r = m;
            id <<= 1;
        }
        else {
            l = m + 1;
            id = id << 1 | 1;
        }
    }

    tree[id] = ((val > 0) ? u : 0);

    while (id > 1) {
        id >>= 1;
        tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
    }
}

int get(int id, int l, int r, int u) {
    int res = 0;
    while (l < r) {
        int m = l + r >> 1;
        if (m < u) {
            maximize(res, tree[id << 1]);
            id = id << 1 | 1;
            l = m + 1;
        }
        else {
            id <<= 1;
            r = m;
        }
    }
    return max(res, tree[id]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    int sum = 0;
    For(i, 1, n, 1) cin >> a[i];
    For(i, 1, n, 1) {
        cin >> b[i];
        sum += b[i];
    }

    int ans = 0;
    For(i, 1, n, 1) update(1, 1, n, i, a[i]);
    For(i, 2, n, 1) {
        int idx;
        while (b[i] && (idx = get(1, 1, n, i - 1))) {
            int val = min(a[idx], b[i]);
            ans += val; sum -= val;
            b[i] -= val; a[idx] -= val;
            update(1, 1, n, idx, a[idx]);
        }
    }

    For(i, 1, n, 1) ans += min(a[i], b[i]);
    cout << ans - sum;

    return 0;
}
