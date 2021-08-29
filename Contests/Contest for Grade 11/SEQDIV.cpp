#include <bits/stdc++.h>
using namespace std;

const int N = 105, K = 2e4 + 5, md = 1e9 + 7;;

int n, k, f[N][K], res;
vector<int> adj[K];

int main() {
	// double Time = clock();
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; ++ i) {
		for (int j = i + i; j <= k; j += i) {
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	for (int j = 1; j <= k; ++ j) f[1][j] = 1;
	for (int i = 2; i <= n; ++ i) {
		for (int j = 1; j <= k; ++ j) {
			for (int v : adj[j]) {
				f[i][j] = (f[i][j] + f[i-1][v]) % md;
			}
		}
	}
	for (int j = 1; j <= k; ++ j) res = (res + f[n][j]) % md;
	printf("%d\n", res);
	// cerr << clock() - Time;
}