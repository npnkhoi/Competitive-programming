#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int N = 2005;
const vi ZERO = {};

int n, m;
vi c[N][N], res;
int trace[N];
queue<int> q;
vector<int> adj[N];

bool cmp(int a, int b) {
	return abs(a) > abs(b);
}

vi operator + (const vi &a, const vi &b) {
	vi res = a;
	// cerr << "begin +\n";
	for (int x : b) res.push_back(x);
	// cerr << "end1 +\n";
	sort(res.begin(), res.end(), cmp);
	return res;
}

vi operator - (const vi &a, const vi &b) {
	vi res = a;
	for (int x : b) res.push_back(-x);
	sort(res.begin(), res.end(), cmp);
}

void show(const vi &a) {
	cerr << "show: ";
	for (int x : a) cerr << x << " ";
	cerr << "\n";
}

bool operator > (const vi &a, const vi &b) {
	// cerr << "compare: \n";
	// show(a); show(b);
	if (a.empty()) {
		if (b.empty()) return 0;
		return b[0] < 0;
	}
	if (b.empty()) return a[0] > 0;
	return a[0] > b[0]; 
}

int Exp(int i) {
	if (i == 0) return 1;
	else return 3 * Exp(i - 1);
}

int val(vi &a) {
	int res = 0;
	for (int x : a) res += Exp(x);
	return res;
}


bool BFS() {
	memset(trace, 0, sizeof trace);
	trace[1] = -1;
	while (!q.empty()) q.pop();
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		// cerr << "reach " << u << "\n";
		for (int v : adj[u]) {
			// cerr << u << " " << v << ": ";
			// show(c[u][v]);
			if (!(c[u][v] > ZERO) || trace[v] != 0) continue;
			trace[v] = u;
			if (v == n) return 1;
			q.push(v);
		}
	}
	return 0;
}

void augment() {
	// cerr << "begin aug\n";
	// for (int i = 1; i <= n; ++ i) cerr << trace[i] << " "; cerr << "\n";
	int u = n;
	vi minEdge = {m + 1};
	while (1) {
		if (u == 1) break;
		if (minEdge > c[trace[u]][u]) 
			minEdge = c[trace[u]][u];
		u = trace[u];
	}
	// cerr << "done minedge\n";
	// show(minEdge);
	// cerr << "1\n";
	vi tmp = res + minEdge;
	res = tmp;
	// cerr << "2\n";
	u = n;
	while (1) {
		// cerr << u << "\n";
		if (u == 1) break;
		c[trace[u]][u] = c[trace[u]][u] - minEdge;
		c[u][trace[u]] = c[u][trace[u]] + minEdge;
		u = trace[u];
	}
	// cerr << "done aug\n";
}

int main() {
	freopen("test.inp", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		u ++; v ++;
		adj[u].push_back(v);		
		adj[v].push_back(u);
		c[u][v] = {i};
		c[v][u] = {i};
	}
	while (BFS()) {
		augment();
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				cerr << val(c[i][j]) << "\n";
				show(c[i][j]);
			}
		}
	}
	// cerr << res.size() << "\n";
	// cerr << "result\n";

	for (int x : res) {
		cerr << x << " ";
	}
}