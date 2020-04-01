#include <bits/stdc++.h>
using namespace std;

int main() {
	int l = 1, r = 1e6;
	string ans;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		printf("%d\n", mid);
		fflush(stdout);
		getline(cin, ans);
		if (ans == "<") {
			r = mid - 1;
		} else {
			l = mid;
		}
	}
	printf("! %d\n", l);
	fflush(stdout);
}