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

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1005;

int nl, nr, last, res;
int ml[N], mr[N], a[N], b[N], x[N], y[N], trace[N];
vi adj[N];
queue<int> q;

bool augment() {
	while (!q.empty()) q.pop();
	memset(trace, 0, sizeof trace);
	FOR(i, 1, nl) {
		if (ml[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (trace[v]) continue;
			trace[v] = u;
			if (mr[v] == 0) {
				last = v;
				return true;
			}
			q.push(mr[v]);
		}
	}
	return false;
}

void enlarge() {
	// cerr << "enlarge\n";
	res ++;
	int v = last, nxt;
	while (1) {
		nxt = ml[trace[v]];
		// debug(nxt);
		ml[trace[v]] = v;
		mr[v] = trace[v];
		if (nxt == 0) break;
		v = nxt;
	} 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> nl >> nr;
	FOR(i, 1, nl) cin >> a[i] >> b[i];
	FOR(i, 1, nr) cin >> x[i] >> y[i];
	FOR(i, 1, nl) {
		FOR(j, 1, nr) {
			if (x[j] > a[i] && y[j] <= b[i]) {
				// cerr << i << " " << j << "\n";
				adj[i].push_back(j);
			}
		}
	}
	FOR(i, 1, nl) {
		for (int j : adj[i]) {
			if (mr[j] == 0) {
				ml[i] = j;
				mr[j] = i;
				res ++;
				break;
			}
		}
	}
	while (augment()) enlarge();
	cout << res;
	return 0;
}
