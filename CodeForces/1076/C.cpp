#include <bits/stdc++.h>
using namespace std;

double d, delta, a, b;
int tc;

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%lf", &d);
		delta = d * d - 4 * d;
		if (delta < 0) {
			printf("N\n");
			continue;
		}
		a = (d + sqrt(delta)) / 2;
		b = (d - sqrt(delta)) / 2;
		if (b < 0) {
			printf("N\n");
			continue;
		}
		printf("Y %.10lf %.10lf\n", a, b);
	}
}