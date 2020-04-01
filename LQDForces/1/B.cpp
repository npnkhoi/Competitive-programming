#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int n, a[N];

void getInt(int &x) {
	int c = getchar();
	while (c < '0' || '9' < c) c = getchar();
	x = c - '0';
	while (1) {
		c = getchar();
		if (c < '0' || '9' < c) break;
		x = x * 10 + c - '0';
	}
}

int main() {
	// freopen("test18.inp", "r", stdin);
	// freopen("log.txt", "w", stdout);
	scanf("%d", &n);
	int t = 1e9 + 7, idx;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		// cerr << i << " " << a[i] << "\n";
		int tmp = (a[i] - i + n) / n * n + i;
		if (t > tmp) {
			t = tmp;
			idx = i;
		}
	}
	printf("%d\n", idx);
}