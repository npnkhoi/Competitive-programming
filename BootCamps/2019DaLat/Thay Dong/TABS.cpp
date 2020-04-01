#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;

const int N = 1005;

int n, a[N][N], b[N][N], ope[2 * N];
bool flag;
int diag1, diag2;
vector<ii> adj[2 * N];

void dfs(int u) {
	// cerr << "dfs " << u << "\n"; 
	if (!flag) return;
	for (ii v : adj[u]) {
		if (ope[v.fi] == -1) {
			ope[v.fi] = ope[u] ^ v.se;
			dfs(v.fi);
		} else {
			if (ope[v.fi] != ope[u] ^ v.se) {
				flag = 0;
			}
		}
	}
}

void calc() {
	for (int i = 1; i <= 2 * n; ++ i) adj[i].clear();

	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			if (a[i][j] != 0) {
				int tmp = a[i][j] != b[i][j];
				adj[i].push_back(make_pair(j + n, tmp));
				adj[j + n].push_back(make_pair(i, tmp));
				// cerr << "edge " << i << " " << j << " " << tmp << "\n";
			}
		}
	}
	flag = 1;
	memset(ope, -1, sizeof ope);
	for (int i = 1; i <= 2 * n; ++ i) {
		if (ope[i] == -1) {
			ope[i] = 0;
			dfs(i);
		}
		if (!flag) return;
	}
	// cerr << "ok\n";
	if (flag) {
		int cnt = diag1 + diag2;
		for (int i = 1; i <= 2 * n; ++ i) cnt += ope[i];
		printf("%d\n", cnt);
		if (diag1) printf("3 1\n");
		if (diag2) printf("3 2\n");
		for (int i = 1; i <= n; ++ i) {
			if (ope[i]) printf("1 %d\n", i);
		}
		for (int i = 1; i <= n; ++ i) {
			if (ope[n + i]) printf("2 %d\n", i);
		}
		exit(0);
	}
}

int main() {
	freopen("TAB.inp", "r", stdin);
	freopen("TAB.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++ j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++ j) {
			scanf("%d", &b[i][j]);
		}
	}

	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			if ((a[i][j] == 0) ^ (b[i][j] == 0)) {
				printf("-1");
				exit(0);
			}
		}
	}

	calc();
	// cerr << "not 1\n";

	for (int i = 1; i <= n; ++ i) {
		a[i][i] = - a[i][i];
	}
	diag1 ^= 1;
	calc();

	for (int i = 1; i <= n; ++ i) {
		a[i][n - i + 1] = - a[i][n - i + 1];
	}
	diag2 ^= 1;
	calc();

	for (int i = 1; i <= n; ++ i) {
		a[i][i] = - a[i][i];
	}
	diag1 ^= 1;
	calc();

	printf("-1");
}