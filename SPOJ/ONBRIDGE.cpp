#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define showArr(a, x, y) cerr << #a << " "; for (int i = x; i <= y; ++ i) cerr << a[i] << ' '; cerr << '\n'
#define all(x) x.begin(), x.end()

#define task "onbridge"

typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 50000 + 5;

int n, m, tc, res;
int par[N];

lint Rand(lint l, lint r) {
    lint res = l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
    if (res < 0) res += r - l + 1;
    return res;
}

void makeTest() {
	srand(time(NULL));
	ofstream inp(task".inp");
	int tc = 1;
	inp << tc << "\n";
	REP(z, tc) {
		int n = 5e4, m = 1e5;
		inp << n << ' ' << m << '\n';
		REP(z, m) {
			inp << Rand(1, n) << ' ' << Rand(1, n) << '\n';
		}
	}
	inp.close();
}

void read(int &x) {
	int c;
	do c = getchar(); while (c < '0' || '9' < c);
	x = c - '0';
	while (1) {
		c = getchar();
		if (c < '0' || '9' < c) break;
		x = x * 10 + c - '0';
	}
}

struct DisjointSetUnion {
	vector<int> lab;

	int root(int u) {
		if (lab[u] < 0) return u;
		else return lab[u] = root(lab[u]);
	}

	void merge(int u, int v) {
		u = root(u); v = root(v);
		if (lab[u] > lab[v]) swap(u, v);
		lab[u] -= (lab[u] == lab[v]);
		lab[v] = u;
	}
} dsu1, dsu2;

void merge1(int u, int v) {
	res ++;
	if (dsu1.lab[dsu1.root(u)] > dsu1.lab[dsu1.root(v)]) {
		swap(u, v);
	}
	dsu1.merge(u, v);

	int x = dsu2.root(v), pre = dsu2.root(u), nxt;
	while (x != -1) {
		// cerr << x << '\n';
		if (par[x] == -1) nxt = -1;
		else nxt = dsu2.root(par[x]);
		
		par[x] = pre;

		pre = x;
		x = nxt;
	}
}

void merge2(int u, int v) {
	u = dsu2.root(u);
	v = dsu2.root(v);
	int x = u, y = v, lca;
	set<int> s;
	s.insert(x);
	s.insert(y);
	
	// find LCA
	while (1) {
		int report = 0;
		if (par[x] != -1) {
			x = dsu2.root(par[x]);
			if (s.find(x) != s.end()) {
				lca = x;
				break;
			}
			s.insert(x);
		} else report ++;

		if (par[y] != -1) {
			y = dsu2.root(par[y]);
			if (s.find(y) != s.end()) {
				lca = y;
				break;
			}
			s.insert(y);
		} else report ++;
		if (report == 2) break;
	}
	// update par[]
	x = u, y = v;
	while (dsu2.root(x) != dsu2.root(lca)) {
		dsu2.merge(x, lca);
		res --;
		x = dsu2.root(par[x]);
	}
	while (dsu2.root(y)  != dsu2.root(lca)) {
		dsu2.merge(y, lca);
		res --;
		y = dsu2.root(par[y]);
	}
	par[dsu2.root(lca)] = par[lca];
}


int main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	// freopen(task".inp", "r", stdin);
	// freopen(task".out", "w", stdout);
	read(tc);
	while (tc --) {
		read(n);
		read(m);
		dsu1.lab.assign(n + 5, -1);
		dsu2.lab.assign(n + 5, -1);
		memset(par, -1, sizeof par);
		res = 0;
		while (m --) {
			int u, v;
			read(u); read(v);
			if (dsu2.root(u) != dsu2.root(v)) {
				if (dsu1.root(u) == dsu1.root(v)) {
					merge2(u, v);
				} else {
					merge1(u, v);
				}
			}
			printf("%d\n", res);
		}
	}
}
