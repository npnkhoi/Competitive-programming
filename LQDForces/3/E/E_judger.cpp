// This is to compare output of two programs
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

#define task "E"

typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;


lint Rand(lint l, lint r) {
	lint res = l + (
	1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
	1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
	1LL * rand() * (RAND_MAX + 1) +
	1LL * rand()) % (r - l + 1);
	if (res < 0) res += r - l + 1;
	return res;
}

const int N = 1e5 + 5;

vi adj[N];
int idx, perm[N], ord[N], a[N];

void dfs(int u, int par) {
	a[++idx] = u;
	for (int v : adj[u]) {
		if (v == par) continue;
		dfs(v, u);
	}
}


void test(int iTest) {
	ofstream inp((to_string(iTest) + ".inp").c_str());
	int tc = 10;
	inp << tc << '\n';
	while (tc --) {     
		int n = Rand(4e4, 5e4);
		// int n = 50000;
		inp << n << '\n';
		FOR(i, 1, n) {
			perm[i] = ord[i] = i;
			adj[i].clear();
		}

		random_shuffle(perm + 1, perm + n + 1);
		random_shuffle(ord + 2, ord + n + 1);
		FOR(i, 2, n) {
			int x = ord[i];
			int u = perm[x];
			int v = perm[Rand(1, x - 1)];
			if (Rand(0, 1)) swap(u, v);
			inp << u << ' ' << v << '\n';
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if (Rand(0, 1)) {
			// random permutation
			random_shuffle(perm + 1, perm + n + 1);
			FOR(i, 1, n) inp << perm[i] << ' ';
		} else {
			// always YES
			idx = 0;
			dfs(Rand(1, n), -1);
			FOR(i, 1, n) inp << a[i] << ' '; 
		}
	}
	inp.close();
}

const int nTest = 5;

int main() {
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	srand(time(NULL));

	// test(5); exit(0);

	FOR(love, 1, 4) {
		printf("*TEST NUMBER %d\n", love);
		test(love);
		// double timer1 = clock();
		// system(task".exe");
		// timer1 = (clock() - timer1) / CLOCKS_PER_SEC;
		// double timer2 = clock();
		// system(task"_BF.exe");
		// timer2 = (clock() - timer2) / CLOCKS_PER_SEC;
		// printf("Time: %lf %lf\n", timer1, timer2);

		// if (system("fc "task".out "task".ans")) {
		// // if (system("fc "task".out "task".out")) {
		// 	printf("WRONG ANSWER\n");
		// 	return 0;
		// }
		// printf("CORRECT\n");
	}
}
