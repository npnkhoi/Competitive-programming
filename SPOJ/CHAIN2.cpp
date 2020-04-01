//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
const int N_CHAR = 26;
typedef long long ll;
//typedef pair<int, int> ii;
struct TNode {
    TNode *child[N_CHAR], *par;
    int End;
} *T;
void init(TNode *&p)  {
    p = new TNode;
    REP(i, N_CHAR) p -> child[i] = NULL;
    p -> End = 0;
}
void add(string &s)  {
    TNode *p = T;
    REP(i, s.size()) {
        int tmp = s[i] - 'a';
        if (p -> child[tmp] == NULL) init(p -> child[tmp]);
        p = p -> child[tmp];
    }
    p -> End = 1;
}

int n, res;
string s;

void traverse(TNode *p, int cnt) {
    res = max(res, cnt);
    REP(i, N_CHAR) if (p -> child[i] != NULL)
        traverse(p -> child[i], cnt + ((p -> child[i]) -> End));
}

int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    init(T);
    scanf("%d ", &n);
    FOR(i, 1, n) {
        getline(cin, s);
        add(s);
    }
    traverse(T, 0);
    printf("%d", res);
}
/// Expelliarmus !
