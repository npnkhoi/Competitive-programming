#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, a[N], pos[N], top, take;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	top = 1;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &take);
		if (pos[take] < top) {
			printf("0 ");
			// cerr << "---" << top << "\n";
		} else {
			printf("%d ", pos[take] - top + 1);
			// cerr << "---" << top << "\n";
			top = pos[take] + 1;
		}
	}
}