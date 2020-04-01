#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int m, k, a[N], buy[N];
long long res;
deque<int> q;

int main() {
	// freopen("FOOD.inp", "r", stdin);
	// freopen("FOOD.out", "w", stdout);
	scanf("%d%d", &m, &k);
	for (int i = 1; i <= m; ++ i) {
		scanf("%d", &a[i]);
		while (!q.empty() && a[q.back()] >= a[i]) q.pop_back();
		if (!q.empty() && q.front() <= i - k) q.pop_front();
		q.push_back(i);
		// cerr << 
		buy[q.front()] += 2;
		res += a[q.front()] * 2;
	}
	printf("%lld\n", res);
	for (int i = 1; i <= m; ++ i) printf("%d ", buy[i]);
}