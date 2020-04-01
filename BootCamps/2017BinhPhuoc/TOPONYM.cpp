using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define fname "TOPONYM"
const int NCHAR = 54;
struct node {
    int cnt;
    node* des[NCHAR];
} *T;

int res;

int id(char ch) {
    if (ch == ' ') return 0;
    else if (ch <= 'Z') return ch - 'A' + 1;
    else return ch - 'a' + 27;
}
void Add(node *&p) {
    p = new node;
    p -> cnt = 0;
    REP(i, NCHAR) p -> des[i] = NULL;
}
void Insert(string &str) {
    //cerr << "insert " << str << "\n";
    node *p = T;
    REP(i, str.size()) {
        int cur = id(str[i]);
        if (p -> des[cur] == NULL) {
            Add(p -> des[cur]);
            //cerr << "new Node " << str[i] << ".\n";
        }
        p = p -> des[cur];
        p -> cnt ++;
        res = max(res, (i+1)*(p->cnt));
    }
}
void duyet(node *p, int dep) {
    if (p -> cnt == 1) return;
    res = max(res, dep * (p -> cnt));
    REP(i, NCHAR) if (p -> des[i] != NULL) {
        duyet(p -> des[i], dep + 1);
    }
}
int main() {
    freopen(fname".inp", "r", stdin);
    freopen(fname".out", "w", stdout);
    int n;
    string str;
    scanf("%d ", &n);
    Add(T);
    REP(i, n) {
        getline(cin, str);
        //res = max(res, (int)str.size());
        //cerr << str << "\n";
        Insert(str);
        //cerr << i << "\n";
    }
    //duyet(T, 0);
    printf("%d", res);

    return 0;
}
/** Happy Coding :D */
