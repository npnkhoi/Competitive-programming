#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int N = 2e5 + 5;

int n, m, d, ans[N];
ii a[N];
priority_queue<ii, vector<ii>, greater<ii> > heap;

int main() {
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (heap.empty() || a[i].first - heap.top().first <= d) {
			++res;
			heap.push(make_pair(a[i].first, res));
			ans[a[i].second] = res;
		} else {
			int tmp = heap.top().second;
			heap.pop();
			heap.push(make_pair(a[i].first, tmp));
			ans[a[i].second] = tmp;
		}
	}
	printf("%d\n", res);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
}