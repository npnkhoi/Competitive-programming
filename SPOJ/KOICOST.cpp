#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()
#define task ""
typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;
typedef pair<int, ii> Edge;

const int N = 1e6 + 5, md = 1e9;

int n, m, res, lab[N];
Edge e[N];

int root(int u) {
	return (lab[u] < 0 ? u : lab[u] = root(lab[u]));
}

void merge(int u, int v) {
	if (lab[u] > lab[v]) swap(u, v);
	lab[u] += lab[v];
	lab[v] = u;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> m;
	REP(i, m) {
		cin >> e[i].X >> e[i].Y.X >> e[i].Y.Y;
	}
	sort(e, e + m, greater<Edge>());
	memset(lab, -1, sizeof lab);
	REP(i, m) {
		int u = root(e[i].Y.X), v = root(e[i].Y.Y);
		if (u == v) {
			res = (res + (lint)(- lab[u]) * (- lab[u] - 1) / 2 % md * e[i].X) % md;
		} else {
			res = (res + (lint)(- lab[u]) * (- lab[v]) % md * e[i].X % md) % md;
			merge(u, v);
		}
	}
	cout << res;
}
