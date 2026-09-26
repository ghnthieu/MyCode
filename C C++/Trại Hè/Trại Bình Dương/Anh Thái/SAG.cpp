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
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, k, m, in[N], ou[N], din[N], dou[N];
vii(int, char) inp[N];

void solve(string s) {
    int u = 0, v = 0, i = 0; char ss;
    while (i < s.length()) {
        if ('0' <= s[i] && s[i] <= '9') u = u * 10 + (s[i] - '0');
        else break;
        ++i;
    }
    ss = s[i]; ++i;
    while (i < s.length()) { v = v * 10 + (s[i] - '0'); ++i; }

    inp[u].pub({v, ss});
    if (ss == '=')
        inp[v].pub({u, ss});
    else if (ss == '<') {
        ++in[v]; ++ou[u];
        inp[v].pub({u, '>'});
    }
    else {
        ++in[u]; ++ou[v];
        inp[v].pub({u, '<'});
    }
}

void solve_ou(void) {
    priority_queue <ii(int, int)> pq;
    For(i, 1, n, 1) if (!ou[i])
        pq.push({0, i});
    while (!pq.empty()) {
        int i = pq.top().se;
        if (dou[i] > pq.top().fi) {
            pq.pop();
            continue;
        }
        pq.pop();
        for (ii(int, int) x : inp[i]) {
            if (x.se == '=') {
                if (dou[x.fi] < dou[i]) {
                    dou[x.fi] = dou[i];
                    pq.push({dou[x.fi], x.fi});
                }
            }
            else if (x.se == '>') {
                if (dou[x.fi] < dou[i] + 1) {
                    dou[x.fi] = dou[i] + 1;
                    pq.push({dou[x.fi], x.fi});
                }
            }
        }
    }
}

void solve_in(void) {
    priority_queue <ii(int, int)> pq;
    For(i, 1, n, 1) if (!in[i])
        pq.push({0, i});
    while (!pq.empty()) {
        int i = pq.top().se;
        if (din[i] > pq.top().fi) {
            pq.pop();
            continue;
        }
        pq.pop();
        for (ii(int, int) x : inp[i]) {
            if (x.se == '=') {
                if (din[x.fi] < din[i]) {
                    din[x.fi] = din[i];
                    pq.push({din[x.fi], x.fi});
                }
            }
            else if (x.se == '<') {
                if (din[x.fi] < din[i] + 1) {
                    din[x.fi] = din[i] + 1;
                    pq.push({din[x.fi], x.fi});
                }
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

    cin >> n >> k >> m;
    Rep(inp_str, m) {
        string s; cin >> s;
        solve(s);
    }

    solve_ou();
    solve_in();

    For(i, 1, n, 1) cout << ((din[i] + dou[i] == k - 1) ? char('a' + din[i]) : ('?'));

    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}
