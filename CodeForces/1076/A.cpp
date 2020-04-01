#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
char s[N];
int n;

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i < n; ++ i) {
		if (s[i] > s[i + 1]) {
			for (int j = 1; j < i; ++ j) printf("%c", s[j]);
			for (int j = i + 1; j <= n; ++ j) printf("%c", s[j]);
				return 0;
		}
	}
	for (int i = 1; i < n; ++ i) printf("%c", s[i]);
}