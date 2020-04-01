//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <stack>
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
const int oo = 1e9+7;
typedef long long ll;
//typedef pair<int, int> ii;
struct TNode {
    TNode *child[N_CHAR], *par;
    int End, cnt, distToEnd;
} *T;

int n, res;
string s;
stack<int> Stack;

void init(TNode *&p)  {
    p = new TNode;
    REP(i, N_CHAR) p -> child[i] = NULL;
    p -> End = p-> cnt = 0;
    p -> distToEnd = oo;
}
int Find(string &s) {
    TNode *p = T;
    FORD(i, s.size() - 1, 0) {
        int tmp = s[i] - 'a';
        if (p-> child[tmp] == NULL) return false;
        p = p-> child[tmp];
    }
    return p-> End;
}
void add(string &s)  {
    if (Find(s)) return;
    TNode *p = T;
    FORD(i, s.size()-1, 0) {
        int tmp = s[i] - 'a';
        if (p -> child[tmp] == NULL) init(p -> child[tmp]);
        p = p -> child[tmp];
        p -> cnt ++;
    }
    p -> End = 1;
    p -> distToEnd = 0;
}
void traverse(TNode *p) {
    REP(i, N_CHAR) if (p -> child[i] != NULL) {
        traverse(p-> child[i]);
        p-> distToEnd =
            min(p-> distToEnd, (p-> child[i])-> distToEnd + 1);
    }
}
void printNear(TNode *p) {
    REP(i, N_CHAR)
        if (p-> child[i] != NULL &&
        (p-> child[i])-> distToEnd + 1 == p-> distToEnd) {
            printNear(p-> child[i]);
            printf("%c", i+'a');
        }
}
void solve(string &s) {
    TNode *p = T;
    FORD(i, s.size()-1, 0) {
        int tmp = s[i] - 'a';
        if (p-> child[tmp] != NULL && (p-> child[tmp])-> cnt > 1) {
            Stack.push(tmp + 'a');
            p = p -> child[tmp];
        }
    }
    printNear(p);
    while (!Stack.empty())
        printf("%c", Stack.top()), Stack.pop();
    printf("\n");
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    init(T);
    while (getline(cin, s)) {
        if (s == "") break;
        else add(s);
    }
    traverse(T);
    while (getline(cin, s))
        solve(s);
}
/// Expelliarmus !
