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
const int N = (int) 1e4 + 7;

/*-----------------------------------------------------------------------------------------------------------------*/

int n, m, k, tam, vtri[N], trace[N];
vii(int, int) inp[N];
ll duong[N];
vec(int) luu;

void dijkstra(int s, int t) {
    memset(duong, 0x3f, (n + 1) * sizeof(ll));
    duong[s] = 0;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se]) continue;
        for (ii(int, int) v : inp[u.se]) if (minimize(duong[v.fi], duong[u.se] + v.se)) {
            pq.push({duong[v.fi], v.fi});
            trace[v.fi] = u.se;
        }
    }
    do {
        luu.pub(t);
        t = trace[t];
    } while (t != s);
    luu.pub(s); reverse(all(luu));
}

void sub1(void) {
    if (vtri[1] == tam) {
        cout << 0 << '\n' << 0 << '\n';
        return;
    }
    dijkstra(vtri[1], tam);
    cout << duong[tam] << '\n';
    cout << luu.size() - 1 << '\n';
    Rep(i, luu.size() - 1) cout << 1 << " " << luu[i] << " " << luu[i + 1] << '\n';
}

map <ii(int, int), int> edge, check_1, check_2;
viii(int, int, int) use_1;
vii(int, int) use_2;

void sub2(void) {
    if (vtri[1] == tam && vtri[2] == tam) {
        cout << 0 << '\n' << 0 << '\n';
        return;
    }
    if (vtri[1] == tam) {
        dijkstra(vtri[2], tam);
        cout << duong[tam] << '\n';
        cout << luu.size() - 1 << '\n';
        Rep(i, luu.size() - 1) cout << "01" << " " << luu[i] << " " << luu[i + 1] << '\n';
    }
    else if (vtri[2] == tam) {
        dijkstra(vtri[1], tam);
        cout << duong[tam] << '\n';
        cout << luu.size() - 1 << '\n';
        Rep(i, luu.size() - 1) cout << "10" << " " << luu[i] << " " << luu[i + 1] << '\n';
    }
    else {
        dijkstra(vtri[1], tam);
        ll chi_phi = duong[tam];
        Rep(i, luu.size() - 1) check_1[{luu[i], luu[i + 1]}] = true;
        luu.clear();
        dijkstra(vtri[2], tam);
        chi_phi += duong[tam];
        Rep(i, luu.size() - 1) check_2[{luu[i], luu[i + 1]}] = true;
        int sl = 0;
        for (auto x : check_1) {
            if (check_2[{x.fi.fi, x.fi.se}]) {
                ++sl;
                chi_phi -= edge[{x.fi.fi, x.fi.se}];
                use_2.pub({x.fi.fi, x.fi.se});
            }
            else {
                ++sl;
                use_1.pub({{x.fi.fi, x.fi.se}, 1});
            }
        }
        for (auto x : check_2) if (!check_1[{x.fi.fi, x.fi.se}]) {
            ++sl;
            use_1.pub({{x.fi.fi, x.fi.se}, 2});
        }
        cout << chi_phi << '\n';
        cout << sl << '\n';
        for (iii(int, int, int) x : use_1) {
            if (x.se == 1)
                cout << "10" << " " << x.fi.fi << " " << x.fi.se << '\n';
            else
                cout << "01" << " " << x.fi.fi << " " << x.fi.se << '\n';
        }
        for (ii(int, int) x : use_2) cout << "11" << " " << x.fi << " " << x.se << '\n';
    }
}

map <ii(int, int), int> cnt;

void dijkstraa(int s, int t) {
    memset(duong, 0x3f, (n + 1) * sizeof(ll));
    duong[s] = 0;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se]) continue;
        for (ii(int, int) v : inp[u.se]) {
            if (minimize(duong[v.fi], duong[u.se] + v.se)) {
                pq.push({duong[v.fi], v.fi});
                trace[v.fi] = u.se;
            }
        }
    }
    vec(int) luu;
    do {
        luu.pub(t);
        t = trace[t];
    } while (t != s);
    luu.pub(s); reverse(all(luu));
    Rep(i, luu.size() - 1) ++cnt[{luu[i], luu[i + 1]}];
}

