#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n;
int a[N], b[N];

int main() {
	while (scanf("%d", &n)) {
		if (n == -1) break;


		int p = 0, q = 0, s = 0;
		for (int i = 2; i <= sqrt(n); ++ i) {
			if (n % i == 0) {
				a[++ p] = i;
				s += i;
				if (i * i != n) {
					b[++ q] = n / i;
					s += n / i;
				}
			}
		}
		// cerr << "s = " << s << "\n";
		if (s + 1 == n) {
			printf("%d = 1 ", n);
			for (int i = 1; i <= p; ++ i) {
				printf("+ %d ", a[i]);
			}
			for (int i = q; i >= 1; --i) {
				printf("+ %d ", b[i]);
			}
			printf("\n");
		} else {
			printf("%d is NOT perfect.\n", n);
		}

	}
}