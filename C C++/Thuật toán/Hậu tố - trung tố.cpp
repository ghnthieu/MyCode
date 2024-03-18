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
stack <string> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

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

    return 0;
}