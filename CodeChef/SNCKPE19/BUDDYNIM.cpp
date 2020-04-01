#include <bits/stdc++.h>
using namespace std;

int tc, m, n;
vector<int> x, y;

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d", &m, &n);
		x.clear();
		y.clear();
		int val;
		while (m --) {
			scanf("%d", &val);
			if (val > 0) x.push_back(val);
		}
		while (n --) {
			scanf("%d", &val);
			if (val > 0) y.push_back(val);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		if (x == y) printf("Bob\n");
		else printf("Alice\n");
	}
}