void sub3(void) {
    if (k == 3) {
        if (vtri[1] == tam && vtri[2] == tam && vtri[3] == tam) {
            cout << 0 << '\n' << 0 << '\n';
            return;
        }
        ll ans = 0;
        if (vtri[1] != tam) {
            dijkstraa(vtri[1], tam);
            ans += duong[tam];
        }
        if (vtri[2] != tam) {
            dijkstraa(vtri[2], tam);
            ans += duong[tam];
        }
        if (vtri[3] != tam) {
            dijkstraa(vtri[3], tam);
            ans += duong[tam];
        }
        for (auto x : cnt) {
            if (x.se == 2)
                ans -= edge[{x.fi.fi, x.fi.se}];
            else if (x.se == 3) {
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
            }
        }
        cout << ans << '\n';
    }
    else if (k == 4) {
        if (vtri[1] == tam && vtri[2] == tam && vtri[3] == tam && vtri[4] == tam) {
            cout << 0 << '\n' << 0 << '\n';
            return;
        }
        ll ans = 0;
        if (vtri[1] != tam) {
            dijkstraa(vtri[1], tam);
            ans += duong[tam];
        }
        if (vtri[2] != tam) {
            dijkstraa(vtri[2], tam);
            ans += duong[tam];
        }
        if (vtri[3] != tam) {
            dijkstraa(vtri[3], tam);
            ans += duong[tam];
        }
        if (vtri[4] != tam) {
            dijkstraa(vtri[4], tam);
            ans += duong[tam];
        }
        for (auto x : cnt) {
            if (x.se == 2)
                ans -= edge[{x.fi.fi, x.fi.se}];
            else if (x.se == 3) {
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
            }
            else if (x.se == 4) {
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
            }
        }
        cout << ans << '\n';
    }
    else if (k == 5) {
        if (vtri[1] == tam && vtri[2] == tam && vtri[3] == tam && vtri[4] == tam && vtri[5] == tam) {
            cout << 0 << '\n' << 0 << '\n';
            return;
        }
        ll ans = 0;
        if (vtri[1] != tam) {
            dijkstraa(vtri[1], tam);
            ans += duong[tam];
        }
        if (vtri[2] != tam) {
            dijkstraa(vtri[2], tam);
            ans += duong[tam];
        }
        if (vtri[3] != tam) {
            dijkstraa(vtri[3], tam);
            ans += duong[tam];
        }
        if (vtri[4] != tam) {
            dijkstraa(vtri[4], tam);
            ans += duong[tam];
        }
        if (vtri[5] != tam) {
            dijkstraa(vtri[5], tam);
            ans += duong[tam];
        }
        for (auto x : cnt) {
            if (x.se == 2)
                ans -= edge[{x.fi.fi, x.fi.se}];
            else if (x.se == 3) {
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
            }
            else if (x.se == 4) {
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
            }
            else if (x.se == 5) {
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
            }
        }
        cout << ans << '\n';
    }
    else {
        if (vtri[1] == tam && vtri[2] == tam && vtri[3] == tam && vtri[4] == tam && vtri[5] == tam && vtri[6] == tam) {
            cout << 0 << '\n' << 0 << '\n';
            return;
        }
        ll ans = 0;
        if (vtri[1] != tam) {
            dijkstraa(vtri[1], tam);
            ans += duong[tam];
        }
        if (vtri[2] != tam) {
            dijkstraa(vtri[2], tam);
            ans += duong[tam];
        }
        if (vtri[3] != tam) {
            dijkstraa(vtri[3], tam);
            ans += duong[tam];
        }
        if (vtri[4] != tam) {
            dijkstraa(vtri[4], tam);
            ans += duong[tam];
        }
        if (vtri[5] != tam) {
            dijkstraa(vtri[5], tam);
            ans += duong[tam];
        }
        if (vtri[6] != tam) {
            dijkstraa(vtri[6], tam);
            ans += duong[tam];
        }
        for (auto x : cnt) {
            if (x.se == 2)
                ans -= edge[{x.fi.fi, x.fi.se}];
            else if (x.se == 3) {
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
            }
            else if (x.se == 4) {
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
            }
            else if (x.se == 5) {
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
            }
            else if (x.se == 6) {
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
                ans -= edge[{x.fi.fi, x.fi.se}];
            }
        }
        cout << ans << '\n';
    }
}

void sub4(void) {
    bool check = true;
    For(i, 1, k, 1) if (vtri[i] != tam) {
        check = false;
        break;
    }
    if (check) {
        cout << 0 << '\n' << 0 << '\n';
        return;
    }
    ll ans = 0;
    For(i, 1, k, 1) if (vtri[i] != tam) {
        dijkstraa(vtri[i], tam);
        ans += duong[tam];
    }
    for (auto x : cnt) if (x.se >= 2) ans -= 1ll * edge[{x.fi.fi, x.fi.se}] * (x.se - 1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TAXI.inp", "r", stdin);
    freopen("TAXI.out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);

    cin >> n >> m >> k >> tam;
    For(i, 1, k, 1) cin >> vtri[i];
    For(i, 1, m, 1) {
        int x, y, w; cin >> x >> y >> w;
        inp[x].pub({y, w});
        inp[y].pub({x, w});
        if (edge[{x, y}] == 0) {
            edge[{x, y}] = w;
            edge[{y, x}] = w;
        }
        else {
            minimize(edge[{x, y}], w);
            minimize(edge[{y, x}], w);
        }
    }

    if (k == 1)
        sub1();
    else if (k == 2)
        sub2();
    else if (k <= 6)
        sub3();
    else
        sub4();

    return 0;
}
