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

class Captain {
public:
    Captain() {}

    string encode(string time) {
        int hh, mm, ss; sscanf(time.c_str(), "%d:%d:%d", &hh, &mm, &ss);
        vec(int) bits(17);
        Rep(i, 5) bits[i] = (hh >> (4 - i)) & 1;
        Rep(i, 6) bits[5 + i] = (mm >> (5 - i)) & 1;
        Rep(i, 6) bits[11 + i] = (ss >> (5 - i)) & 1;
        vec(int) word(23, 0);

        int idx = 0;
        For(i, 1, 22, 1) {
            if (i == 1 || i == 2 || i == 4 || i == 8 || i == 16) continue;
            else word[i] = bits[idx++];
        }

        Rep(p, 5) {
            int pos = 1 << p, poss = 0;
            For(i, 1, 22, 1) if (i & pos)
                poss ^= word[i];
            word[pos] = poss;
        }

        string res = "";
        For(i, 1, 22, 1) res += ((word[i]) ? '1' : '0');
        return res;
    }
};

class Soldier {
private:
    int id;

public:
    Soldier(int id) : id(id) {}

    string decode(string s) {
        vec(int) word(23, 0);
        Rep(i, 22) word[i + 1] = s[i] - '0';
        int tmp = 0;
        Rep(p, 5) {
            int pos = 1 << p, poss = 0;
            For(i, 1, 22, 1) if (i & pos)
                poss ^= word[i];
            if (poss) tmp += pos;
        }

        if (tmp != 0 && tmp <= 22) word[tmp] ^= 1;

        vec(int) bits(17);
        int idx = 0;
        For(i, 1, 22, 1) {
            if (i == 1 || i == 2 || i == 4 || i == 8 || i == 16) continue;
            else bits[idx++] = word[i];
        }

        int hh = 0, mm = 0, ss = 0;
        Rep(i, 5) hh = (hh << 1) | bits[i];
        Rep(i, 6) mm = (mm << 1) | bits[5 + i];
        Rep(i, 6) ss = (ss << 1) | bits[11 + i];
        char str[9];
        sprintf(str, "%02d:%02d:%02d", hh, mm, ss);
        return string(str);
    }
};

#include "main.h"
