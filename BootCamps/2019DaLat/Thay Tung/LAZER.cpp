#include <bits/stdc++.h>
using namespace std;

const int MAX_COOR = 1e5;
const int sh = 1e5;

int n, q;
int d[5];
int change1[MAX_COOR + 5], change2[2 * MAX_COOR + 5], change3[2 * MAX_COOR + 5];
int delta2[2 * MAX_COOR + 5], delta3[2 * MAX_COOR + 5];
int len1[MAX_COOR + 5], len2[2 * MAX_COOR + 5], len3[2 * MAX_COOR + 5];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

		change1[x1] += y2 - y1;
		change1[x2 + 1] -= y2 - y1;

		d[1] = x1 + y1;
		d[2] = x1 + y2;
		d[3] = x2 + y1;
		d[4] = x2 + y2;
		sort(d + 1, d + 5);
		delta2[d[1] + 1] ++;
		delta2[d[2] + 1] --;
		delta2[d[3] + 1] --;
		delta2[d[4] + 1] ++; 

		d[1] = x1 - y1;
		d[2] = x1 - y2;
		d[3] = x2 - y1;
		d[4] = x2 - y2;
		sort(d + 1, d + 5);
		delta3[sh + d[1] + 1] ++;
		delta3[sh + d[2] + 1] --;
		delta3[sh + d[3] + 1] --;
		delta3[sh + d[4] + 1] ++; 
	}
	for (int i = 1; i <= MAX_COOR; ++i) {
		len1[i] = len1[i-1] + change1[i];
	}

	for (int i = 2; i <= 2 * MAX_COOR; ++ i) {
		change2[i] = change2[i - 1] + delta2[i];
		len2[i] = len2[i - 1] + change2[i];
	}

	for (int i = 1 - MAX_COOR; i <= MAX_COOR - 1; ++ i) {
		change3[sh + i] = change3[sh + i - 1] + delta3[sh + i];
		len3[sh + i] = len3[sh + i - 1] + change3[sh + i];
	}

	scanf("%d", &q);
	while (q --) {
		int x, d;
		scanf("%d%d", &x, &d);
		if (d == 1) {
			if (1 <= x && x <= MAX_COOR) 
				printf("%lld\n", 1LL * len1[x] * len1[x]);
			else printf("0\n");
		} else if (d == 2) {
			if (2 <= x  && x <= 2 * MAX_COOR) 
				printf("%lld\n", 2LL * len2[x] * len2[x]);
			else printf("0\n");
		} else if (d == 3) {
			if (1 - MAX_COOR <= x && x <= MAX_COOR - 1) 
				printf("%lld\n", 2LL * len3[sh + x] * len3[sh + x]);
			else printf("0\n");
		}
	}
}