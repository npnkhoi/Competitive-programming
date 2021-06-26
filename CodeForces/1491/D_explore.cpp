#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
int mark[105];
int cnt[35];

long long lso(long long x) {
	return x & (-x);
}

bool include(long long u, long long v) {
	return (u & v) == v;
}

int bit_pos(long long x) {
	return (int) log2(x);
}

bool reachable(long long u, long long v) {
	long long tmp;
	memset(cnt, 0, sizeof cnt);
	while (u < v) {
		cerr << u << ' ' << v << '\n';
		for (int i = 0; i <= 30; ++ i) {
			if (u >> i & 1) {
				cnt[i] ++;
			}
		}
		tmp = lso(u ^ v);

		while (tmp > 0 && cnt[bit_pos(tmp)] == 0) {
			tmp = tmp >> 1;
		}
		if (tmp == 0) {
			return false;
		}
		u += tmp;
		cnt[bit_pos(tmp)] --;
		// if (include(u, tmp)) {
		// 	u += tmp;
		// 	cnt[bit_pos(tmp)] --;
		// } else if (tmp < lso(u)) {
		// 	return false;
		// } else {
		// }
	}
	return (u == v);
}

void dfs(int u, int lim) {
	mark[u] = 1;
	for (int v : adj[u]) {
		if (v <= lim) dfs(v, lim);
	}
}

bool reachable_2(long long u, long long v) {
	memset(mark, 0, sizeof mark);
	dfs(u, 100);
	return mark[v];
}


int main() {
	for (int i = 1; i <= 100; ++ i) {
		for (int j = 1; j <= i; ++ j) {
			if ((i & j) == j && i + j <= 100) {
				// printf("%d %d\n", i, i + j);
				adj[i].push_back(i + j);
			}
		} 
	}
	for (int u = 1; u <= 100; ++ u) {
		for (int v = u + 1; v <= 100; ++ v) {
			// if (reachable(u, v) != reachable_2(u, v)) {
			// 	printf("Sth wrong with %d, %d\n", u, v);
			// 	cerr << reachable(u, v) << reachable_2(u, v) << '\n';
			// }
			if (reachable_2(u, v)) {
				cerr << u << ' ' << v << '\n';
			}
		}
	}
}