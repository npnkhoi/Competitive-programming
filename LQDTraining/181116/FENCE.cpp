#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, x, a[N], f[N], h[N], roll;
long long s[N], sweep;
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
	freopen("FENCE.out", "w", stdout);
	scanf("%d%d", &n, &x);
	// cerr << n << " " << x << "\n";
	for (int i = 1; i <= n; ++ i) {
		getInt(a[i]);
		s[i] = s[i - 1] + a[i];
		while (!q.empty() && a[q.back()] >= a[i])
			q.pop_back();
		if (!q.empty() && q.front() <= i - x) q.pop_front();
		q.push_back(i);
		f[i] = a[q.front()];
	}

	while (!q.empty()) q.pop_back();
	for (int i = x; i <= n; ++ i) {
		while (!q.empty() && f[q.back()] <= f[i])
			q.pop_back();
		if (!q.empty() && q.front() <= i - x) q.pop_front();
		q.push_back(i);
		h[i - x + 1] = f[q.front()];
		sweep += a[i - x + 1] - h[i - x + 1];
	}
	for (int i = n - x + 2; i <= n; ++ i) {
		if (q.front() < i) q.pop_front();
		h[i] = f[q.front()];
		sweep += a[i] - h[i];
	}
	if (x == 1) roll = n;
	else {
		int cnt = 1;
		for (int i = 2; i <= n; ++ i) {
			if (h[i] != h[i - 1]) {
				roll += max((cnt + x - 3) / (x - 1), 1);
				cnt = 1;
			} else cnt ++;
		}
		roll += max((cnt + x - 3) / (x - 1), 1);
	}
	// cerr << sweep << "\n";
	printf("%lld\n%d\n", sweep, roll);

	// int last = n + x;
	// sweep = s[n];
	// for (int i = n; i >= x; -- i) {
	// 	if (i <= last - x) {
	// 		roll ++;
	// 		sweep -= 1LL * x * f[i];
	// 		last = i;
	// 	} else if (f[i] > f[last]) {
	// 		roll ++;
	// 		sweep -= 1LL * f[i] * (last - i) + 1LL * (f[i] - f[last]) * (i - (last - x)); 
	// 		last = i;
	// 	}
	// }
	// if (last > x) {
	// 	// cerr << "here\n";
	// 	roll ++;
	// 	sweep -= 1LL * (last - x) * f[x];
	// }
	// printf("%lld\n%d\n", sweep, roll);
	// printf("%lld\n", sweep);
}