//Quick Sort
int partion(int a[], int b[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for (int j=l; j<r; ++j) {
        if (a[j] <= pivot) {
            ++i;
            swap(a[i], a[j]);
            swap(b[i], b[j]);
        }
    }
    ++i;
    swap(a[i], a[r]);
    swap(b[i], b[r]);
    return i;
}

void QuickSort(int a[], int b[], int l, int r) {
    if (l >= r)
        return;
    int p = partion(a, b, l, r);
    QuickSort(a, b, l, p - 1);
    QuickSort(a, b, p + 1, r);
}

//Số hoàn hảo
bool checknt(int n) {
    for (int i=2; i<=sqrt(n); ++i) {
        if (n%i == 0)
            return false;
    }
    return (n > 1);
}

bool check(ll n) {
    for (int i=2; i<=32; ++i) {
        if (checknt(i)) {
            int tmp = (int) pow(2,i) - 1;
            if (checknt(tmp)) {
                ll hh = 1ll*tmp*(int) pow(2,i-1);
                if (hh == n)
                    return true;
            }
        }
    }
    return false;
}

//Sàng nguyên tố
for (int i=2; i<=n; ++i)
    nt[i] = true;
for (int i=2; i<=sqrt(n); ++i) {
    if (nt[i]) {
         for (int j=i*i; j<=n; j+=i)
            nt[j] = false 
    }
}

//Phân tích thừa số nguyên tố
for (int i=2; i<=sqrt(n); i++) {
        while (n%i==0) {
            cout << i << " ";
            n /= i;
        }
    }
if (n>1) {
    cout << n;
}

//Tổng ước của n
ll sum = 0;
for (int i=1; i<=sqrt(n); i++) {     
    if (n%i == 0) {
        if (i == n/i) 
            sum += i;
        else 
            sum += i + n/i;
    }
}
cout << sum;

//Luỹ thừa nhị phân
if (b == 0)
    return 1;
ll x = ltbinary(a, b/2);
if (b%2 == 1)
    return x * x * a;
else
    return x * x;

//Đếm ước của N!
int degree(int n, int p) {
    int ans = 0;
    for (int i=p; i<=n; i*=p)
        ans += n/i;
    return ans;
}

int nt(int n) {
    for (int i=2; i<=sqrt(n); ++i) {
        if (n%i == 0)
            return 0;
    }
    return (n > 1);
}

ll count(int n) {
    ll res = 1;
    for (int i=1; i<=n; ++i) {
        if (nt(i))
            res = ((res%r)*((degree(n, i)+1)%r))%r;
    }
    return res;
}

//Nghịch đảo modulo
ll modulo(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2 != 0) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return res;
}
ll revmodulo = modulo(..., MOD-2);

//Mảng cộng dồn ma trận
sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
cout << sum[h2][c2] - sum[h1-1][c2] - sum[h2][c1-1] + sum[h1-1][c1-1] << endl;

//Tổng dãy con liên tiếp lớn nhất
ll sum = 0, ans = -1e18;
for (int i=0; i<n; ++i) {
    cin >> a[i];
    sum += a[i];
    ans = max(ans, sum);
    if (sum < 0) sum = 0;
}

//Dãy con tăng dài nhất
for (int i=0; i<n; ++i) {
        cin >> a[i];
        len[i] = 1;
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<i; j++) {
            if (a[i] > a[j])
                len[i] = max(len[i], len[j] + 1);
        }
    }
    int Max = 0;
    for (int i=0; i<n; ++i)
        Max = max(Max, len[i]);
    cout << Max;

//Bài toán cái túi
 cin >> n >> s;
    vp.push_back({0, 0});
    for (int i=1; i<=n; ++i) {
        int x; cin >> x;
        vp.push_back({x, 0});   //Trong luong do vat thu i
    }
    for (int i=1; i<=n; ++i)
        cin >> vp[i].se;   //Gia tri do vat thu i
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=s; ++j) {
            dp[i][j] = dp[i-1][j];
            if (vp[i].fi <= j)
                dp[i][j] = max(dp[i][j], dp[i-1][j-vp[i].fi] + vp[i].se);
        }
    }
    cout << dp[n][s];

