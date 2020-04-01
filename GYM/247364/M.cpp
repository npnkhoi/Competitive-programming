#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
char s[N];
int cnt[30], n;

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++ i) {
		cnt[s[i] - 'a'] ++;
	}
	for (int i = 0; i < 25; ++ i) {
		cnt[i + 1] += cnt[i] / 2;
		cnt[i] %= 2;
	}

	for (int i = 25; i >= 0; -- i) {
		for (int j = 0; j < cnt[i]; ++ j) {
			printf("%c", i + 'a');
		}
	}
}