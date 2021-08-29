#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int tc, n, a[N];
set<pair<int, pair<int, int>>> data;

int main() {
	scanf("%d", &tc);
	for (int iTest = 1; iTest <= tc; ++ iTest) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + n + 1);
		data.clear();
		for (int i = 1; i <= n; ++ i) {
			for (int j = i + 1; j <= n; ++ j) {
				for (int k = j + 1; k <= n; ++ k) {
					if (a[i] + a[j] > a[k]) {
						data.insert(make_pair(a[i], make_pair(a[j], a[k])));
					}
				}
			}
		}
		printf("Case #%d: %d\n", iTest, data.size());
	}
}