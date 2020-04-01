using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

//ifstream inp(".inp");
//ofstream out(".out");

int main() {
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, m) {
        scanf("%d%d%d%d", &u, &v, &x, &y);
        adj[u].push_back(mp(v, mp(x, y)));
        adj[v].push_back(mp(u, mp(x, y)));
    }
    FOR(i, 2, n) {

    }
    return 0;
}
/** Happy Coding :D */
