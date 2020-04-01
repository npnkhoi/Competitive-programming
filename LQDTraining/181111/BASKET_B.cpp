#include <bits/stdc++.h>
using namespace std;
#define task "BASKET_B"
const int TOTAL = 48 * 60;

int n, timer, res[3], score[3];
string s;

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d ", &n);
	timer = 0;
	for (int i = 1; i <= n; ++ i) {
		getline(cin, s);
		int t = (s[2] - '0') * 600 + (s[3] - '0') * 60 + (s[5] - '0') * 10 + (s[6] - '0');
		
		if (score[1] > score[2]) {
			res[1] += t - timer;
		} else if (score[2] > score[1]) {
			res[2] += t - timer;
		}

		score[s[0] - '0'] ++;
		timer = t;
	}
	if (score[1] > score[2]) {
			res[1] += TOTAL - timer;
		} else if (score[2] > score[1]) {
			res[2] += TOTAL - timer;
		}

	printf("%02d:%02d\n", res[1] / 60, res[1] % 60);
	printf("%02d:%02d\n", res[2] / 60, res[2] % 60);
}