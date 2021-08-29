#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf("%d %d", &a[i].fi, &a[i].se);
		}
		scanf("%d", &price);
		printf("%.2lf", 
			(double) price / (triArea(a[1], a[2], a[3]) + triArea(a[1], a[4], a[3]));
	}
}