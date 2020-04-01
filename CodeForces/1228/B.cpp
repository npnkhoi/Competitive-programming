#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, md = 1e9 + 7;

int h, w;
int a[N][N];

void assign(int i, int j, int val) {
	if (a[i][j] == -1 || a[i][j] == val) {
		a[i][j] = val;
	} else {
		printf("0");
		exit(0);
	}
}

int main() {
	scanf("%d%d", &h, &w);
	memset(a, -1, sizeof a);
	for (int i = 1; i <= h; ++ i) {
		int x;
		scanf("%d", &x);
		for (int j = 1; j <= x; ++ j) {
			assign(i, j, 1);
		}
		if (x < w) {
			assign(i, x + 1, 0);
		}
	}
	for (int j = 1; j <= w; ++ j) {
		int x;
		scanf("%d", &x);
		for (int i = 1; i <= x; ++ i) {
			assign(i, j, 1);
		}
		if (x < h) {
			assign(x + 1, j, 0);
		}
	}
	int res = 1;
	for (int i = 1; i <= h; ++ i) {
		for (int j = 1; j <= w; ++ j) {
			if (a[i][j] == -1) {
				res = (res + res);
				if (res >= md) res -= md;
			}
		}
	}
	printf("%d", res);
}