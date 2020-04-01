#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int tc, n, a[N], b[N];

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
		for (int i = 1; i <= n; ++ i) scanf("%d", &b[i]);
		bool noSol = 0;
		for (int i = 1; i <= n - 2; ++ i) {
			if (a[i] < b[i]) {
				int tmp = b[i] - a[i];
				a[i] += tmp;
				a[i + 1] += 2 * tmp;
				a[i + 2] += 3 * tmp;
			} else if (a[i] > b[i]) {
				noSol = 1;
				break;
			}
		}
		if (noSol || a[n - 1] != b[n - 1] || a[n] != b[n]) {
			printf("NIE\n");
		} else {
			printf("TAK\n");
		}
	}

}