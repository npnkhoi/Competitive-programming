#include <bits/stdc++.h>
using namespace std;
#define task "CUBICS"
int n, k, len, head;
map<long long, int> mark;

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d%d", &n, &k);
	long long s = 0;
	len = 0;
	int val;

	mark[0] = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &val);
		s += val - k;
		if (mark.find(s) == mark.end()) {
			mark[s] = i;
		} else {
			int tmp = i - mark[s];
			if (tmp > len) {
				len = tmp;
				head = mark[s] + 1;		
			}
		}
	}
	if (len == 0) printf("0\n");
	else printf("%d %d\n", len, head);
}