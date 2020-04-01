#include <bits/stdc++.h>
using namespace std;

const int N = 22;
const int MASK = (1 << 20) + 2;
const double oo = 1e18;

struct Point{
	int x, y;
};

Point a[N];
int n, k;
double dp[MASK][N];

double dist(int i, int j) {
	return sqrt((double) (a[i].x - a[j].x) * (a[i].x - a[j].x) + (double) (a[i].y - a[j].y) * (a[i].y - a[j].y));
} 

void trace(int mask, int i) {
	// cerr << "trace " << mask << " " << i << "\n";
	cerr << a[i].x << " " << a[i].y << "\n";
	for (int j = 0; j < n; ++ j) {
		if ((mask & (1 << j)) && (j != i) && dp[mask ^ (1 << i)][j] + dist(i, j) == dp[mask][i]) {
			trace(mask ^ (1 << i), j);
			break;
		}
	}
}

int main() {
	freopen("KING.inp", "r", stdin);
	freopen("KING.ans", "w", stdout);
	scanf("%d%d", &n, &k);
	n ++; k --;
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i].x);
		a[i].y = 0;
	}
	scanf("%d", &a[n - 1].y);
	// for (int i = 0; i < n; ++ i) cerr << a[i].x << " " << a[i].y << "\n";
	// cerr << "start: " << a[k].x << " " << a[k].y << "\n";
	for (int mask = 1; mask < (1 << n); ++ mask) {
		if (__builtin_popcount(mask) == 1) continue;
		for (int i = 0; i < n; ++ i) if (mask & (1 << i)) {
			dp[mask][i] = oo;
			for (int j = 0; j < n; ++ j) if ((mask & (1 << j)) && (j != i))
				dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + dist(j, i));
				// cerr << mask << " " << i << " " << dp[mask][i] << "\n";
		}
	}
	printf("%.10lf", dp[(1 << n) - 1][k]);
	// trace((1 << n) - 1, k);
}