#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
	int tc;
	cin >> tc;
	while (tc --) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++ i) {
			cin >> a[i];
		}
		sort(a, a + n);
		for (int i = n - 1; i >= 0; -- i) {
			if ((i == n - 1) || (a[i] <= a[i + 1] - 2)) {
				a[i] ++;
			}
		}
		int res = n;
		for (int i = 0; i < n - 1; ++ i) {
			res -= (a[i] == a[i + 1]);
		}
		cout << res << '\n';
	}
}