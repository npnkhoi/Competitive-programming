#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, k;
long long dp[N], s[N];
deque<int> q;

long long val(int i) {
	if (i == -1) return 0;
	return dp[i - 1] - s[i];
}

int main() {
	scanf("%d%d", &n, &k);
	int x;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &x);
		s[i] = s[i - 1] + x;
	}
	q.push_back(0);
	for (int i = 1; i <= n; ++ i) {
		while (!q.empty() && val(q.back()) < val(i)) q.pop_back();
		if (!q.empty() && q.front() <= i - k) q.pop_front();
		q.push_back(i);
		dp[i] = s[i] + val(q.front());
	}
	printf("%lld\n", dp[n]);
}