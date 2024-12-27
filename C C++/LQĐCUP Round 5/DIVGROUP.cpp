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
const int N = (int) 2e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, q, a[N], cnt[N];
ii(int, int) que[N];

void sub1(void) {
    For(i, 1, q, 1) {
        int l = que[i].fi, r = que[i].se;
        cout << r - l + 1 << '\n';
    }
}

void sub2(void) {
    For(i, 1, q, 1) {
        int l = que[i].fi, r = que[i].se;
        memset(cnt, 0, (n + 1) * sizeof(int));
        bool check = true;
        For(j, l, r, 1) if (++cnt[a[j]] > 1) {
            check = false;
            break;
        }
        if (check) {
            cout << 1 << '\n';
            continue;
        }

        vec(vec(int)) luu; vec(int) tmp1, tmp2;
        For(j, l, r, 2) tmp1.pub(a[j]);
        For(j, l + 1, r, 2) tmp2.pub(a[j]);
        luu.pub(tmp1); luu.pub(tmp2);
        while (true) {
            bool conti = true;
            int sz = luu.size();
            Rep(j, sz) {
                memset(cnt, 0, (n + 1) * sizeof(int));
                bool check = true;
                for (int k : luu[j]) if (++cnt[k] > 1) {
                    check = false;
                    break;
                }
                if (!check) conti = false;
                if (!check) {
                    vec(int) tmp1, tmp2;
                    For(k, 0, luu[j].size() - 1, 2) tmp1.pub(luu[j][k]);
                    For(k, 1, luu[j].size() - 1, 2) tmp2.pub(luu[j][k]);
                    luu[j].clear();
                    luu.pub(tmp1); luu.pub(tmp2);
                }
            }
            if (conti) break;
        }

        int ans = 0;
        Rep(j, luu.size()) if (!luu[j].empty())
            ++ans;
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DIVGROUP.inp", "r", stdin);
    freopen("DIVGROUP.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> q;
    bool check_sub1 = true;
    For(i, 1, n, 1) {
        cin >> a[i];
        if (a[i] != 1) check_sub1 = false;
    }
    For(i, 1, q, 1) cin >> que[i].fi >> que[i].se;

    if (check_sub1)
        sub1();
    else
        sub2();

    return 0;
}
