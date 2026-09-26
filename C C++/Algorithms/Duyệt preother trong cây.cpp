#include <bits/stdc++.h>
using namespace std;

#define NAME ""
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
#define ii pair <int,int>
#define vii vector <pair <int,int>>
#define iii pair <pair <int,int>,int>
#define viii vector <pair <pair <int,int>,int>>

typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;

struct node {
    int value;
    node *left;
    node *right;
    node (int n) {
        value = n;
        left = right = NULL;
    }
};

int n;
node *root = NULL;

void makeroot(node *root, int u, int v, char ch) {
    if (ch == 'L')
        root -> left = new node(v);
    else
        root -> right = new node(v);
}

void insnode(node *root, int u, int v, char ch) {
    if (root == NULL)
        return;
    if (root -> value == u)
        makeroot(root, u, v, ch);
    else {
        insnode(root -> left, u, v, ch);
        insnode(root -> right, u, v, ch);
    }
}

void preother(node *root) {
    if (root == NULL)
        return;
    cout << root -> value << " ";
    preother(root -> left);
    preother(root -> right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);

    cin >> n;
    while (n--) {
        int x, y; cin >> x >> y;
        char ch; cin >> ch;
        if (root == NULL) {
            root = new node(x);
            makeroot(root, x, y, ch);
        }
        else
            insnode(root, x, y, ch);
    }
    preother(root);

    return 0;
}