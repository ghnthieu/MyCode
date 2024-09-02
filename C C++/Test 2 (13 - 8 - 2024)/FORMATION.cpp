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
const int N = (int) 2e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, k;
bool have[N][N];

void sub1(void) {
    ll ans = 0;
    For(eni, 1, n, 1) For(enj, 1, m, 1) {
        vec(int) luu;
        For(sti, 1, n, 1) For(stj, 1, m, 1) if (have[sti][stj])
            luu.pub(abs(eni - sti) + abs(enj - stj));
        sort(all(luu));
        Rep(i, k) ans += luu[i];
    }
    cout << ans;
}

void sub2(void) {
    ll ans = 0;
    int enil = 1, enir = n;
    while (enil <= enir) {
        int enjl = 1, enjr = m;
        while (enjl <= enjr) {
            vec(int) luu;
            int stil = 1, stir = n;
            while (stil <= stir) {
                if (stil != stir) {
                    int stjl = 1, stjr = m;
                    while (stjl <= stjr) {
                        if (have[stil][stjl]) luu.pub(abs(enil - stil) + abs(enjl - stjl));
                        if (have[stir][stjl]) luu.pub(abs(enil - stir) + abs(enjl - stjl));

                        if (stjl != stjr) {
                            if (have[stil][stjr]) luu.pub(abs(enil - stil) + abs(enjl - stjr));
                            if (have[stir][stjr]) luu.pub(abs(enil - stir) + abs(enjl - stjr));
                        }
                        ++stjl; --stjr;
                    }
                }
                else {
                    int stjl = 1, stjr = m;
                    while (stjl <= stjr) {
                        if (have[stil][stjl]) luu.pub(abs(enil - stil) + abs(enjl - stjl));
                        if (stjl != stjr)
                            if (have[stil][stjr]) luu.pub(abs(enil - stil) + abs(enjl - stjr));
                        ++stjl; --stjr;
                    }
                }
                ++stil; --stir;
            }
            sort(all(luu));
            Rep(i, k) ans += luu[i];

            if (enjl != enjr) {
                vec(int) luu;
                int stil = 1, stir = n;
                while (stil <= stir) {
                    if (stil != stir) {
                        int stjl = 1, stjr = m;
                        while (stjl <= stjr) {
                            if (have[stil][stjl]) luu.pub(abs(enil - stil) + abs(enjr - stjl));
                            if (have[stir][stjl]) luu.pub(abs(enil - stir) + abs(enjr - stjl));

                            if (stjl != stjr) {
                                if (have[stil][stjr]) luu.pub(abs(enil - stil) + abs(enjr - stjr));
                                if (have[stir][stjr]) luu.pub(abs(enil - stir) + abs(enjr - stjr));
                            }
                            ++stjl; --stjr;
                        }
                    }
                    else {
                        int stjl = 1, stjr = m;
                        while (stjl <= stjr) {
                            if (have[stil][stjl]) luu.pub(abs(enil - stil) + abs(enjr - stjl));
                            if (stjl != stjr)
                                if (have[stil][stjr]) luu.pub(abs(enil - stil) + abs(enjr - stjr));
                            ++stjl; --stjr;
                        }
                    }
                    ++stil; --stir;
                }
                sort(all(luu));
                Rep(i, k) ans += luu[i];
            }
            ++enjl; --enjr;
        }

        if (enil != enir) {
            int enjl = 1, enjr = m;
            while (enjl <= enjr) {
                vec(int) luu;
                int stil = 1, stir = n;
                while (stil <= stir) {
                    if (stil != stir) {
                        int stjl = 1, stjr = m;
                        while (stjl <= stjr) {
                            if (have[stil][stjl]) luu.pub(abs(enir - stil) + abs(enjl - stjl));
                            if (have[stir][stjl]) luu.pub(abs(enir - stir) + abs(enjl - stjl));

                            if (stjl != stjr) {
                                if (have[stil][stjr]) luu.pub(abs(enir - stil) + abs(enjl - stjr));
                                if (have[stir][stjr]) luu.pub(abs(enir - stir) + abs(enjl - stjr));
                            }
                            ++stjl; --stjr;
                        }
                    }
                    else {
                        int stjl = 1, stjr = m;
                        while (stjl <= stjr) {
                            if (have[stil][stjl]) luu.pub(abs(enir - stil) + abs(enjl - stjl));
                            if (stjl != stjr)
                                if (have[stil][stjr]) luu.pub(abs(enir - stil) + abs(enjl - stjr));
                            ++stjl; --stjr;
                        }
                    }
                    ++stil; --stir;
                }
                sort(all(luu));
                Rep(i, k) ans += luu[i];

                if (enjl != enjr) {
                    vec(int) luu;
                    int stil = 1, stir = n;
                    while (stil <= stir) {
                        if (stil != stir) {
                            int stjl = 1, stjr = m;
                            while (stjl <= stjr) {
                                if (have[stil][stjl]) luu.pub(abs(enir - stil) + abs(enjr - stjl));
                                if (have[stir][stjl]) luu.pub(abs(enir - stir) + abs(enjr - stjl));

                                if (stjl != stjr) {
                                    if (have[stil][stjr]) luu.pub(abs(enir - stil) + abs(enjr - stjr));
                                    if (have[stir][stjr]) luu.pub(abs(enir - stir) + abs(enjr - stjr));
                                }
                                ++stjl; --stjr;
                            }
                        }
                        else {
                            int stjl = 1, stjr = m;
                            while (stjl <= stjr) {
                                if (have[stil][stjl]) luu.pub(abs(enir - stil) + abs(enjr - stjl));
                                if (stjl != stjr)
                                    if (have[stil][stjr]) luu.pub(abs(enir - stil) + abs(enjr - stjr));
                                ++stjl; --stjr;
                            }
                        }
                        ++stil; --stir;
                    }
                    sort(all(luu));
                    Rep(i, k) ans += luu[i];
                }
                ++enjl; --enjr;
            }
        }
        ++enil; --enir;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("FORMATION.inp", "r", stdin);
    freopen("FORMATION.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> k;
    For(i, 1, n, 1) For(j, 1, m, 1) {
        int type; cin >> type;
        have[i][j] = ((type == 1) ? true : false);
    }

    if (n <= 50 && m <= 50)
        sub1();
    else
        sub2();

    return 0;
}
