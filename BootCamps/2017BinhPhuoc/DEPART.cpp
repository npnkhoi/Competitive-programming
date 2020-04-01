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
const int NCHAR = 26;
const int N = 1e5 + 5;
const int md = 1e9 + 7;

struct node {
    int tail;
    node* des[NCHAR];
} *T;

int dp[N];

void Add(node *&p) {
    p = new node;
    p -> tail = 0;
    REP(i, NCHAR) p -> des[i] = NULL;
}
void Insert(string &str) {
    //cerr << "insert " << str << "\n";
    node *p = T;
    REP(i, str.size()) {
        int cur = str[i] - 'a';
        if (p -> des[cur] == NULL) {
            Add(p -> des[cur]);
            //cerr << "new Node " << (char) (cur + 'a') << ".\n";
        }
        p = p -> des[cur];
    }
    p -> tail = 1;
}
bool Find(string &str) {
    node *p = T;
    REP(i, str.size()) {
        int tmp = str[i] - 'a';
        if (!p -> des[tmp]) return false;
        else p = p -> des[tmp];
    }
    return p -> tail;
}
void duyet(node *p, char ch) {
    if (p == NULL) return;
    printf("%c %d\n", ch, p -> tail);
    REP(i, NCHAR) if (p -> des[i] != NULL) {
        duyet(p -> des[i], i + 'a');
    }
}

int main() {
    freopen("DEPART.inp", "r", stdin);
    freopen("DEPART.out", "w", stdout);
    int n;
    string str;
    scanf("%d ", &n);

    Add(T);
    REP(i, n) {
        getline(cin, str);
        reverse(str.begin(), str.end());
        Insert(str);
    }
    //duyet(T, 0);
    getline(cin, str);
    n = str.size();

    //cerr << "--\n";
    string str0 = "";
    REP(i, n) {
        dp[i] = 0;
        node *p = T;
        FORD(j, i, max(0, i - 100)) {
            int tmp = str[j] - 'a';
            if (p -> des[tmp] != NULL) {
                p = p -> des[tmp];
                if (p -> tail) {
                    if (j == 0) dp[i] = (dp[i] + 1) % md;
                    else dp[i] = (dp[i] + dp[j-1]) % md;
                }
            } else break;
        }
    }
    printf("%d\n", dp[n-1]);
    return 0;
}
/** Happy Coding :D */
