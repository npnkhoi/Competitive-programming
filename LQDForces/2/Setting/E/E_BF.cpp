#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, k, md, a[N], mark[N];
long long res = 0;

void brute(int i, int j) {
	if (i == k + 1) {
		long long tmp = 1;
		for (int i = 1; i <= n; ++ i) {
			if (mark[i]) tmp = (tmp * a[i]) % md;
		}
		res = (res + tmp) % md;
		return;
	}
	for (int x = j; x <= n; ++ x) {
		if (mark[x] == 0) {
			mark[x] = 1;
			brute(i + 1, x + 1);
			mark[x] = 0;
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &k, &md);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	brute(1, 1);
	printf("%d\n", res);
}