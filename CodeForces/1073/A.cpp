#include <bits/stdc++.h>
using namespace std;

int n, cnt[30];
char s[1005];

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int l = 1; l <= n; ++ l) {
		memset(cnt, 0, sizeof cnt);
		for (int r = l; r <= n; ++ r) {
			cnt[s[r] - 'a'] ++;
			bool flag = 0;
			for (int ch = 0; ch < 26; ++ ch) {
				if (cnt[ch] > (r - l + 1) / 2) flag = 1;
			}
			if (flag == 0) {
				printf("YES\n");
				for (int i = l; i <= r; ++ i) {
					printf("%c", s[i]);
				}
				exit(0);
			}
		}
	}
	printf("NO\n");
}