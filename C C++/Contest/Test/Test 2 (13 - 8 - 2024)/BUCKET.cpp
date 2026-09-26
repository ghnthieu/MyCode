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
const int N = (int) 3e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

struct Data {
    int r_nap, r_thung;
};

int n;
Data a[N];

void sub1(void) {
    //Check -1
    vec(int) luu_nap, luu_thung;
    For(i, 1, n, 1) {
        luu_nap.pub(a[i].r_nap);
        luu_thung.pub(a[i].r_thung);
    }
    sort(all(luu_nap)); sort(all(luu_thung));
    Rep(i, n) if (luu_nap[i] < luu_thung[i]) {
        cout << -1;
        return;
    }

    //Calc ans
    int ans = -1;
    Rep(k, mask(n)) {
        luu_nap.clear(); luu_thung.clear();
        int sl_bit1 = 0;
        bool check = true;
        Rep(i, n) {
            if (bit(k, i)) {
                ++sl_bit1;
                luu_nap.pub(a[i + 1].r_nap);
                luu_thung.pub(a[i + 1].r_thung);
            }
            else {
                if (a[i + 1].r_nap < a[i + 1].r_thung) {
                    check = false;
                    break;
                }
            }
            if (!check) break;
        }
        if (!check) continue;
        sort(all(luu_nap)); sort(all(luu_thung));
        Rep(i, n) if (luu_nap[i] < luu_thung[i]) {
            check = false;
            break;
        }
        if (check) maximize(ans, n - sl_bit1);
    }
    cout << ans;
}

ii(int, int) tree[4 * N];

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || pos > r) return;
    if (l == pos && pos == r)
        tree[id] = {val, l};
    else {
        int m = l + r >> 1;
        update(id << 1, l, m, pos, val);
        update(id << 1 | 1, m + 1, r, pos, val);
        tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
    }
}

ii(int, int) get(int id, int l, int r, int u, int v) {
    if (l > v || u > r) return {0, -1};
    if (l >= u && v >= r) return tree[id];
    int m = l + r >> 1;
    return max(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
}

void sub2(void) {
    //Check -1
    vec(int) luu_nap, luu_thung;
    For(i, 1, n, 1) {
        luu_nap.pub(a[i].r_nap);
        luu_thung.pub(a[i].r_thung);
    }
    sort(all(luu_nap)); sort(all(luu_thung));
    Rep(i, n) if (luu_nap[i] < luu_thung[i]) {
        cout << -1;
        return;
    }

    //Calc ans
    priority_queue <ii(int, int), vii(int, int), greater <ii(int, int)>> pq;
    vii(int, int) thoa;
    For(i, 1, n, 1) {
        if (a[i].r_nap < a[i].r_thung) {
            pq.push({a[i].r_nap, 1}); //1 la nap
            pq.push({a[i].r_thung, 0}); //0 la thung
        }
        else
            thoa.pub({a[i].r_thung, a[i].r_nap});
    }
    sort(all(thoa));

    int pre = 0, ans = thoa.size(), idx = 0;
    while (!pq.empty()) {
        ii(int, int) top = pq.top(); pq.pop();
        pre += ((top.se == 0) ? 1 : (-1));

        while (idx < thoa.size() && thoa[idx].fi <= top.fi) {
            update(1, 0, thoa.size() - 1, idx, thoa[idx].se);
            ++idx;
        }

        while (pre < 0) {
            ii(int, int) tmp = get(1, 0, thoa.size() - 1, 0, idx - 1);
            if (tmp.fi <= 0 || tmp.se == -1) break;
            ++pre;
            --ans;
            pq.push({tmp.fi, 1});
            update(1, 0, thoa.size() - 1, tmp.se, -1);
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("BUCKET.inp", "r", stdin);
    freopen("BUCKET.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n;
    For(i, 1, n, 1) cin >> a[i].r_nap >> a[i].r_thung;

    if (n <= 18)
        sub1();
    else
        sub2();

    return 0;
}
