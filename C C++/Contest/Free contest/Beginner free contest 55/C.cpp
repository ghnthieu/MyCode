#include <bits/stdc++.h>
using namespace std;

#define NAME "PALINARRAY"
#define fi first
#define se second
#define fr front
#define bk back
#define pf pop_front
#define pb pop_back
#define puf push_front
#define pub push_back
#define NOT 18446744073709551615
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <kdl1,kdl2>,kdl3>>

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;

struct Data {
    int value, index;
};

int test, n;
Data a[N];

bool cmp(Data a, Data b) {
    if (a.value == b.value)
        return (a.index < b.index);
    return (a.value < b.value);
}

int tknp1(Data a[], int l, int r, int x) {
    int ans = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m].value == x) {
            ans = a[m].index;
            r = m - 1;
        }
        else if (a[m].value < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return ans;
}

int tknp2(Data a[], int l, int r, int x) {
    int ans = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m].value == x) {
            ans = a[m].index;
            l = m + 1;
        }
        else if (a[m].value < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);

    cin >> test;
    while (test--) {
        cin >> n;
        map <int,int> mp;
        for (int i=1; i<=n; ++i) {
            cin >> a[i].value;
            a[i].index = i;
            ++mp[a[i].value];
        }
        bool ok = false;
        for (auto it : mp) {
            if (it.se >= 2) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "NO" << '\n';
            continue;
        }
        sort(a+1, a+n+1, cmp);
        vector <int> v;
        v.clear();
        for (auto it : mp) {
            if (it.se >= 2)
                v.pub(it.fi);
        }
        ok = false;
        for (int x : v) {
            int tmp1 = tknp1(a, 1, n, x);
            int tmp2 = tknp2(a, 1, n, x);
            //cout << tmp1 << " " << tmp2 << '\n';
            if (abs(tmp2 - tmp1) > 1) {
                cout << "YES" << '\n';
                ok = true;
            }
            if (ok)
                break;
        }
        if (ok)
            continue;
        else
            cout << "NO" << '\n';
    }

    return 0;
}
