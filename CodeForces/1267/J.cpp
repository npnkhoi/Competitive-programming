#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int tc, n;
int cnt[N];
vector<int> val;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	while (tc --) {
		// reset
		val.clear();

		// input
		cin >> n;
		int number;
		for (int i = 1; i <= n; ++ i) {
			cin >> number;
			if (cnt[number] == 0) {
				val.push_back(number);
			}
			cnt[number] ++;
		}

		// init
		int size = val.size();
		for (int i = 0; i < size; ++i) {
			int tmp = val[i];
			val[i] = cnt[val[i]];
			cnt[tmp] = 0;
		}
		sort(val.begin(), val.end());
		// cerr << "val: ";
		// for (int x : val) cerr << x << ' ';
		// cerr << '\n';

		// solve
		int res = 1e9 + 7;
		for (int s = val[0]; s >= 1; -- s) {
			int res_tmp = 0;
			int ok = true;
			for (int x : val) {
				if (x/s < x%s) ok = false;
			}
			if (ok) {
				// output
				int res = 0;
				for (int x : val) {
					res += x/(s+1) + (x%(s+1) != 0);
				}
				cout << res << '\n';
				break;
			}
		}

	}
}