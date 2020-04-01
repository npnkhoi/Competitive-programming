#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <cctype>
#include <ctime>
#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>
#include <functional>
#include <complex>
#include <string>
#include <iterator>
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
typedef long long ll;
typedef pair<int, int> ii;
const int NCHAR = 26;
const int md = 1337377;
const int N = 3e5 + 5;
struct TNode {
    TNode *nex[NCHAR], *par;
    bool End;
} *T;
void init(TNode *&p) {
    p = new(TNode);
    REP(i, 26) p -> nex[i] = NULL;
    p -> par = NULL;
    p -> End = 0;
}
void add(string &s) {
    TNode *p = T;
    REP(i, s.size()) {
        int tmp = s[i] - 'a';
        if ((p -> nex[tmp]) == NULL) init(p -> nex[tmp]);
        p = (p -> nex[tmp]);
    }
    p -> End = 1;
}
string s, x;
int n, dp[N];
int main() {
    init(T);
    getline(cin, s); int L = s.size();
    scanf("%d ", &n);
    for (int i = 1; i <= n; i++) {
        getline(cin, x);
        //cerr << x << "\n";
        add(x);
        //cerr << "ok\n";

    }
    dp[L] = 1;
    FORD(i, L-1, 0) {
        dp[i] = 0;
        TNode *p = T;
        FOR(j, i, L-1) {
            int tmp = s[j] - 'a';
            if ((p -> nex[tmp]) == NULL) break;
            else p = (p -> nex[tmp]);
            if (p -> End) dp[i] = (dp[i] + dp[j+1]) % md;
        }
    }
    printf("%d", dp[0]);
}
