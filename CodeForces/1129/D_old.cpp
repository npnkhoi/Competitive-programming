#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, MOD = 998244353;

int n, k, a[N], cnt[N], ways[N], waysPrefix[N];

int main() {
	scanf("%d%d", &n, &k);
	int leftmost = 0, cntUnique = 0;
	
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
		cnt[a[i]] ++;
		if (cnt[a[i]] == 1) {
			cntUnique ++;
			while (cntUnique > k) {
				cnt[a[leftmost]] --;
				if (cnt[a[leftmost]] == 0) {
					cntUnique --;
				}
				leftmost ++;
			}
		}
		// get sum of ways from leftmost to i-1
		if (i == 0) {
			ways[i] = waysPrefix[i] = 1;
		} else {
			ways[i] = (waysPrefix[i-1] - 
				(leftmost == 0 ? -1 : ways[leftmost - 1]) + MOD) % MOD;
			waysPrefix[i] = (waysPrefix[i-1] + ways[i]) % MOD;
		}
		cerr << ways[i] << '\n';
	}
	printf("%d", ways[n-1]);
}