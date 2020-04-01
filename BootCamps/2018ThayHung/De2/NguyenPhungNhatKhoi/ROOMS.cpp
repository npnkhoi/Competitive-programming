#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
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
#define task "rooms"

const int N = 2005;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int m, n;
char a[N][N];
int id[N][N];
queue<ii> q;

bool inside(int x, int y) {
    return 1 <= x && x <= m && 1 <= y && y <= n;
}
void flood(int x, int y, int idx) {
    while (!q.empty()) q.pop();
    q.push(mp(x,y));
    id[x][y] = idx;
    while (!q.empty()) {
        ii tmp = q.front(); q.pop();
        REP(z,  4) {
            int u = tmp.fi + dx[z];
            int v = tmp.se + dy[z];
            if (inside(u, v) && a[u][v] == a[tmp.fi][tmp.se] && id[u][v] == 0) {
                id[u][v] = idx;
                q.push(mp(u, v));
            }
        }
    }
}
void sub1() {
    int queries;
    scanf("%d", &queries);
    while (queries --) {
        int x, y, u, v;
        scanf("%d%d%d%d", &x, &y, &u, &v);
        set<int> data;
        int res = 0;
        FOR(i, x, u) FOR(j, y, v) data.insert(id[i][j]);
        printf("%d\n",(int)data.size());
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) FOR(j, 1, n) scanf(" %c", &a[i][j]);
    int idx = 0;
    FOR(i, 1, m) FOR(j, 1, n)
    if (id[i][j] == 0) flood(i, j, ++ idx);
    sub1();
    return 0;
}
