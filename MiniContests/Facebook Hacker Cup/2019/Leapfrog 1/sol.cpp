#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int tc, n, b;
char s[N];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &tc);
	for (int iTest = 1; iTest <= tc; ++ iTest) {
		scanf("%s", s);
		n = strlen(s);
		b = 0;
		for (int i = 1; i < n; ++ i) b += (s[i] == 'B');
		printf("Case #%d: ", iTest);
		if (b < n - 1 && b >= n / 2) printf("Y\n");
		else printf("N\n");
	}
}