#include <ctime>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <complex>
#include <iterator>
#include <bitset>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,n) for (int i = 0; i < n; i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define task "fmatch"
typedef long long ll;
typedef pair<int, int> ii;

const int N = 5e4 + 5;
int nl, nr, m, last, res;
queue<int> q;
int matchl[N], matchr[N], trace[N];
vector<int> adj[N];

bool findAugment() {
    while (!q.empty()) q.pop();
    memset(trace, 0, sizeof trace);
    FOR(i, 1, nl) if (matchl[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        REP(j, adj[u].size()) {
            int v = adj[u][j];
            if (trace[v] == 0) {
                trace[v] = u;
                if (matchr[v] == 0) {
                    last = v;
                    return 1;
                } else q.push(matchr[v]);
            }
        }
    }
    return 0;
}
void enlarge() {
    res ++;
    int u = last, v;
    while (1) {
        v = matchl[trace[u]];
        matchr[u] = trace[u];
        matchl[trace[u]] = u;
        if (v == 0) break;
        else u = v;
    }
}


int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d%d", &nl, &nr, &m);
    REP(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
    }
    FOR(i, 1, nl) REP(j, adj[i].size()) {
        int v = adj[i][j];
        if (matchr[v] == 0) {
            matchl[i] = v;
            matchr[v] = i;
            res ++;
            break;
        }
    }
    while (findAugment()) enlarge();
    printf("%d", res);
    //FOR(i, 1, nl) if (matchl[i]) cerr << i << " " << matchl[i] << "\n";
}
