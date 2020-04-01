#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, s, a[N], b[N], mark[N];

int main() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &b[i]);
	}
	mark[1] = 1;
	if (a[1] == 1) {
		for (int i = 1; i <= n; ++ i) {
			if (a[i]) {
				mark[i] = 1;
				if (b[i]) {
					for (int j = i; j >= 1; -- j) {
						if (b[j]) mark[j] = 1;
					}
				}
			}
		}
	}
	if (mark[s]) printf("YES\n");
	else printf("NO\n");
}