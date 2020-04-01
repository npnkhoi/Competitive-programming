#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 +5;

int tc, n;
char s[N];

int cntDot(int i) {
	return (s[i-2] == '.') + (s[i-1] == '.') + (s[i] == '.');
}

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		// cerr << s + 1 << "\n";
		int flag = 0, firstDot = 0;
		for (int i = 1; i <= n; ++ i) {
			if (s[i] == '.') {
				firstDot = i;
				break;
			}
		}
		if (firstDot == 0) {
			printf("0\n");
			continue;
		}

		// cerr << firstDot << "\n";

		bool ok = 1;
		for (int i = firstDot + 1; i <= n; ++ i) {
			if (s[i] == '#') {
				ok = 0;
				break;
			}
		}
		if (ok) {
			printf("0\n");
			continue;
		}
		for (int i = 3; i <= n; ++ i) {
			if (cntDot(i) >= 2) {
				flag = i;
				break;
			}
		}
		if (flag == 0) {
			printf("-1\n");
			continue;
		}
		// ------------------------------------
		int res = 0;
		for (int i = flag - 1; i >= firstDot + 2; -- i) {
			// cerr << "at " << i << "\n";
			while (cntDot(i) < 2) {
				if (i > 3 && cntDot(i - 1) >= 2) {
					i --;
					break;
				}
				res ++;
				if (s[i] == '#') {
					swap(s[i], s[i + 1]);
				} else {
					swap(s[i-1], s[i]);
				}
				// cerr << s + 1 << "\n";
			}
		}
		// cerr << "res " << res << "\n";
		int tmp = 0;
		for (int i = 1; i <= n; ++ i) {
			if (s[i] == '#') {
				++ tmp;
				res += i - tmp;
			}
		}
		printf("%d\n", res);
	}
}