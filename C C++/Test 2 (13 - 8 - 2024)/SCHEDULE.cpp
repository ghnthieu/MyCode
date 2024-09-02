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
const ll oo = (ll) 1e18 + 7ll;
const int N = (int) 1e5 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

struct Data {
    ll sl_work;
    int st_day, en_day;
};

int n, m, st_day[N], en_day[N];
Data work[N];
ll sl_work[N];

void sub1(void) {
    map <int, ll> pre;
    For(i, 1, n, 1) pre[work[i].st_day] += work[i].sl_work;
    ll ans = LLONG_MIN;
    for (auto x : pre) maximize(ans, x.se);
    cout << ans;
}

bool cmp(Data x, Data y) {
    if (x.en_day == y.en_day)
        return (x.st_day < y.st_day);
    return (x.en_day < y.en_day);
}

bool check(int x, vec(Data) tt) {
    int j = 1;
    For(i, 1, m, 1) {
        int tmp = x;
        if (i > tt[j].en_day && tt[j].sl_work != 0) return false;
        if (i < tt[j].st_day) continue;
        while (tmp >= tt[j].sl_work && tt[j].st_day <= i && i <= tt[j].en_day) {
            tmp -= tt[j].sl_work; tt[j].sl_work = 0;
            ++j; if (j > n) return true;
        }
        if (tmp > 0 && tt[j].st_day <= i && i <= tt[j].en_day) tt[j].sl_work -= tmp;
    }
    For(i, 1, n, 1) if (tt[i].sl_work > 0)
        return false;
    return true;
}

void sub2(void) {
    sort(work + 1, work + n + 1, cmp);
    vec(Data) tmp;
    tmp.pub({0, 0, 0});
    For(i, 1, n, 1) tmp.pub(work[i]);
    int l = 1, r = 25e4, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid, tmp)) {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
}

bool cmpp(Data x, Data y) {
    return (x.st_day < y.st_day);
}

bool chek(ll x) {
    priority_queue <ii(int, ll), vii(int, ll), greater <ii(int, ll)>> pq;
    //int i = 1;
    //while (i <= n) {
    For(i, 1, n, 1) {
        pq.push({en_day[i], sl_work[i]});
        while (i < n && st_day[i] == st_day[i + 1])
            pq.push({en_day[++i], sl_work[i]});
        ll st = st_day[i], en = st_day[i + 1] - 1;
        while (!pq.empty() && st <= en) {
            ii(int, ll) top = pq.top(); pq.pop();
            ll workk = (top.se - 1) / x + 1;
            if (st + workk - 1 > top.fi) return false;
            if (st + workk - 1 > en) {
                pq.push({top.fi, top.se - (en - st + 1) * x});
                break;
            }

            ll crr = 1ll * workk * x - top.se; st += workk;
            while (crr > 0 && !pq.empty()) {
                ii(int, ll) topp = pq.top(); pq.pop();
                if (top.se > crr) {
                    pq.push({topp.fi, topp.se - crr});
                    crr = 0;
                }
                else
                    crr -= topp.se;
            }
        }
        if (!pq.empty() && pq.top().fi <= en) return false;
        //++i;
    }
    return true;
}

ll tr = 0;
void sub3(void) {
    ll l = 1, r = tr, ans = oo;
    while (l <= r) {
        ll m = l + r >> 1;
        if (chek(m)) {
            minimize(ans, m);
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("SCHEDULE.inp", "r", stdin);
    freopen("SCHEDULE.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m;
    bool dk_sub1 = true;
    For(i, 1, n, 1) {
        cin >> work[i].sl_work >> work[i].st_day >> work[i].en_day;
        if (work[i].st_day != work[i].en_day) dk_sub1 = false;
        tr += work[i].sl_work;
    }

    sort(work + 1, work + n + 1, cmpp);
    For(i, 1, n, 1) { sl_work[i] = work[i].sl_work; st_day[i] = work[i].st_day; en_day[i] = work[i].en_day; }
    st_day[n + 1] = m + 1;

    if (dk_sub1)
        sub1();
    else if (n <= 500 && m <= 1e6)
        sub2();
    else
        sub3();

    return 0;
}
