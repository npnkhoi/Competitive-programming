#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef unsigned long long ull;

const int N = 2e6 + 5;
const long long BASE1 = 1e7 + 19;
const long long BASE2 = 1e9 + 7;

char str[N];
pair<ull, ull> h[N], s[N];
int n, res;

bool check(int d) {
	for (int i = 2 * d; i <= n; i += d) {
		ull tmp1 = s[i].fi - s[i - d].fi;
		ull tmp2 = s[i].se - s[i - d].se;
		if (make_pair(tmp1, tmp2) != s[d]) return 0;
	}
	return 1;
}

int main() {
	freopen("BONNY.txt", "r", stdin);
	scanf("%s", str + 1);
	n = strlen(str + 1);
		
	h[0] = make_pair(1, 1);
	for (int i = 1; i < 26; ++ i) {
		h[i].fi = h[i - 1].fi * BASE1; 
		h[i].se = h[i - 1].se * BASE2; 
	}

	for (int i = 1; i <= n; ++ i) {
		s[i].fi = s[i - 1].fi + h[str[i] - 'a'].fi;
		s[i].se = s[i - 1].se + h[str[i] - 'a'].se;
	}

	for (int i = 1; i <= n; ++ i) {
		if (n % i == 0) {
			if (check(i)) res = max(res, n / i);
			if (check(n / i)) res = max(res, i);
		}
	}
	printf("%d\n", res);
	cerr << "Time = " << clock() / (double) 1000;
}