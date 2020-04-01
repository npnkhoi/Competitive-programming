#include <bits/stdc++.h>
using namespace std;

const int N = 22;
const int MAX_M = 2e7;
const int sh = MAX_M + 1;

typedef vector<int> vi;

int n, m, a[N], s;
vi v1, v2;

void brute(int x, int y, vi &v) {
	if (x == y + 1) {
		v.push_back(s);
		return;
	}
	for (int i = -1; i <= 1; ++ i) {
		s += i * a[x];
		brute(x + 1, y, v);
		s -= i * a[x];
	}
}

int main() {
	// freopen("BALANCE.inp", "r", stdin);
	// freopen("BALANCE.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int p = n/2;

	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}

	s = 0;
	brute(1, p, v1);

	s = 0;
	brute(p + 1, n, v2);

	// sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	long long res = 0;
	for (int x : v1) {
		res += upper_bound(v2.begin(), v2.end(), x - m) - 
			lower_bound(v2.begin(), v2.end(), x - m);
		res += upper_bound(v2.begin(), v2.end(), x + m) - 
			lower_bound(v2.begin(), v2.end(), x + m);
	}
	printf("%lld", res / 2);
}