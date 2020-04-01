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

#define task "sol"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int PRI = 1e5;
const int N = 1e5 + 5;

int n, res, last;
int a[N], b[N], trace[N], ml[N], mr[N], minFact[PRI + 2];
vector<ii> v;
vi primes, adj[N], vl, vr;
queue<int> q;
// set<int> reach[N];

void sieve() {
	FOR(i, 2, PRI) {
		if (minFact[i] == 0) {
			primes.push_back(i);
			for (ll j = 1LL * i * i; j <= PRI; j += i) {
				if (minFact[j] == 0) minFact[j] = i;
			}
		}
	}
}

void div(int &x, int fact, int id) {
	if (x % fact) return;
	while (x % fact == 0) x /= fact;
	v.push_back(mp(fact, id));
}

void parse(int x, int id) {
	// cerr << "parse " << x << " " << id << "\n";
	if (x > PRI) {
		for (int f : primes) {
			if (1LL * f * f > x) break;
			div(x, f, id);
		}
		// cerr << "done\n";
	}
	// cerr << x << "\n";
	if (x > PRI) {
		v.push_back(mp(x, id));
		return;
	}
	while (minFact[x] != 0) {
		div(x, minFact[x], id);
	}
	if (x > 1) v.push_back(mp(x, id));
}

bool augment() {
	while (!q.empty()) q.pop();
	memset(trace, 0, sizeof trace);
	FOR(i, 1, n) {
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
	// freopen(task".inp", "r", stdin);
	// freopen(task".out", "w", stdout);

	sieve();
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		// debug(i);
		parse(a[i], i);
	}
	FOR(i, 1, n) {
		cin >> b[i];
		parse(b[i], -i);
	}
	sort(all(v));
	// cerr << v.size() << '\n';
	// for (ii t : v) {
	// 	cerr << t.fi << " " << t.se << "\n";
	// }
	REP(i, v.size()) {
		if (v[i].se > 0) vl.push_back(v[i].se);
		else vr.push_back(- v[i].se);
		if (i == v.size() - 1 || v[i].fi != v[i + 1].fi) {
			for (int x : vl) for (int y : vr) {
				// if (reach[x].find(y) == reach[x].end()) {
					adj[x].push_back(y);
					// reach[x].insert(y);
				// }
				// cerr << x << " -> " << y << "\n";
			}
			vl.clear(); vr.clear();	
		}
	}
	FOR(i, 1, n) {
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
