#include <bits/stdc++.h>
using namespace std;

const int T = 3e6 + 5;
const int MAX_T = 3e6;
const int K = 5;

int n, k;
int f[T][K], res;
vector<int> head[T];

void read(int &x) {
	int c;
	do c = getchar(); while (c < '0' || '9' < c);
	x = c - '0';
	while (1) {
		c = getchar();
		if (c < '0' || '9' < c) break;
		x = x * 10 + c - '0';
	}
}

int main() {
	// freopen("MACHINE3.inp", "r", stdin);
	// freopen("MACHINE3.out", "w", stdout);
	// scanf("%d%d", &n, &k);
	read(n); read(k);
	for (int i = 1; i <= n; ++ i) {
		int l, r;
		// scanf("%d%d", &l, &r);
		read(l); read(r);		
		head[r].push_back(l);
	}
	for (int r = 1; r <= MAX_T; ++ r) {
		for (int l : head[r]) {
			f[r][1] = max(f[r][1], f[l - 1][0] + r - l);
			if (f[l - 1][1] > 0) f[r][2] = max(f[r][2], f[l - 1][1] + r - l);
			if (f[l - 1][2] > 0) f[r][3] = max(f[r][3], f[l - 1][2] + r - l);
		}
		f[r][1] = max(f[r][1], f[r - 1][1]);
		f[r][2] = max(f[r][2], f[r - 1][2]);
		f[r][3] = max(f[r][3], f[r - 1][3]);
		// if (r <= 21) cerr << f[r][1] << " " << f[r][2] << " " << f[r][3] << "\n";

		res = max(res, f[r][k]);
	}
	if (res == 0) printf("-1");
	else printf("%d", res);
}