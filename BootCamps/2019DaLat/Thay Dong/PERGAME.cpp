#include <bits/stdc++.h>
using namespace std;

const int N = 170;
const int oo = 1e9 + 7;

int n, a[N], b[N], res;

void calc() {
	for (int i = 1; i <= n; ++ i) b[i] = a[i];
	int tmp1 = 0, tmp2 = 0;
	if (b[1] != n / 2) {
		tmp1 ++;
		for (int i = 2; i <= n; ++ i) {
			if (b[i] == n / 2) {
				swap(b[1], b[i]);
				break;
			}
		}
	}
	if (b[n] != n / 2 + 1) {
		tmp1 ++;
		for (int i = 2; i < n; ++ i) {
			if (b[i] == n / 2 + 1) {
				swap(b[i], b[n]);
				break;
			}
		}
	}
	// cerr << tmp << "\n";
	// for (int i = 1; i <= n; ++i) cerr << b[i] << " ";
		// cerr << "\n";
	for (int i = 2; i < n; ++ i) {
		// cerr << i << " here\n";
		// cerr << (b[i] > n / 2) << " " << (i % 2 == 0) << "\n";
		if ((b[i] > n / 2) ^ (i % 2 == 0)) tmp2 ++;
	}
	res = min(res, tmp1 + tmp2 / 2);
	// cerr << "done case 1\n";
}

int main() {
	freopen("PERGAME.inp", "r", stdin);
	freopen("PERGAME.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	res = oo;
	calc();
	for (int i = 1; i <= n / 2; ++ i) {
		swap(a[i], a[n-i+1]);
	}
	calc();
	printf("%d\n", res);
}