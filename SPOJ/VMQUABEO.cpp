#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, l, d, h[N], f[N];
long long res;
deque<int> stepDown, stepUp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// scanf("%d%d%d", &n, &l, &d);
	cin >> n >> l >> d;
	f[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		// scanf("%d", &h[i]);
		cin >> h[i];
		while (!stepDown.empty() && h[stepDown.back()] > h[i]) {
			stepDown.pop_back();
		}
		stepDown.push_back(i);
		while (!stepUp.empty() && h[stepUp.back()] < h[i]) {
			stepUp.pop_back();
		}
		stepUp.push_back(i);

		f[i] = f[i-1];
		while (h[stepUp.front()] - h[stepDown.front()] > d) {
			if (stepUp.front() == f[i]) {
				stepUp.pop_front();
			}
			if (stepDown.front() == f[i]) {
				stepDown.pop_front();
			}
			++ f[i];
			if (f[i] > i) break;
		}
		res += max(0, i - f[i] + 1 - l);
	}
	// printf("%lld\n", res);
	cout << res << "\n";
}