#include <bits/stdc++.h>
using namespace std;

bool makeTriangle(int a, int b, int c) {
	return (a + b > c && b + c > a && c + a > b);
}

int l[6], res;

int main() {
	for (int i = 1; i <= 5; ++i) {
		scanf("%d", &l[i]);
	}
	for (int i = 1; i <= 5; ++ i) {
		for (int j = i + 1; j <= 5; ++j) {
			for (int k = j + 1; k <= 5; ++k) {
				if (makeTriangle(l[i], l[j], l[k])) {
					++ res;
					// cerr << i << " " << j << " " << k << "\n";
				}
			}
		}
	}
	printf("%d", res);
}