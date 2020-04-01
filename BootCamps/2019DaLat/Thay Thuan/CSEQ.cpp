#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m;
int a[N];
long long s[N], res;

void getInt(int &x) {
	int c;
	do c = getchar(); while (c < '0' || '9' < c);
	x = c - '0';
	while (1) {
		c = getchar();
		if (c < '0' || '9' < c) break;
		x = 10 * x + c - '0';
	}
}

int main() {
	getInt(n);
	getInt(m);
	for (int i = 1; i <= n; ++ i) {
		getInt(a[i]);
		s[i] = s[i-1] + a[i]; // long long
	}
	int j = 1;
	for (int i = 1; i <= n; ++ i) {
		while (s[i] - s[j - 1] > m) ++ j;
		res += i - j + 1;
	}
	printf("%lld", res);
}