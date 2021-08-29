#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <iterator>
#include <utility>
#include <complex>
#include <bitset>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
#define fi first
#define se second
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

const int N = 2e5 + 5;
const lint oo = 1e18 + 7;

int n, m, d;
pair<ii, int> e[2*N];
vector<ii> adj[N];
lint dist[2*N];
priority_queue<li, vector<li>, greater<li> > q;

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> d;
    e[0] = mp(mp(1, 1), -d);
    FOR(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        e[2 * i - 1] = mp(mp(u, v), c);
        e[2 * i] = mp(mp(v, u), c);
        adj[u].push_back(mp(v, 2 * i - 1));
        adj[v].push_back(mp(u, 2 * i));
    }
    FOR(i, 1, 2 * m) dist[i] = oo;
    q.push(mp(0, 0));

    //cerr << "ok\n";
    while (!q.empty()) {
        li tmp = q.top();
        q.pop();

        //cerr << tmp.fi << ' ' << e[tmp.se].fi.fi << ' ' << e[tmp.se].fi.se << '\n';
        if (tmp.fi != dist[tmp.se]) continue;

        int u = e[tmp.se].fi.se;

        //cerr << "from " << u << '\n';

        REP(i, adj[u].size()) {
            ii v = adj[u][i];
            //cerr << "to " << v.fi << ", id = " << v.se << '\n';
            //cerr << (e[tmp.se].se + d <= e[v.se].se) << '\n';
            //cerr << (dist[v.se] > tmp.fi + e[tmp.se].se) << '\n';
            if (e[tmp.se].se + d <= e[v.se].se && dist[v.se] > tmp.fi + e[v.se].se) {
                //cerr << "pushed\n";
                dist[v.se] = tmp.fi + e[v.se].se;
                q.push(mp(dist[v.se], v.se));
            }
        }
    }
    lint res = oo;
    FOR(i, 0, 2*m) if (e[i].fi.se == n) res = min(res, dist[i]);
    cout << (res == oo ? -1 : res);
}

