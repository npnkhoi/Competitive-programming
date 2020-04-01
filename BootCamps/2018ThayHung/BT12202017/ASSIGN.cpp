#include <bits/stdc++.h>
using namespace std;
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
#define task "assign"

const int N = 1e5 + 5;
int nx, ny, m, res;
int matchx[N], matchy[N], trace[N];
vector<int> adj[N];
queue<int> q;

int findAugment() {
    //printf("Augment\n");
    while (!q.empty()) q.pop();
    memset(trace, 0, sizeof trace);
    FOR(i, 1, nx) if (matchx[i] == 0)
        q.push(i); /// push all un-matched vtx.es into queue
    while (!q.empty()) {
        int u = q.front(); q.pop();
        REP(j, adj[u].size()) {
            int v = adj[u][j];
            if (trace[v] == 0) {
                trace[v] = u;
                if (matchy[v] == 0) return v;
                else q.push(matchy[v]);
            }
        }
    }
    return 0;
}
void enLarge(int u) {
    //printf("enLarge\n");
    res ++;
    while (1) {
        int v = matchx[trace[u]];
        matchx[trace[u]] = u;
        matchy[u] = trace[u];
        if (v == 0) break;
        else u = v;
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    //ifstream fin(task".inp");
    //ofstream fou(task".out");
    scanf("%d%d", &nx, &ny);
    //fin >> nx >> ny;
    int x, y;
    //while (fin >> x >> y) {
    while (scanf("%d%d", &x, &y) != EOF)
        adj[x].pb(y);
    FOR(u, 1, nx) REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!matchy[v]) {
            matchx[u] = v;
            matchy[v] = u;
            res ++;
            break;
        }
    }
    while (1) {
        int tmp = findAugment();
        if (tmp == 0) break;
        else enLarge(tmp);
    }
    printf("%d\n", res);
    //FOR(i, 1, nx) if (matchx[i]) printf("%d - %d\n", i, matchx[i]);
    //fou << res << "\n";
    FOR(i, 1, ny)
        printf("%d ", matchy[i]);
        //fou << matchy[i] << " ";
    return 0;
}
/** Happy Coding :D */
