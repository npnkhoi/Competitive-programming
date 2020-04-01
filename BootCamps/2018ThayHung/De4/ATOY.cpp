#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
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
int n;
vector<ii> child[N];
int par[N];

ll sol(int v, ll t) { /// v: vtx, t: times
    //printf("%d %lld\n", v, t);
    if (v == 1) return t;
    int u = par[v];
    if (child[u].size() == 1) {
        if (child[u][0].se >= t) return sol(u, t);
        else return -1;
    } else { // child[u].size == 2
        bool dir = (v == child[u][1].fi);
        int wl = child[u][0].se;
        int wr = child[u][1].se;

        if (dir == 0) {
            if (wl < t) return -1;
            if (wl - wr >= t) return sol(u, t);
            return sol(u, 2*t - 1 - (wl - wr));
        } else {
            if (wr < t) return -1;
            if (wr - wl >= t) return sol(u, t);
            return sol(u, 2*t - (wr - wl));
        }
    }

}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        int u, w;
        scanf("%d%d", &u, &w);
        if (u) {
            child[i].pb(mp(u, w));
            par[u] = i;
            //capChild[i] += w;
        }
        scanf("%d%d", &u, &w);
        if (u) {
            child[i].pb(mp(u, w));
            par[u] = i;
            //capChild[i] += w;
        }
    }
    //cerr << "ok\n";
    int v;
    scanf("%d", &v);
    printf("%lld\n", sol(v, 1));
}
