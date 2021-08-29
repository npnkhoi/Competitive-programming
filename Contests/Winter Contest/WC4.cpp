#include <bits/stdc++.h>
using namespace std;
#define task "WC4"
int tc, a[5], b[5];

bool checkEqual() {
	for (int i = 0; i <= 2; ++ i) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

bool checkSameShape() {
	if (1LL * a[0] * b[1] != 1LL * b[0] * a[1]) return false;
	if (1LL * a[0] * b[2] != 1LL * b[0] * a[2]) return false;
	return true;
}

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d%d%d%d%d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
		sort(a, a + 3);
		sort(b, b + 3);
		if (checkEqual()) {
			printf("EQUAL\n");
		} else if (checkSameShape()) {
			printf("SAME SHAPE\n");
		} else {
			printf("NOT SAME SHAPE\n");
		}
	}
}