//Dãy con có tổng bằng S
cin >> n >> s;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i=0; i<n; ++i) {
        for (int j=s; j>=a[i]; --j) {
            if (dp[j - a[i]])
                dp[j] = true;
        }
    }
    if (dp[s])
        cout << "YES";
    else
        cout << "NO";

//Xâu con đối xứng dài nhất
cin >> s;
    int len = s.length();
    s = " " + s;
    memset(dx, false, sizeof(dx));
    for (int i=1; i<=len; ++i)
        dx[i][i] = true;
    int ans = 1;
    for (int length = 2; length <= len; ++length) {
        for (int i = 1; i <= len - length + 1; ++i) {
            int j = i + length - 1;
            if (length == 2 && s[i] == s[j])
                dx[i][j] = true;
            else
                dx[i][j] = dx[i+1][j-1] && (s[i] == s[j]);
            if (dx[i][j])
                ans = max(ans, length);
        }
    }
    cout << ans;

//Xâu con chung dài nhất
int len1 = s1.length();
    int len2 = s2.length();
    s1 = " " + s1;
    s2 = " " + s2;
    memset(xc, 0, sizeof(xc));
    for (int i=1; i<=len1; ++i) {
        for (int j=1; j<=len2; ++j) {
            if (s1[i] == s2[j])
                xc[i][j] = xc[i-1][j-1] + 1;
            else
                xc[i][j] = max(xc[i][j-1], xc[i-1][j]);
        }
    }
    cout << xc[len1][len2];

//Frog
 cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> h[i];
    dp[1] = 0;
    dp[2] = dp[1] + abs(h[2] - h[1]);
    for (int i=3; i<=n; ++i)
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    cout << dp[n];

//Frog k
cin >> n >> k;
    for (int i=1; i<=n; ++i)
        cin >> h[i];
    dp[1] = 0;
    for (int i=2; i<=n; ++i) {
        int tmp = INT_MAX;
        for (int j=1; j<=k && i-j>0; ++j)
            tmp = min(tmp, dp[i-j] + abs(h[i] - h[i-j]));
        dp[i] = tmp;
    }
    cout << dp[n];

//Duyệt qua các cặp abs
cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    sort(a, a+n);
    int mn = min(abs(a[0] - a[1]), abs(a[n-1] - a[n-2]));
    for (int i=1; i<n-1; ++i)
        mn = min({mn, abs(a[i] - a[i-1]), abs(a[i] - a[i+1])});
    cout << mn;

//Fibo 1e10
ll n, f[2][2], m[2][2];

void Mul(ll f[2][2], ll m[2][2]) {
    ll x = (f[0][0] * m[0][0] % MOD + f[0][1] * m[1][0] % MOD) % MOD;
    ll y = (f[0][0] * m[0][1] % MOD + f[0][1] * m[1][1] % MOD) % MOD;
    ll z = (f[1][0] * m[0][0] % MOD + f[1][1] * m[1][0] % MOD) % MOD;
    ll t = (f[1][0] * m[0][1] % MOD + f[1][1] * m[1][1] % MOD) % MOD;
    f[0][0] = x;
    f[0][1] = y;
    f[1][0] = z;
    f[1][1] = t;
}

void Pow(ll f[2][2], ll n) {
    if (n <= 1)
        return;
    Pow(f, n/2);
    Mul(f, f);
    if (n&1)
        Mul(f, m);
}

cin >> n;
    f[0][0] = f[0][1] = f[1][0] = 1;
    f[1][1] = 0;
    m[0][0] = m[0][1] = m[1][0] = 1;
    m[1][1] = 0;
    if (n == 0)
        cout << 0;
    else {
        Pow(f, n - 1);
        cout << f[0][0];
    }

