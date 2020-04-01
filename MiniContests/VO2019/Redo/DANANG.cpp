#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,a,b) for (int i = a; i >= b; -- i)
#define all(v) v.begin(), v.end()
#define debug(x) cerr << #x << " = " << x << '\n'
#define task "DANANG"
typedef long long lint;
typedef unsigned long long ul;
typedef pair<int, int> ii;
typedef pair<lint, int> li;
typedef vector<int> vi;
typedef pair<li, int> Pack;

const int N = 2e5 + 5;
const int oo = 1e9 + 7;

int n, m, D;
vector<ii> adj[N];
priority_queue<Pack, vector<Pack>, greater<Pack> > q;

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> D;
    FOR(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(mp(c, v));
        adj[v].push_back(mp(c, u));
    }
    FOR(i, 1, n) sort(all(adj[i]));
    q.push(mp(mp(0, -oo), 1));
    while (!q.empty()) {
        Pack tmp = q.top();
        q.pop();

        int d = tmp.X.X, c = tmp.X.Y, u = tmp.Y;
        if (u == n) {
            cout << d << '\n';
            exit(0);
        }

        while (!adj[u].empty()) {
            ii v = adj[u].back();
 
            if (c + D <= v.X) {
                adj[u].pop_back();
                q.push(mp(mp(d + v.X, v.X), v.Y));
            } else break;
        }
    }
    cout << -1;
}

