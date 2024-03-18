#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define fr front
#define bk back
#define NAME ""
#define NOT 18446744073709551615
#define ii pair <int,int>
#define vii vector <pair <int,int>>
#define iii pair <pair <int,int>,int>
#define viii vector <pair <pair <int,int>,int>>

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;

string s;
stack <char> st;

int init(char ch) {
    if (ch == '*' || ch == '/')
        return 4;
    if (ch == '+' || ch == '-')
        return 3;
    return 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

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

    return 0;
}