//Sum four val
unordered_map <int, pair <int,int>> um;
cin >> n >> x;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j)
            um[a[i] + a[j]] = {i, j};
    }
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            int sum = a[i] + a[j];
            if (um.find(x - sum) != um.end()) {
                pair <int, int> p = um[x - sum];
                if (p.fi != i && p.fi != j && p.se != i && p.se != j) {
                    cout << i + 1 << " " << j + 1 << " " << p.fi + 1 << " " << p.se + 1;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";

//Đường đi
void dfs(int i) {
    vit[i] = true;
    for (int j : inp[i]) {
        if (!vit[j]) {
            prt[j] = i;
            dfs(j);
        }
    }
}
dfs(s);
    if (vit[t]) {
        vector <int> tmp;
        while (t != s) {
            tmp.push_back(t);
            t = prt[t];
        }
        tmp.push_back(s);
        reverse(tmp.begin(), tmp.end());
        for (int i=0; i<tmp.size(); ++i)
            cout << tmp[i] << " ";
    }
    else
        cout << -1;

//Check chu trình liên thông
bool dfs(int i, int par) {
    vit[i] = true;
    for (int x : inp[i]) {
        if (!vit[x]) {
            if (dfs(x, i))
                return true;
        }
        else if (x != par)
            return true;
    }
    return false;
}
if (dfs(1, 0))
        cout << 1;
    else
        cout << 0;

//Check chu trình !liên thông
bool dfs(int i, int par) {
    vit[i] = true;
    for (int x : inp[i]) {
        if (!vit[x]) {
            if (dfs(x, i))
                return true;
        }
        else if (x != par)
            return true;
    }
    return false;
}
for (int i=1; i<=n; ++i) {
        if (!vit[i]) {
            if (dfs(i, 0)) {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;

//Đếm thành phần liên thông mạnh
void dfs1(int u) {
    vit[u] = true;
    for (int v : inp[u]) {
        if (!vit[v])
            dfs1(v);
    }
    st.push(u);
}

void dfs2(int u) {
    vit[u] = true;
    //cout << u << " ";
    for (int v : rinp[u]) {
        if (!vit[v])
            dfs2(v);
    }
}
void scc() {
    memset(vit, false, sizeof(vit));
    for (int i=1; i<=n; ++i) {
        if (!vit[i])
            dfs1(i);
    }
    memset(vit, false, sizeof(vit));
    int cnt = 0;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!vit[u]) {
            dfs2(u);
            ++cnt;
        }
    }
    if (cnt == 1)
        cout << 1;
    else
        cout << 0;
}

//Tìm min đường đi trong ma trận
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void bfs(int i, int j) {
    queue <pair <int,int>> qp;
    qp.push({i, j});
    a[i][j] = 0;
    d[i][j] = 0;
    while (!qp.empty()) {
        pair <int,int> tmp = qp.fr();
        qp.pop();
        for (int k=0; k<8; ++k) {
            int it = tmp.fi + dx[k];
            int jt = tmp.se + dy[k];
            if (it >= 1 && it <= n && jt >= 1 && jt <= n && a[it][jt] != 0) {
                d[it][jt] = d[tmp.fi][tmp.se] + 1;
                if (it == u && jt == v )
                    return;
                qp.push({it, jt});
                a[it][jt] = 0;
            }
        }
    }
}
 bfs(s, t);
    if (d[u][v])
        cout << d[u][v];
    else
        cout << -1;

//Dijkstra
void distra(int s) {
    vector <ll> d(n + 1, 1e9);
    d[s] = 0;
    priority_queue <pair <int,int>, vector <pair <int,int>>, greater <pair <int,int>>> q;
    q.push({0, s});
    while (!q.empty()) {
        pair <int,int> top = q.top();
        q.pop();
        int u = top.se, kc = top.fi;
        if (kc > d[u])
            continue;
        for (auto it : inp[u]) {
            int v = it.fi, w = it.se;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    for (int i=1; i<=n; ++i)
        cout << d[i] << " ";
}

//Truy vấn đường đi dijkstra
void distra(int s, int t) {
    vector <ll> d(n + 1, 1e9);
    d[s] = 0;
    ans[s] = s;
    priority_queue <pair <int,int>, vector <pair <int,int>>, greater <pair <int,int>>> q;
    q.push({0, s});
    while (!q.empty()) {
        pair <int,int> top = q.top();
        q.pop();
        int u = top.se, kc = top.fi;
        if (kc > d[u])
            continue;
        for (auto it : inp[u]) {
            int v = it.fi, w = it.se;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
                ans[v] = u;
            }
        }
    }
    cout << d[t] << '\n';
    vector <int> path;
    while (true) {
        path.push_back(t);
        if (t == s)
            break;
        t = ans[t];
    }
    reverse(path.begin(), path.end());
}

//Tiền tố -> trung tố
 cin >> s;
    for (int i=s.length(); i>=0; --i) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            string fi = st.top(); st.pop();
            string se = st.top(); st.pop();
            string tmp = '(' + fi + s[i] + se + ')';
            st.push(tmp);
        }
        else
            st.push(string(1, s[i]));
    }
    cout << st.top();

//Tiền tố -> hậu tố
 cin >> s;
    for (int i=s.length(); i>=0; --i) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            string fi = st.top(); st.pop();
            string se = st.top(); st.pop();
            string tmp = fi + se + s[i];
            st.push(tmp);
        }
        else
            st.push(string(1, s[i]));
    }
    cout << st.top();

