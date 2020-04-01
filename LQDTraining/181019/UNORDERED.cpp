#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b, int c) {
	if (a <= b && b <= c) return 0;
	if (a >= b && b >= c) return 0;
	return 1;
}

const int N = 1e5 + 5;
const int oo = 1e9 + 7;

int n, a[N], minL[N], maxL[N], minR[N], maxR[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	minL[0] = oo; maxL[0] = - oo;
	for (int i = 1; i <= n; ++ i) {
		minL[i] = min(minL[i - 1], a[i]);
		maxL[i] = max(maxL[i - 1], a[i]);
	}
	minR[n + 1] = oo; maxR[n + 1] = - oo;
	for (int i = n; i >= 1; -- i) {
		minR[i] = min(minR[i + 1], a[i]);
		maxR[i] = max(maxR[i + 1], a[i]);
	} 
	for (int i = 2; i <= n - 1; ++ i) {
		if (check(minL[i - 1], a[i], minR[i + 1])) {
			printf("3\n");
			return 0;
		}
		if (check(maxL[i - 1], a[i], maxR[i + 1])) {
			printf("3\n");
			return 0;
		}
	}
	printf("0");
}