#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> base = {
	{},
	{},
	{},
	{0.3333333333, 0.5, 1.0, 1.0},
	{0.25, 0.5, 1.0, 1.0}
};

int tc, k;
long long n;
double res;

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%lld%d", &n, &k);
		if (n == 1) res = 1.0;
		else if (n == 2) res = 0.5;
		else {
			while (n > 4 && k > 0) {
				if (n % 4 == 0) {
					n = n / 2;
				} else if (n % 2 == 0) {
					n = n / 2 + 1;
				} else {
					n = (n + 1) / 2;
				}
				k --;
			}
			if (k == 0) res = 1.0 / n;
			else if (k < 4) res = base[n][k];
			else res = 1.0;
		}
		printf("%.10lf\n", res);
	}
}