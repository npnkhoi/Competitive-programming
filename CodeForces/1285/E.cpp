#include <bits/stdc++.h>
using namespace std;

const int N = 8e5 + 5;

int tc, n, a[N], one[N], l[N], r[N];

int pos(int val, vector<int> &vec) {
	return lower_bound(vec.begin(), vec.end(), val) - vec.begin();
}

int main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	cin >> tc;
	while (tc --) {
		// input
		cin >> n;
		vector<int> id;
		for (int i = 0; i < n; ++ i) {
		 cin >> l[i] >> r[i];
		 l[i] = l[i] * 2;
		 r[i] = r[i] * 2;
		 id.push_back(l[i]);
		 id.push_back(r[i]);
		 id.push_back(l[i] - 1);
		 id.push_back(r[i] + 1);
		}
		// corner case:
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		// compress coor
		sort(id.begin(), id.end());
		id.resize(unique(id.begin(), id.end()) - id.begin());
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; ++ i) {
			l[i] = pos(l[i], id);
			r[i] = pos(r[i], id);
			a[l[i]] ++;
			a[r[i] + 1] --;
		}
		// count 0's and 1's segments
		int len = id.size();
		int cnt0 = 0, cnt1 = 0;
		bool inOne = 0;
		for (int i = 1; i < len; ++ i) {
			a[i] += a[i - 1];
			if (a[i - 1] != 0 && a[i] == 0) cnt0 ++;
			if (inOne) {
				if (a[i] != 1) {
					inOne = 0;
					if (a[i] > 1) cnt1 ++;
				}
			} else if (a[i - 1] > 1 && a[i] == 1) {
				inOne = 1;
			}
			one[i] = cnt1;
		}
		// final cal
		int res = -1;
		for (int i = 0; i < n; ++ i) {
			res = max(res, one[r[i]] - (l[i] == 0 ? 0 : one[l[i] - 1]) - (a[r[i] + 1] == 0 && a[r[i]] == 1));
		}
		res += cnt0;
		// printf("cnt0 = %d\n", cnt0);
		cout << res << '\n';
	}
}