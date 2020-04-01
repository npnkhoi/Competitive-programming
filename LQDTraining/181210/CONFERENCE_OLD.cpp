#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "CONFERENCE"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e6 + 5;

int n, m, k, x[N], y[N],
    last[N], lastDay[N], nxtDay[N], hasArt[N], nxt[N];
vi v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n >> m >> k;
    FOR(i, 1, m) cin >> x[i] >> y[i];
    memset(nxt, -1, sizeof nxt);
    memset(last, -1, sizeof last);
    memset(lastDay, -1, sizeof lastDay);
    FORD(i, m, 1) {
        int u = x[i], v = y[i];
        if (u > v) swap(u, v);
        if (v <= k) { // 2 scientists
            if (nxt[v] == -1) swap(u, v);

            if (nxt[u] != -1 && nxt[v] != -1) {
                if (nxtDay[v] < nxtDay[u]) {
                    nxt[u] = nxt[v];
                    nxtDay[u] = nxtDay[v];
                } else {
                    nxt[v] = nxt[u];
                    nxtDay[v] = nxtDay[u];
                }
            } else if (nxt[u] == -1 && nxt[v] != -1) {
                nxt[u] = nxt[v];
                nxtDay[u] = nxtDay[v];

                last[u] = last[v];
                lastDay[u] = lastDay[v];
            }
        } else if (u <= k) { // scientist vs journalist
            cerr << u << v << "\n";
            nxt[u] = v;
            nxtDay[u] = i;
            if (last[u] != -1) continue;
            last[u] = v;
            lastDay[u] = i;
            //cerr << last[u] << " " << lastDay[u] << '\n';
        }
    }
    FOR(i, 1, k) cout << lastDay[i] << ' ';
    cout << '\n';

    FOR(i, 1, k) hasArt[last[i]] = 1;
    FOR(i, k + 1, n) if (hasArt[i]) v.push_back(i);
    cout << v.size() << ' ';
    REP(i, v.size()) cout << v[i] << ' ';
    cout << '\n';

    FOR(i, 1, k) cout << last[i] << ' ';
}
