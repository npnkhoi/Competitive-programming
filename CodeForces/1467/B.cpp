#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int tc, n, a[N], mark[N];

int getSign(int x) {
	if (x < 0) return -1;
	if (x > 0) return 1;
	return 0;
}

bool isPeak(int i) {
	if (i == 0 || i == n - 1) return false;
	return getSign(a[i] - a[i - 1]) * getSign(a[i + 1] - a[i]) < 0;
}

int localScore(int i) {
	return isPeak(i - 1) + isPeak(i) + isPeak(i + 1);
}

int main() {
	cin >> tc;
	while (tc --) {
		cin >> n;
		for (int i = 0; i < n; ++ i) {
			cin >> a[i];
		}
		if (n <= 2) {
			cout << "0\n";
			continue;
		}
		int init_intimidation = 0;

		for (int i = 1; i < n - 1; ++ i) {
			mark[i] = isPeak(i);
			init_intimidation += mark[i]; 
		}

		int res = init_intimidation;

		for (int i = 1; i < n - 1; ++ i) {
			int tmp = a[i];
			int old_score = localScore(i);
			a[i] = a[i - 1];
			res = min(res, init_intimidation - old_score + localScore(i));
			a[i] = a[i + 1];
			res = min(res, init_intimidation - old_score + localScore(i));
			a[i] = tmp;
		}
		res = min(res, init_intimidation - mark[1]);
		res = min(res, init_intimidation - mark[n - 2]);
		cout << res << '\n';
	}
}