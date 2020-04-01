#include <bits/stdc++.h>
using namespace std;

// 1 2 3 5
const int cnt[]  = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3};
const int ways[] = {1, 1, 1, 1, 2, 1, 2, 1, 1, 3};
// 4: 3 1, 2 2
// 6: 5 1, 3 3
// 7: 5 2
// 8: 5 3
// 9: 5 3 1, 5 2 2, 3 3 3

int tc, c;
char num[22];


int main() {
	freopen("atm.inp", "r", stdin);
	freopen("atm.out", "w", stdout);
	scanf("%d", &tc);
	while (tc --) {
		scanf(" %s %d", num, &c);
		int l = strlen(num) - 3;
		// cerr << num << " " << c << "\n";5

		if (num[l] != '0' || num[l+1] != '0' || num[l+2] != '0') {
			printf("0\n");
			continue;
		}
		
		long long s = 1, n = 0, tmp = 2;
		for (int i = 0; i < l; ++ i) {
			if (i <= c) {
				s *= ways[num[l - i - 1] - '0'];
				n += cnt[num[l - i - 1] - '0'];
				// cerr << "digit " << num[l - i - 1] - '0' << "\n";
			} else {
				n += (num[l - i - 1] - '0') * tmp;
				tmp *= 10;
			}
		}
		printf("%lld %lld\n", n, s);
	}
}