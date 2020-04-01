#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,b,a) for (int i = b; i >= a; i--)
#define task "number"

const int MAX_CHAR = 10;
struct node {
    node *nex[MAX_CHAR], *par;
    int inf, End;
} *T;

int n;
string s, save;

void init(node *&p) {
    p = new node;
    REP(i, MAX_CHAR) p -> nex[i] = NULL;
    p -> End = 0;
}
void add(string &s) {
    node *p = T;
    REP(i, s.size()) {
        int tmp = s[i] - '0';
        if (p -> nex[tmp] == NULL) {
            init(p -> nex[tmp]);
            p -> nex[tmp] -> par = p;
        }
        p = p -> nex[tmp];
        p -> inf = tmp;
    }
    p -> End ++;
}
void del(node *&p) {
    if (p -> End > 1) p -> End --;
    else {
        do {
            int tmp = p -> inf;
            p = p -> par;
            p -> nex[tmp] = NULL;
        } while (p != T && p -> End == 0);
    }
}

bool emptyNode(node *p) {
    REP(i, MAX_CHAR) if (p -> nex[i] != NULL) return 0;
    return 1;
}
bool Less(node *a, node *b) {
    while (1) {
        if (emptyNode(a) || emptyNode(b)) return 1;
        REP(i, MAX_CHAR) {
            bool x = a -> nex[i] != NULL;
            bool y = b -> nex[i] != NULL;
            if (x || y)
            if (x ^ y) return x;
            else {
                a = a -> nex[i];
                b = b -> nex[i];
                continue;
            }
            return 0;
        }
    }
}
void duyet(node *p) {
    REP(i, MAX_CHAR) if (p -> nex[i] != NULL) {
        printf("%c\n", '0' + i);
        duyet(p -> nex[i]);
    }
}
void solMin() {
    REP(love, n) {
        node *p = T;
        while (1) {
            if (p -> End && p != T && Less(T, p)) {
                del(p);
                break;
            }
            FOR(i, love == 0, MAX_CHAR - 1) if (p -> nex[i] != NULL) {
                printf("%c", '0' + i);
                p = p -> nex[i];
                break;
            }
        }
    }
}
void solMax() {
    printf("%s", save.c_str());
    REP(love, n-1) {
        node *p = T;
        while (1) {
            if (p -> End && p != T && Less(p, T)) {
                del(p);
                break;
            }
            FORD(i, MAX_CHAR - 1, (love == 0)) {
                if (p -> nex[i] != NULL) {
                    printf("%c", '0' + i);
                    p = p -> nex[i];
                    break;
                }
            }
        }
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    init(T);
    scanf("%d ", &n);
    if (n == 1) {
        getline(cin, s);
        printf("%s", s.c_str());
        exit(0);
    }
    bool neg = 0;
    bool nonzero = 0;
    FOR(i, 1, n) {
        getline(cin, s);
        if (s[0] == '-') {
            if (neg) {
                printf("NO\n");
                exit(0);
            } else {
                neg = 1;
                save = s;
                continue;
            }
        } else if (s[0] != '0') nonzero = 1;
        add(s);
    }
    node *xx;
    if (!nonzero) {
        printf("NO\n");
        exit(0);
    }
    /// nho truong hop 1 so 0
    if (neg) solMax();
    else solMin();

    return 0;
}
