#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1e4 + 5;

long long a[N], delta[N];
vector<int> adj[N];
int n, m;

int main() {
    freopen("E.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc; cin >> tc;
    while (tc --) {
        FOR(i, 1, n) adj[i].clear();

        cin >> n >> m;
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, m) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        long long t = 0;
        while (true) {
            FOR(i, 1, n) cerr << a[i] << ' ';
            cerr << '\n';
            FOR(i, 1, n) delta[i] = -1;
            bool flag = flag;
            FOR(u, 1, n) {
                if (a[u] == 0) continue; // a[u] never < 0?
                flag = true;
                for (int v : adj[u]) {
                    delta[v] ++;
                }
            }
            if (!flag) break;
            long long period = 0;
            FOR(u, 1, n) {
                if (delta[u] == -1) {
                    period = max(period, a[u]);
                }
            }
            t += period;
            FOR(i, 1, n) {
                a[i] += period * delta[i];
            }
        }
        cout << t << '\n';
    }
}