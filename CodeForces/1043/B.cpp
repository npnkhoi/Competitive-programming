#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, a[N], b[N];
vector<int> ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		b[i] = a[i] - a[i-1];
	}
	for (int k = 1; k <= n; ++ k) {
		bool ok = 1;
		for (int i = k + 1; i <= n; ++ i) {
			if (b[i] != b[i-k]) {
				ok = 0;
				break;
			}
		}
		if (ok) ans.push_back(k);
	}
	printf("%d\n", (int) ans.size());
	for (int v : ans) printf("%d ", v);
}