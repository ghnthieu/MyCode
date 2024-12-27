#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pub push_back
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)

typedef long long ll;
const int N = (int) 1e6 + 7;

int n;
ll mon;

struct Data {
    int gift, kn;
} a[N];

bool done[N];
vec(int) luu;

void solve(void) {
    ll cook = mon;
    done[0] = true;
    For(i, 1, n, 1) if (a[i].gift >= 0 && done[a[i].kn]) {
        mon += a[i].gift;
        done[i] = true;
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, n, 1) if (!done[a[i].kn]) {
        luu.clear(); luu.pub(i);
        ll sum = a[i].gift, j = a[i].kn;
        while (!done[j]) {
            luu.pub(j);
            sum += a[j].gift;
            j = a[j].kn;
        }
        if (sum > 0) {
            bool check = true;
            reverse(all(luu));
            ll tmp = mon;
            for (int x : luu) {
                tmp += a[x].gift;
                if (tmp < 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int x : luu) done[x] = true;
                mon += sum;
            }
        }
    }

    For(i, 1, 500, 1) {
        For(i, 1, n, 1) if (!done[a[i].kn]) {
            luu.clear(); luu.pub(i);
            ll sum = a[i].gift, j = a[i].kn;
            while (!done[j]) {
                luu.pub(j);
                sum += a[j].gift;
                j = a[j].kn;
            }
            if (sum > 0) {
                bool check = true;
                reverse(all(luu));
                ll tmp = mon;
                for (int x : luu) {
                    tmp += a[x].gift;
                    if (tmp < 0) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    for (int x : luu) done[x] = true;
                    mon += sum;
                }
            }
        }
    }

    cout << mon - cook;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> mon;
    For(i, 1, n, 1) cin >> a[i].gift >> a[i].kn;

    solve();

    return 0;
}
