#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;

int n, idx, need[N], lab[4*N];
ll x[N], y[N];
vector<ll> hub;
vector<int> comp[4*N];

void merge(int u, int v) {
	u  = lab[u], v = lab[v];
	if (u == v) return;
	if (comp[u].size() < comp[v].size()) swap(u, v);
	for (int chi : comp[v]) {
		if (lab[chi^1] == u) {
			REP(i, n - idx + 1) cout << "No\n";
			exit(0);
		} else {
			lab[chi] = u;
			comp[u].pb(chi);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) {
		int u, v;
		cin >> x[i] >> y[i] >> u >> v;
		x[i] = - x[i];
		need[i] = u ^ v;
		hub.pb(x[i]);
		hub.pb(y[i]);
	}
	sort(hub.begin(), hub.end());	
	hub.resize(unique(hub.begin(), hub.end()) - hub.begin());
	REP(i, 4 * n) {
		lab[i] = i;
		comp[i].pb(i);
	}
	FOR(i, 1, n) {
		x[i] = upper_bound(hub.begin(), hub.end(), x[i]) - hub.begin() - 1;
		y[i] = upper_bound(hub.begin(), hub.end(), y[i]) - hub.begin() - 1;
		//cerr << x[i] << " " << y[i] << "\n";
		idx ++;
		if (need[i]) {
			merge(2*x[i], 2*y[i] + 1);
			merge(2*y[i], 2*x[i] + 1);
		} else {
			merge(2*x[i], 2*y[i]);
			merge(2*x[i]+1, 2*y[i]+1);
		}
		cout << "Yes\n";
	}
}
