#include <bits/stdc++.h>
using namespace std;

int main() {
	scanf("%s", s);
	n = strlen(s);
	int cur = -1, cnt = 0;
	for (int i = 0; i < n; ++ i) {
		tmp = (s[i] == 'L') ^ (i % 2);
		if (s[i] - '0' == cur) {
			cnt ++;
		} else {
			block[++m] = make_pair(cnt, tmp ^ 1);
		}
	}
	if (cnt > 0) {
		block[++m] = make_pair(cnt, tmp);
	}
	for (int i = 1; i <= n; ++ i) {
		f[i][0] = (block[i].second ? block[i].first : 0) + f[i - 1][0];
		for (int j = 1; j <= n; ++ j) {
			f[i][j] = ((j ^ block[i].second) % 2 ? block[i].first : 0) + max(f[i - 1][j], f[i - 1][j - 1]);
		}
	}
	
}