#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 3e4 + 5;
int n, m, s, t, maxC;
bool mark[N];
vector<ii> adj[N];
void dfs(int u, int c) {
    mark[u] = 1;
    REP(i, adj[u].size()) {
        ii v = adj[u][i];
        if (!mark[v.fi] && v.se % c == 0) dfs(v.fi, c);
    }
}
void sub1() {
    //cerr << "sub 1\n";
    FORD(i, maxC, 1) {
        memset(mark, 0, sizeof mark);
        dfs(s, i);
        if (mark[t]) {
            printf("%d", i);
            exit(0);
        }
    }
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &s, &t);
    FOR(i, 1, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        maxC = max(maxC, c);
        adj[u].push_back(mp(v, c));
        //adj[v].push_back(mp(u, c));
    }
    sub1();
}
