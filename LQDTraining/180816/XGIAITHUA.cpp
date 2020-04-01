#include <bits/stdc++.h>
using namespace std;

#define task "XGIAITHUA"

int n;
vector<int> ans;

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d", &n);
	if (n == 1) {
		printf("3\n1\n2\n6\n");
	} else {
		long double curLog = log(6) / log(10);
		//cerr << curLog << "\n";
		for (int x = 4; ; x ++) {
			// dig = log10(x!)
			curLog += (long double) log(1.0 * x) / log(10);
			//cerr << x << " " << curLog << "\n";
			if ((int) curLog + 1 == n) {
				ans.push_back(x);
			} else if ((int) curLog + 1 > n) {
				break;
			}
		}
		if (ans.empty()) {
			printf("NO\n");
		} else {
			printf("%d\n", (int) ans.size());
			for (int i = 0; i < ans.size(); i ++) {
				printf("%d\n", ans[i]);
			}
		}
	}
	
}