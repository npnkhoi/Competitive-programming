#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n, tc;
int mark[3][N];
char a[3][N];
int cnt;

void trace(int x, int y) {
	cnt = 1;
	mark[x][y] = 1;
	while (1) {
		if (mark[3 - x][y] == 0 && a[3 - x][y] == '#') {
			x = 3 - x;
			cnt ++;
			mark[x][y] = 1;
		} else if (y < n && a[x][y + 1] == '#') {
			y += 1;
			cnt ++;
			mark[x][y] = 1;
		} else {
			break;
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		int lenSnack = 0;
		for (int i = 1; i <= 2; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				scanf(" %c", &a[i][j]);
				lenSnack += (a[i][j] == '#');
			}
		}
		int firstCol;
		for (int j = 1; j <= n; ++ j) {
			if (a[1][j] == '#' || a[2][j] == '#') {
				firstCol = j;
				break;
			}	
		}
		if (a[1][firstCol] == '#') {
			cnt = 0;
			memset(mark, 0, sizeof mark);
			trace(1, firstCol);
			if (cnt == lenSnack) {
				printf("yes\n");
				continue;
			}
		}
		if (a[2][firstCol] == '#') {
			cnt = 0;
			memset(mark, 0, sizeof mark);
			trace(2, firstCol);
			if (cnt == lenSnack) {
				printf("yes\n");
				continue;
			}
		}
		printf("no\n");
	}
}