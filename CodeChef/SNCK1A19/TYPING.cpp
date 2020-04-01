#include <bits/stdc++.h>
using namespace std;

map<string, int> dura;
int tc, n;
string s;

int main() {
	scanf("%d", &tc);
	while (tc --) {
		dura.clear();
		int res = 0;

		scanf("%d ", &n);
		for (int t = 1; t <= n; ++ t) {
			getline(cin, s);
			if (dura.find(s) != dura.end()) {
				res += dura[s] / 2;
			} else {
				int pre, cur, sum = 0;
				for (int i = 0; i < s.size(); ++ i) {
					cur = (s[i] == 'j' || s[i] == 'k');
					// cerr << cur << "\n";
					if (i == 0 || cur != pre) {
						sum += 2;
					} else {
						sum += 4;
					}
					pre = cur;
				}
				res += sum;
				dura[s] = sum;
				// cerr << sum << "\n";
			}
			// cerr << s << " " << res << "\n";
		}
		printf("%d\n", res);
	}
}