#include <bits/stdc++.h>
using namespace std;

int tc, n, m, sum[2];
vector<pair<int, int>> voting_packs;

int main() {
	cin >> tc;
	while (tc --) {
		sum[0] = sum[1] = 0;
		voting_packs.clear();

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n + m; ++ i) {
			int x;
			cin >> x;
			voting_packs.push_back({x, i >= n});
			sum[i >= n] += x;
		}
		sort(voting_packs.begin(), voting_packs.end());
		int l = 0, r = m + n - 1, res = 0;
		while (sum[0] <= sum[1]) {
			while (voting_packs[l].second != 0 && l < n + m) l ++;
			while (voting_packs[r].second != 1 && r >= 0) r --;
			if (l >= r) break;
			sum[0] += voting_packs[r].first - voting_packs[l].first;
			sum[1] -= voting_packs[r].first - voting_packs[l].first;
			l ++;
			r --;
			res ++;
		}
		if (sum[0] <= sum[1]) {
			cout << "-1\n";
		} else {
			cout << res << '\n';
		}
	}
}