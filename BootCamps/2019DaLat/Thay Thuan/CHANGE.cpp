#include <bits/stdc++.h>
using namespace std;

const int val[] = {500, 100, 50, 10, 5, 1};
const int MAX_VAL = 1000;

int tc, f[MAX_VAL + 5], x;

int main() {
	for (int i = 1; i <= MAX_VAL; ++ i) {
		f[i] = i;
		for (int j = 0; j < 6; ++ j) {
			if (val[j] > i) continue;
			f[i] = min(f[i], f[i - val[j]] + 1);
		}
	}
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &x);
		printf("%d\n", f[1000 - x]);
	}
}