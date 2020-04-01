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
    int ans = n+1;
    while (l >= r) {
        int v = q[l++];
        for (auto u:G[v]) {
            if (d[u].fi == -1) {
                d[u].fi = d[v].fi + 1;
                d[u].se
            }
        }
    }
    return 0;
}
/** Happy Coding :D */
