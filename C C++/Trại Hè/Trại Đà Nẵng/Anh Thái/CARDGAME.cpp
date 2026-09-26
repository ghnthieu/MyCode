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
const string card[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
const string chat[] = {"P", "C", "T", "H"};

/*-----------------------------------------------------------------------------------------------------------------*/

class An {
public:
    An() {}

    vec(string) pick(vec(string) a) {
        string s = a[5]; a.pb();
        vec(int) hv; For(i, 1, 5, 1) hv.pub(i);
        vec(vec(int)) luu; luu.pub(hv);
        while (next_permutation(all(hv))) luu.pub(hv);
        map <string, int> mp;
        Rep(i, 52) {
            string s1 = card[i / 4];
            string s2 = chat[i % 4];
            string s3 = s1 + s2;
            mp[s3] = i;
        }
        vec(int) ans = luu[mp[s]];
        vii(int, string) luu_cap;
        for (string x : a) luu_cap.pub({mp[x], x});
        sort(all(luu_cap));
        vec(string) luu_ans;
        for (int x : ans) luu_ans.pub(luu_cap[x - 1].se);
        return luu_ans;
    }
};

class Binh {
public:
    Binh() {}

    string guess(vec(string) b) {
        vec(int) hv; For(i, 1, 5, 1) hv.pub(i);
        vec(vec(int)) luu; luu.pub(hv);
        while (next_permutation(all(hv))) luu.pub(hv);
        map <string, int> mp;
        Rep(i, 52) {
            string s1 = card[i / 4];
            string s2 = chat[i % 4];
            string s3 = s1 + s2;
            mp[s3] = i;
        }
        vec(int) tmp;
        Rep(i, 5) {
            int cnt = 1;
            Rep(j, 5) if (i != j) if (mp[b[i]] > mp[b[j]])
                ++cnt;
            tmp.pub(cnt);
        }

        int pos = -1;
        Rep(i, luu.size()) if (luu[i] == tmp)
            pos = i;
        string ans = card[pos / 4] + chat[pos % 4];
        return ans;
    }
};

#include "main.h"
