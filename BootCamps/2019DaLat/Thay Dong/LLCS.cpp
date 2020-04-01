#include <bits/stdc++.h>
using namespace std;

const int N = 72;
const int oo = 1e9 + 7;

int tc, n;
char s[N][N];
int best, f[N][N], id[N];


int lcs(char a[], char b[]) {
	int m = strlen(a + 1), n = strlen(b + 1);

	for (int i = 0; i <= m; ++ i) {
		for (int l = 1; l <= best; ++ l) {
			f[i][l] = n + 1;
		}
	}

	for (int i = 0; i <= m; ++ i) {
		for (int l = 0; l <= best; ++ l) {
			f[i + 1][l] = min(f[i + 1][l], f[i][l]);

			if (f[i][l] < n) {
				int nxt = f[i][l] + 1;
				while (nxt <= n && b[nxt] != a[i + 1]) {
					nxt ++;
				}
				f[i + 1][l + 1] = min(f[i + 1][l + 1], nxt);
			}
		}
		
		if (f[i][best] <= n) return best;
	}


	for (int i = best - 1; i >= 0; -- i) {
		if (f[m][i] <= n) return i;
	}
}

void solve() {
	sort(id + 1, id + n + 1, [](int a, int b) {
		return strlen(s[a] + 1) < strlen(s[b] + 1);
	});
	best = strlen(s[id[1]] + 1);

	for (int i = 1; i < n; ++ i) {
		for (int j = i + 1; j <= n; ++ j) {
			best = min(best, lcs(s[id[i]], s[id[j]]));
		}
	}
	// cerr << "here\n";
	printf("%d\n", best);
}

int main() {
	freopen("LLCS.inp", "r", stdin);
	freopen("LLCS.out", "w", stdout);
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%s", s[i] + 1);
			// cerr << s[i] + 1 << "\n";
			id[i] = i;
		}
		solve();
	}
}