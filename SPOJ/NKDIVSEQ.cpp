#include <bits/stdc++.h>
using namespace std;
#define task "NKDIVSEQ"
int n;

int main() {
	// freopen(task".inp", "r", stdin);
	// freopen(task".out", "w", stdout);
	scanf("%d", &n);
	long long val = 0;
	int cnt = 0;
	for (int i = 1; ; ++ i) {
		val += - val % i + i;
		//cerr << val << "\n";
		if (cnt + i >= n) {
			printf("%lld\n", val + 1LL * (n - cnt - 1) * i);
			exit(0);
		} else {
			val += 1LL * (i - 1) * i;
			cnt += i;
		}
		//cerr << val << "\n";
	}
}