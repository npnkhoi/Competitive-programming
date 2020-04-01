#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, x, a[N], f[N], b[N];
long long res;
deque<int> q;

void getInt(int &x) {
	int c = getchar();
	while (c < '0' || '9' < c) c = getchar();
	x = c - '0';
	while (1) {
		c = getchar();
		if (c < '0' || '9' < c) break;
		x = x * 10 + c - '0';
	}
} 

int main() {
	freopen("FENCE.inp", "r", stdin);
	freopen("FENCE.ans", "w", stdout);
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++ i) {
		getInt(a[i]);
		while (!q.empty() && a[q.back()] >= a[i])
			q.pop_back();
		if (!q.empty() && q.front() <= i - x) q.pop_front();
		q.push_back(i);
		f[i] = a[q.front()];
	}
	for (int i = x; i <= n; ++ i) {
		for (int j = i - x + 1; j <= i; ++ j) {
			b[j] = max(b[j], f[i]);
		}
	}
	for (int i = 1; i <= n; ++ i) res += a[i] - b[i];
	printf("%lld\n", res);
}