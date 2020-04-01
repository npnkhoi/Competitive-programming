#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

char str[N];
int s[N], n;
long long res = 0;

int main() {
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for (int i = 1; i <= n; ++ i) {
		s[i] = s[i - 1] + (str[i] == '(' ? +1 : -1);
	}
	res = 1LL * (n + 1) * (n + 2) / 2;
	int j = 0;
	for (int i = 1; i <= n - 1; ++ i) {
		if (s[i] <= 0) continue;
		if (j < i) j = i;
		while (j < n && s[j + 1] > 0) ++ j;
		res += j - i + 1;
	}		
	printf("%lld\n", res);
}