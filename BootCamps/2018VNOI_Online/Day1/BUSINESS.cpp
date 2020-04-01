#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; ++i)
#define REP(i,n) for (int i = 0; i < n; ++i)
#define task "business"
typedef long long ll;
typedef pair<int, int> ii;

const int N = 3e5 + 5;
vector<int> adj[N];
queue<int> q;
bool mark[N];
int n, k, save, d;
int pos[N];

int flood(int u) {
    while (!q.empty()) q.pop(); q.push(u);
    mark[u] = 1;
    int res = 0;
    while (!q.empty()) {
        ++ res;
        int siz = q.size();
        while (siz -- ) {
            int u = q.front(); q.pop();
            REP(j, adj[u].size()) {
                int v = adj[u][j];
                if (!mark[v]) {
                    mark[v] = 1;
                    save = v;
                    q.push(v);
                }
            }
        }
    }
    return res;
}
bool ok(int x) {
    while (!q.empty()) q.pop();
    memset(mark, 0, sizeof mark);
    FOR(i, 1, k) q.push(pos[i]), mark[pos[i]] = 1;
    REP(z, x) {
        //cerr << z << "\n";
        int siz = q.size();
        REP(loop, siz) {
            int u = q.front(); q.pop();
            REP(j, adj[u].size()) {
                int v = adj[u][j];
                if (!mark[v]) {
                    mark[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    bool flag = 0;
    FOR(i, 1, n) if (!mark[i])
    if (flag) return false;
    else {
        flag = 1;
        save = i;
        d = flood(i);
        d = max(d,flood(save));
    }
    return ((d+1)/2 <= x);
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d %d", &n, &k);
    FOR(i, 1, k) scanf("%d", &pos[i]);
    REP(z, n-1) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int l = 0, r = n, res = r;
    while (l < r) {
        int mi = (l+r) / 2;
        if (ok(mi)) {
            res = min(res, mi);
            r = mi - 1;
        } else l = mi + 1;
    }
    printf("%d", res);
}
