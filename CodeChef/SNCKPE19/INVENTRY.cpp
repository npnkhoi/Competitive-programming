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
			
		int tmp = firstDot + 1;
		int cnt = firstDot - 1;
		int pos = tmp;
		long long res = 0;

		// cerr << "ok\n";

		for (int i = firstDot + 1; i <= n; ++ i) {
			if (s[i] == '#') {
				// cerr << "tmp = " << tmp << "\n";
				++ cnt;
				if (i < tmp) {
					res += tmp - i;
					pos = tmp;
				} else pos = i;
				res += pos - cnt;
				tmp = pos + 2;
				// cerr << "pos = " << pos << "\n";
			}
		}
		// cerr << pos << "\n";
		if (pos >= n) {
			printf("-1\n");
		} else {
			printf("%lld\n", res);
		}
	}
}