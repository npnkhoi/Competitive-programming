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

int n, m, k, x[N], y[N];
int day[N], id[N], nxtDay[N], nxtId[N], hasArt[N];
vi v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n >> m >> k;
    FOR(i, 1, m) cin >> x[i] >> y[i];
    memset(nxtId, -1, sizeof nxtId);
    memset(nxtDay, -1, sizeof nxtDay);
    memset(id, -1, sizeof id);
    memset(day, -1, sizeof day);
    FORD(i, m, 1) {
        int u = x[i], v = y[i];
        if (u > v) swap(u, v);

        if (v <= k) { // 2 scientists
            if (nxtId[v] == -1) swap(u, v);

            if (nxtId[u] == -1 && nxtId[v] != -1) {
                //cerr << u << ' ' << v << '\n';
                //cerr << nxtId[v] << '\n';
                day[u] = i;
                id[u] = nxtId[v];

                nxtId[u] = nxtId[v];
                nxtDay[u] = nxtDay[v];
            } else if (nxtId[u] != -1 && nxtId[v] != -1) {
                if (nxtDay[u] > nxtDay[v]) swap(u, v);
                nxtId[v] = nxtId[u];
                nxtDay[v] = nxtDay[u];
            }
        } else if (u <= k) { // scientist vs journalist
            if (nxtId[u] == -1) {
                id[u] = v;
                day[u] = i;
            }
            nxtId[u] = v;
            nxtDay[u] = i;
        }
    }
    FOR(i, 1, k) cout << day[i] << ' ';
    cout << '\n';

    FOR(i, 1, k) if (id[i] != -1) hasArt[id[i]] = 1;
    FOR(i, k + 1, n) if (hasArt[i]) v.push_back(i);
    cout << v.size() << ' ';
    REP(i, v.size()) cout << v[i] << ' ';
    cout << '\n';

    FOR(i, 1, k) cout << id[i] << ' ';
}
