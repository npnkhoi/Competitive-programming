#include <bits/stdc++.h>
using namespace std;

vector<int> v;
string str;
int n, k;

int main() {
	int tc;
	cin >> tc;
	while (tc --) {
		cin >> n >> k >> str;
		int consec_lose = 0, score = 0, spare_lose = 0;
		v.clear();

		bool hasWin = false;

		for (int i = 0; i < n; ++ i) {
			char pre = (i == 0 ? 'L' : str[i-1]);
			if (str[i] == 'W') {
				if (consec_lose > 0) {
					if (!hasWin) {
						spare_lose += consec_lose;
					} else {
						v.push_back(consec_lose);
					}
					consec_lose = 0;
				}
				hasWin = true;
				score += 1 + (pre == 'W');
			} else {
				consec_lose ++;
			}
		}
		// printf("first sum: %d\n", score);
		if (consec_lose > 0) {
			spare_lose += consec_lose;
		}
		sort(v.begin(), v.end());
		for (int x : v) {
			if (x <= k) {
				score += 1 + 2 * x;
				k -= x;
			} else {
				score += 2 * k;
				k = 0;
				break;
			}
		}
		// printf("second sum: %d\n", score);
		if (k > 0) {
			score += 2 * min(k, spare_lose) - (!hasWin);
		}
		cout << score << '\n';
	}
}