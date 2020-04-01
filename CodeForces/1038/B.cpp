#include <bits/stdc++.h>
using namespace std;

int n, x;

int main() {
	scanf("%d", &n);
	if (n <= 2) {
		printf("No\n");
		return 0;
	} 
	if (n % 2 == 0) x = n / 2;
	else x = (n + 1) / 2;
	printf("Yes\n");
	printf("1 %d\n", x);
	printf("%d ", n - 1);
	for (int i = 1; i <= n; ++ i) {
		if (i != x) {
			printf("%d ", i);
		}
	} 
}