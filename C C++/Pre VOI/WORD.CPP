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
const int N = (int) 1e3 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, k, m, dau[N];
bool dau_end[N][N], viet_sau[N][N], tu_dep[N], tu_xau[N], bat_dau[N];
map <vec(int), bool> check;
ll ans = 0;

//Diem cua cau van co w tu = k + (k - 1) + (k - 2) + ... + (k - w + 1)
//2 cau van hop nhau phai la cau hoan hao
//Ans = Tong diem cac cau van * so cau van hop nhau

void sub1(vec(int) luu, int cnt_t1) {
    if (!luu.empty() && luu.size() - cnt_t1 <= m) {
        if (luu.bk() == -1) {
            check[luu] = true;

            int i = 0;
            vec(vec(int)) bai_van; vec(int) cau;
            while (i < luu.size()) {
                vec(int) cau;
                while (i < luu.size() && luu[i] != -1) {
                    cau.pub(luu[i]);
                    ++i;
                }
                if (i < luu.size()) {
                    cau.pub(luu[i]);
                    bai_van.pub(cau);
                    ++i;
                }
            }

            /*Rep(i, bai_van.size()) {
                for (int x : bai_van[i]) cout << x << " ";
                cout << '\n';
            }
            cout << '\n';*/

            Rep(i, bai_van.size()) if (bai_van[i][0] == -1)
                return;
            Rep(i, bai_van.size()) if (bat_dau[bai_van[i][0]] == false)
                return;
            bool conti = true;
            Rep(i, bai_van.size()) if (tu_xau[bai_van[i][bai_van[i].size() - 2]] && i != bai_van.size() - 1) {
                conti = false;
                break;
            }

            if (conti) {
                map <int, bool> hh;
                Rep(i, bai_van.size()) if (tu_dep[bai_van[i][bai_van[i].size() - 2]])
                    hh[i] = true;

                ll hop_nhau = 0;
                Rep(i, bai_van.size() - 1) if (hh[i] && hh[i + 1] && viet_sau[bai_van[i][bai_van[i].size() - 2]][bai_van[i + 1][bai_van[i].size() - 2]])
                    ++hop_nhau;

                ll res = 0;
                Rep(i, bai_van.size()) For(j, 1, bai_van[i].size() - 1, 1)
                    res += (k - j + 1);
                maximize(ans, res * hop_nhau);
            }
        }
    }
    else if (luu.size() - cnt_t1 > m)
        return;

    For(i, 1, n, 1) {
        luu.pub(i);
        if (!check[luu]) sub1(luu, cnt_t1);
        luu.pb();
        luu.pub(-1);
        if (!check[luu]) sub1(luu, cnt_t1 + 1);
        luu.pb();
    }
}

void sub2(void) {}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("WORD.INP", "r", stdin);
    freopen("WORD.OUT", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> k >> m;
    For(i, 1, n, 1) cin >> dau[i];
    For(i, 1, 6, 1) For(j, 1, 6, 1) {
        int x; cin >> x;
        if (x == 1) dau_end[i][j] = true; //Dau o cuoi cau i hop voi cau j voi i den j
        else if (x == 0) dau_end[i][j] = false; //Dau o cuoi cau i khong hop voi cau j voi i den j
    }
    For(i, 1, n + 1, 1) For(j, 1, n + 1, 1) {
        int x; cin >> x;
        if (j == n + 1) {
            if (x == 1) tu_dep[i] = true; //Tu dep
            else if (x == 0) tu_xau[i] = true; //Tu xau
            continue;
        }
        if (i == n + 1) {
            if (x == 1) bat_dau[j] = true; //Co the lam tu bat dau
            else if (x == 0) bat_dau[j] = false; //Khong the lam tu bat dau
	    continue;
        }
        if (x == 1) viet_sau[i][j] = true; //Tu thu i co the dung truoc tu thu j
        else if (x == 0) viet_sau[i][j] = false; //Tu thu i khong the dung truoc tu thu j
    }

    if (n <= 7 && m <= 7) {
        vec(int) tmp;
        sub1(tmp, 0);
        cout << ans;
    }
    else
        sub2();

    return 0;
}

/*7 4 6
2 4 1 5 6 3 3
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1
0 0 0 0 0 0
0 0 0 0 0 1
0 0 1 0 0 0
0 0 1 0 0 0 1 0
0 0 1 0 1 0 0 0
0 0 0 1 0 0 0 0
0 0 1 0 0 1 0 1
0 0 0 0 0 0 0 1
0 0 0 0 0 1 0 1
0 0 0 0 0 0 0 0
1 1 0 0 0 0 1 0*/
