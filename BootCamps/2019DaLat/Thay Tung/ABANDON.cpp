#include <bits/stdc++.h>
using namespace std;

vector<int> v, t;
long long n;
int k;

int main() {
	scanf("%lld%d", &n, &k);

	for (int i = 1; ; ++ i) {
		if (n % k == 0) {
			printf("%d", i);
			exit(0);
		}
		n = n - n / k;
	}
}