#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int logN = 31;

int n, m, foo, a[N], b[N], res;
map<int, int> cnt[2][32];
void init(map<int, int> &Map, int val) {
	if (Map.find(val) == Map.end())
		Map[val] = 0;
}

int main() {
	scanf("%d%d", &n, &foo);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		for (int j = 0; j <= logN; ++j) {
			cnt[0][j][a[i] % (1 << j)] ++;
		}
	}
	scanf("%d%d", &m, &foo);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i]);
		for (int j = 0; j <= logN; ++j) {
			cnt[1][j][b[i] % (1 << j)] ++;
			if (j > 0) 
				res = max(res, cnt[1][j][b[i] % (1 << j)] + cnt[0][j][(b[i] + (1 << j - 1)) % (1 << j)]);
		}
	}
	printf("%d", res);
}