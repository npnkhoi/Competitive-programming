#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k, a[N];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	a[0] = 0;
	long long rem = 0;
	long long result = 0;
	for (int i = 1; i <= n; ++ i) {
		int width = i - 1;
		int height = a[i] - a[i-1];
		if (rem < width) {
			rem = 0;
			break;
		}
		if (width - k <= 0) {
			result += height;
			rem += 1LL * height * (k - width);
		} else {
			long long can_del = (rem - width) / (width - k) + 1;
			if (can_del < height) {
				result += can_del;
				rem = 0;
				break;
			} else {
				result += height;
				rem -= height * (width - k);
			}
		}
	}
	if (rem >= n) result += (rem - n) / (n - k) + 1;
	cout << result;
}