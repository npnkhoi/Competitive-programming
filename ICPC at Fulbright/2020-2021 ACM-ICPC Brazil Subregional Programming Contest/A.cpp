#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

double f[N], s[N], sum_ways[N];

double get_sum(double arr[], int l, int r) {
	if (l == 0) return arr[r];
	return arr[r] - arr[l - 1];
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	sum_ways[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		if (i < a) {
			f[i] = 0;
		} else {
			int l = max(0, i - b), r = i - a;
			if (a != 0) {
				cerr << get_sum(s, l, r) << ' ' << get_sum(sum_ways, l, r) << '\n';
				f[i] = get_sum(s, l, r) / get_sum(sum_ways, l, r) + 1;
			} else {
				if (get_sum(sum_ways, l, r) == 0) {
					f[i] = 0;
				} else {
					double ways = get_sum(sum_ways, l, r);
					f[i] = (get_sum(s, l, r) / ways + 1) / (1 - 1 / ways);
				}
			}
		}
		sum_ways[i] = sum_ways[i - 1] + (f[i] != 0);
		s[i] = s[i - 1] + f[i];
		cerr << f[i] << '\n';
	}
	cout << f[n];
}