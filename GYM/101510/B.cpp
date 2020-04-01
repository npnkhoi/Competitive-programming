#include <bits/stdc++.h>
using namespace std;

int A, B;
int a[6], b[6], rnks[6], cnt[6], ans[10];
int mark[25][4];

void check() {
	// cerr << "check\n";
	for (int i = 1; i <= 5; ++i) {
		rnks[i] = a[i];
	}
	sort(rnks + 1, rnks + 6);
	for (int i = 1; i <= 5; ++i) {
		// cerr << rnks[i] << "\n";
	}
	memset(cnt, 0, sizeof cnt);
	int p = 0, tmp = 0;
	for (int i = 1; i <= 5; ++i) {
		++ tmp;
		if (i == 5 || rnks[i] != rnks[i + 1]) {
			cnt[tmp] ++;
			tmp = 0;
		}
	}

	bool isStraight = 0;
	bool isFlush = 0;

	bool ok = 1;
	for (int i = 1; i <= 4; ++i) {
		if (b[i] != b[i + 1]) {
			ok = 0;
			break;
		}
	}
	if (ok) isFlush = 1;

	ok = 1;
	for (int i = 1; i <= 4; ++i) {
		if (rnks[i] != rnks[i + 1] - 1) {
			ok = 0;
			break;
		}
	}
	if (ok) {
		isStraight = 1;
	}


	if (isFlush && isStraight) {
		ans[1] ++;
	} else if (cnt[4] || cnt[5]) {
		ans[2] ++;
	} else if ((cnt[3] > 0 && cnt[2] > 0) || (cnt[5] > 0)) {
		ans[3] ++;
		// for (int i = 1; i <= 5; ++i) {
		// 	cerr << a[i] << " " << b[i] << "\n";
		// }
		// cerr << "-------\n";
	} else if (isFlush) {
		ans[4] ++;
	} else if (isStraight) {
		ans[5] ++;
	} else if (cnt[3] > 0 || cnt[4] > 0 || cnt[5] > 0) {
		ans[6] ++;
	} else if (cnt[1] <= 1) {
		ans[7] ++;
	} else if (cnt[1] != 5) {
		ans[8]  ++;
	} else {
		ans[9] ++;
	}
}

void backTrack(int i) {
	for (int rnk = 0; rnk < A; ++ rnk) {
		for (int suit = 0; suit < B; ++ suit) {
			if (!mark[rnk][suit]) {
				a[i] = rnk;
				b[i] = suit;
				mark[rnk][suit] = 1;

				if (i == 5) {
					check();
				} else {
					backTrack(i + 1);
				}
				mark[rnk][suit] = 0;
			}
			
		}
	}
}

int main() {
	// a[1] = 0;
	// a[2] = 1;
	// a[3] = 2;
	// a[4] = 3;
	// a[5] = 4;
	// check();
	// cerr << ans[1] << "\n";

	scanf("%d%d", &A, &B);
	scanf("%d%d%d%d", &a[1], &b[1], &a[2], &b[2]);
	mark[a[1]][b[1]] = mark[a[2]][b[2]] = 1;
	backTrack(3);
	for (int i = 1; i <= 9; ++i) {
		printf("%d ", ans[i] / 6);
	}
}