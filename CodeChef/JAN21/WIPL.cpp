#include <bits/stdc++.h>
using namespace std;

const int SUM = 8005, N = 4005;

int mark[SUM];
int h[N];

int main() {
	int tc;
	cin >> tc;
	while (tc --) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; ++ i) {
			cin >> h[i];
		}

		// Trivial cases
		if (n == 1) {
			cout << "-1\n";
			continue;
		}

		sort(h, h + n, greater<int>());
		
		// Trivial cases
		if (h[1] >= k) {
			cout << "2\n";
			continue;
		}

		if (h[0] >= k) {
			int sum = 0;
			for (int i = 1; i < n; ++ i) {
				sum += h[i];
				if (sum >= k) {
					cout << i + 1 << '\n';
					break;
				}
			}
			if (sum < k) {
				cout << "-1\n";
			}
			continue;
		}

		// DP
		memset(mark, 0, sizeof mark);
		mark[0] = 1;
		vector<int> possible_sum = {0};
		int total = 0, best_sum = 1e9, res = -1;
		for (int i = 0; i < n; ++ i) {
			int cnt = possible_sum.size();
			
			total += h[i];
			
			for (int j = 0; j < cnt; ++ j) {
				if (possible_sum[j] >= k) continue;
				int new_val = possible_sum[j] + h[i];
				if (!mark[new_val]) {
					mark[new_val] = 1;
					possible_sum.push_back(new_val);
					// printf("new value: %d\n", new_val);
					if (new_val >= k) {
						best_sum = min(best_sum, new_val);
					}
				}
			}

			if (total - best_sum >= k) {
				res = i + 1;
				break;
			}
		}
		cout << res << '\n';
	}
}