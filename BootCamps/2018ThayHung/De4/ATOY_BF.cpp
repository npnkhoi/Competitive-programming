#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,b,a) for (int i = b; i >= a; i--)
#define task "atoy"

const int N = 1e5 + 5;
int n, res;
vector<ii> child[N];
bool mark[N];

void dropBall() {
    //cerr << "dropBall\n";
    res ++;
    int u = 1;
    while (1) {
        //cerr << u << "\n";
        mark[u] = 1;
        if (child[u].size() == 0) return;
        else if (child[u].size() == 1) {
            if (child[u][0].se == 0) return;
            else {
                child[u][0].se --;
                u = child[u][0].fi;
            }
        } else {
            int x = child[u][0].se;
            int y = child[u][1].se;
            if (x == 0) {
                if (y == 0) return;
                else {
                    child[u][1].se --;
                    u = child[u][1].fi;
                }
            } else {
                if (y == 0) {
                    child[u][0].se --;
                    u = child[u][0].fi;
                } else {
                    if (x >= y) {
                        child[u][0].se --;
                        u = child[u][0].fi;
                    } else {
                        child[u][1].se --;
                        u = child[u][1].fi;
                    }
                }
            }
        }
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        int u, w;
        scanf("%d%d", &u, &w);
        if (u) child[i].pb(mp(u, w));
        scanf("%d%d", &u, &w);
        if (u) child[i].pb(mp(u, w));
    }
    int v;
    scanf("%d", &v);

    int maxTimes = 1;
    REP(j, child[1].size()) maxTimes += child[1][j].se;
    while (mark[v] == 0 && maxTimes --) dropBall();
    if (mark[v] == 0) printf("-1");
    else printf("%d", res);
}
