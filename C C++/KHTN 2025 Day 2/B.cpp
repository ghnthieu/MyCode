#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb pop_back
#define pub push_back
#define __Trung_Hieu___ signed main()
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
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

int n, q, x;
string s;

struct Fenwick {

    vec(int) bit;

    Fenwick() {
        bit.assign(N, 0);
    }

    void update(int i, int d) {
        while (i < N) {
            bit[i] += d;
            i += i & -i;
        }
    }

    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }

    int range_query(int l, int r) {
        return query(r) - query(l - 1);
    }

} fen[26];

__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);

    cin >> n >> q >> x >> s;
    s = "l" + s;

    For(i, 1, n, 1) fen[(s[i] - 'a')].update(i, 1);

    Rep(query, q) {
        char type;
        cin >> type;
        if (type == '!') {
            int pos; char ch;
            cin >> pos >> ch;
            int old_id = (s[pos] - 'a'), new_id = (ch - 'a');
            fen[old_id].update(pos, -1);
            fen[new_id].update(pos, 1);
            s[pos] = ch;
        }
        else {
            int l, r; ll T;
            cin >> l >> r >> T;

            vec(int) freq(26, 0), powers;
            Rep(i, x)
                freq[i] = fen[i].range_query(l, r);
            Rep(i, x) Rep(j, freq[i])
                powers.pub(mask(i));

            ll sum = 0;
            for (int v : powers) sum += v;

            if ((T + sum) % 2 != 0 || abs(T) > sum) {
                cout << "NO" << '\n';
                continue;
            }

            ll target = (T + sum) / 2;
            bitset <N> bs; bs[0] = 1;
            for (int v : powers)
                bs |= (bs << v);

            cout << (((target < N) && (bs[target])) ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