//Trung tố -> hậu tố
int init(char ch) {
    if (ch == '*' || ch == '/')
        return 4;
    if (ch == '+' || ch == '-')
        return 3;
    return 2;
}
  cin >> s;
    string res = "";
    for (int i=0; i<s.length(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
            res += s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
                st.pop();
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            while (!st.empty() && init(st.top()) >= init(s[i])) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        if (st.top() != '(')
            res += st.top();
        st.pop();
    }
    cout << res;

//Hậu tố -> tiền tố
 cin >> s;
    for (int i=0; i<s.length(); ++i) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            string fi = st.top(); st.pop();
            string se = st.top(); st.pop();
            string tmp = s[i] + se + fi;
            st.push(tmp);
        }
        else
            st.push(string(1, s[i]));
    }
    cout << st.top();

//Hậu tố -> trung tố
cin >> s;
    for (int i=0; i<s.length(); ++i) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            string fi = st.top(); st.pop();
            string se = st.top(); st.pop();
            string tmp = '(' + se + s[i] + fi + ')';
            st.push(tmp);
        }
        else
            st.push(string(1, s[i]));
    }
    cout << st.top();

//Segment tree tổng
void build(int v, int l, int r) {
    if (l == r)
        tree[v] = a[l];
    else {
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}
(Xây dựng segment tree cho truy vấn tổng)

ll sum(int v, int treel, int treer, int l, int r) {
    if (l > r)
        return 0;
    if (treel == l && treer == r)
        return tree[v];
    else {
        int treem = (treel + treer) / 2;
        return sum(2 * v, treel, treem, l, min(treem, r)) + sum(2 * v + 1, treem + 1, treer, max(treem + 1, l), r);
    }
}
(Truy vấn tổng từ l -> r)

void update(int v, int l, int r, int pos, int value) {
    if (l == r)
        tree[v] = value;
    else {
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * v, l, mid, pos, value);
        else
            update(2 * v + 1, mid + 1, r, pos, value);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}
(Thay đổi giá trị pos trong mảng thành giá trị value cho truy vấn tổng)

//Segment tree min
void build(int v, int l, int r) {
    if (l == r)
        tree[v] = a[l];
    else {
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
}
(Xây dựng segment tree cho truy vấn min)

int findmin(int v, int treel, int treer, int l, int r) {
    if (l > r)
        return MOD;
    if (treel == l && treer == r)
        return tree[v];
    else {
        int treem = (treel + treer) / 2;
        return min(findmin(2 * v, treel, treem, l, min(treem, r)), findmin(2 * v + 1, treem + 1, treer, max(treem + 1, l), r));
    }
}
(Truy vấn min từ l -> r)

void update(int v, int l, int r, int pos, int value) {
    if (l == r)
        tree[v] = value;
    else {
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * v, l, mid, pos, value);
        else
            update(2 * v + 1, mid + 1, r, pos, value);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
}
(Thay đổi giá trị pos trong mảng thành giá trị value cho truy vấn min)

//Segment tree max
void build(int v, int l, int r) {
    if (l == r)
        tree[v] = a[l];
    else {
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
}
(Xây dựng segment tree cho truy vấn max)

int findmax(int v, int treel, int treer, int l, int r) {
    if (l > r)
        return -1;
    if (treel == l && treer == r)
        return tree[v];
    else {
        int treem = (treel + treer) / 2;
        return max(findmax(2 * v, treel, treem, l, min(treem, r)), findmax(2 * v + 1, treem + 1, treer, max(treem + 1, l), r));
    }
}
(Truy vấn max từ l -> r)

void update(int v, int l, int r, int pos, int value) {
    if (l == r)
        tree[v] = value;
    else {
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * v, l, mid, pos, value);
        else
            update(2 * v + 1, mid + 1, r, pos, value);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
}
(Thay đổi giá trị pos trong mảng thành giá trị value cho truy vấn max)

//Tìm kiếm index segment
void build(int v, int l, int r) {
    if (l == r)
        tree[v] = a[l];
    else {
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
    }
}
(Xây dựng segment tree)

void fix(int v, int l, int r) {
    if (!lazy[v])
        return;
    tree[v] += lazy[v];
    if (l != r) {
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
}
(Lazy update)

void update(int v, int treel, int treer, int l, int r, int value) {
    fix(v, treel, treer);
    if (treel > r || treer < l)
        return;
    if (treel >= l && treer <= r) {
        lazy[v] += value;
        fix(v, treel, treer);
        return;
    }
    int treem = (treel + treer) / 2;
    update(2 * v, treel, treem, l, r, value);
    update(2 * v + 1, treem + 1, treer, l, r, value);
}
(Thay đổi giá trị l -> r + value bằng lazy update)

ll findindex(int v, int treel, int treer, int index) {
    while (treel <= treer) {
        fix(v, treel, treer);
        if (treel == treer)
            break;
        int treem = treel + treer >> 1;
        if (index <= treem) {
            v <<= 1;
            treer = treem;
        }
        else {
            v = v << 1 | 1;
            treel = treem + 1;
        }
    }
    return tree[v];
}
(Tìm kiếm index trong segment tree)

//Lazy update sum
void fix(int v, int l, int r) {
    if (!lazy[v])
        return;
    tree[v] += (r - l + 1) * lazy[v];
    if (l != r) {
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
}

//Lca
void dfs(int u) {
    for (int v : inp[u]) {
        if (v != par[u][0]) {
            par[v][0] = u;
            high[v] = high[u] + 1;
            dfs(v);
        }
    }
}
dfs(1);
for (int j=1; j<=M; ++j) {
    for (int i=1; i<=n; ++i)
        par[i][j] = par[par[i][j - 1]][j - 1];
}
high[0] = -1;
int lca(int u, int v) {
    if (high[v] > high[u])
        return lca(v, u);
    for (int i=M; i>=0; --i) {
        if (high[par[u][i]] >= high[v])
            u = par[u][i];
    }
    if (u == v)
        return u;
    for (int i=M; i>=0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

//Luỹ thừa nhị phân pro
ll ltbinary(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b) {
        if (b & 1)
            res = ((res % MOD) * (a % MOD)) % MOD;
        a = ((a % MOD) * (a % MOD)) % MOD;
        b >>= 1;
    }
    return (res % MOD);
}

//Tính độ dài 2 đỉnh
void dfs(int u) {
    for (ii(int, int) v : inp[u]) {
        if (v.fi != par[u][0]) {
            par[v.fi][0] = u;
            high[v.fi] = high[u] + 1;
            sum[v.fi] = sum[u] + v.se;
            dfs(v.fi);
        }
    }
}

int lca(int u, int v) {
    if (high[v] > high[u])
        return lca(v, u);
    for (int i=M; i>=0; --i) {
        if (high[par[u][i]] >= high[v])
            u = par[u][i];
    }
    if (u == v)
        return u;
    for (int i=M; i>=0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

dfs(1);
for (int j=1; j<=M; ++j) {
    for (int i=1; i<=n; ++i)
        par[i][j] = par[par[i][j - 1]][j - 1];
}
high[0] = -1;
cout << sum[x] + sum[y] - 2 * sum[lca(x, y)] << '\n';

//Tìm được đi dài nhất giữa 2 đỉnh bất kỳ
void dfs1(int u, int prt) {
    dp1[u] = 0;
    for (int v : inp[u]) {
        if (v != prt && !kdb[v]) {
            dfs1(v, u);
            maximize(dp1[u], dp1[v] + 1);
        }
    }
}

void dfs2(int u, int prt) {
    ii(int, int) tmp = {-1, -1};
    for (int v : inp[u]) {
        if (v != prt && !kdb[v]) {
            if (dp1[v] > tmp.fi) {
                tmp.se = tmp.fi;
                tmp.fi = dp1[v];
            }
            else
                maximize(tmp.se, dp1[v]);
        }
    }
    for (int v : inp[u]) {
        if (v != prt && !kdb[v]) {
            dp2[v] = dp2[u] + 1;
            maximize(dp2[v], ((dp1[v] != tmp.fi) ? tmp.fi : tmp.se) + 2);
            dfs2(v, u);
        }
    }
}

int goc = 1;
while (kdb[goc])
    ++goc;
dfs1(goc, -1);
dfs2(goc, -1);
int mxdi = -1;
for (int i=1; i<=n; ++i) {
    if (mxdi < max(dp1[i], dp2[i]))
        maximize(mxdi, max(dp1[i], dp2[i]));
}

//Dijsktra ma trận
void tdijkstra() {
    memset(duong, 0x3f, sizeof(duong));
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j)
            duong[i][j] = a[i][j];
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            int ti1 = 1, ti2 = n;
            while (ti1 <= ti2) {
                if (ti1 == ti2) {
                    if (duong[i][j] > duong[i][ti1] + duong[ti1][j])
                        duong[i][j] = duong[i][ti1] + duong[ti1][j];
                }
                else {
                    if (duong[i][j] > duong[i][ti1] + duong[ti1][j])
                        duong[i][j] = duong[i][ti1] + duong[ti1][j];
                    if (duong[i][j] > duong[i][ti2] + duong[ti2][j])
                        duong[i][j] = duong[i][ti2] + duong[ti2][j];
                }
                ++ti1;
                --ti2;
            }
        }
    }
}

//Xor
xor[l .. r] = xor[1 .. r] ^ xor[1 .. l - 1] = xor từ l đến r
xorpb[l .. r] = xorpb[1 .. r] ^ xorpb[1 .. l - 1] = xor từ l đến r phân biệt
xor[l .. r] ^ xorpb[l .. r] = xor các số xuất hiện chẵn trong đoạn từ l đến r

//Cầu khớp
void dfs(int u, int par) {
    int child = 0;
    num[u] = low[u] = ++cnt;
    for (int v : inp[u]) {
        if (v == par)
            continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v])
                cau.pub({u, v});
            ++child;
            if (u == par) {
                if (child > 1)
                    check[u] = true;
            }
            else if (low[v] >= num[u])
                check[u] = true;
        }
        else
            low[u] = min(low[u], num[v]);
    }
}
memset(check, false, sizeof(check));
for (int i=1; i<=n; ++i) {
    if (!num[i])
        dfs(i, i);
    if (check[i])
        khop.pub(i);
}
for (ii(int, int) x : cau)
    cout << x.fi << " " << x.se << '\n';
cout << '\n';
for (int x : khop)
    cout << x << " ";

//Dp
void add(ll &a, ll b) {
    a += b;
    a -= ((a >= MOD) ? MOD : 0);
    a += ((!a) ? MOD : 0);
}

void solve() {
    dp[0] = 1;
    for (int i=1; i<=n; ++i) {
        int cnt = 0;    
        for (int j=i; j>=1; --j) {
            cnt += ((a[j]) ? 1 : (-1));
            if (abs(cnt) <= k)
                add(dp[i], dp[j - 1]);
        }
    }
    cout << dp[n];
}

//Random
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

long long Rand(long long l , long long h){
    assert(l <= h);
    return l + 1ll * rd() % (h - l + 1) * (rd() % (h - l + 1)) % (h - l + 1);
}