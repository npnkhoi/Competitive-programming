#include <bits/stdc++.h>
using namespace std;

const int DIGIT = 20;
const long long md = 998244353;

long long l, r;
long long f[DIGIT][2], res, s[DIGIT][2];
int k;

bool inSet(int ch, int s) {
	return s & (1 << (ch));
}

string toString(long long n) {
	if (n == 0) return "0";
	else return toString(n / 10) + (char) (n % 10 + '0');
}

long long calc(long long num) {
	if (num < 10) {
		return num;
	}

	string s = toString(num);
	int n = s.size() - 1;

	cerr << "calc " << s << " " << n << "\n";

	long long res = 0;

	for (int mask = 1; mask < (1 << 10); ++ mask) {
		if (__builtin_popcount(mask) != k) continue;

		cerr << "mask: ";
		for (int i = 0; i < 10; ++ i) if (inSet(i, mask)) cerr << i << " ";
		cerr << "\n";

		int nonzero = __builtin_popcount(mask) - inSet(0, mask);

		f[1][0] = 0;
		for (int d = 1; d < s[1] - '0'; ++ d) {
			f[1][0] += inSet(d, mask);
		}
		f[1][1] = inSet(s[1] - '0', mask);

		cerr << f[1][0] << " " << f[1][1] << "\n";

		for (int i = 2; i <= n; ++ i) {
			f[i][1] = f[i - 1][1] && inSet(s[i] - '0', mask);

			f[i][0] = nonzero;
			for (int d = 0; d <= 9; ++ d) {
				if (inSet(d, mask)) f[i][0] += f[i - 1][0];
			}
			for (int d = 0; d < s[i] - '0'; ++ d) {
				if (inSet(d, mask)) f[i][0] += f[i - 1][1];
			}
			cerr << f[i][0] << " " << f[i][1] << "\n";
		}
		// if ((k - __builtin_popcount(mask)) % 2)
		// 	res -= f[n][0] + f[n][1];
		// else 
			res += f[n][0] + f[n][1];
	}
	return res / k;
}

int main() {
	scanf("%lld %lld %d", &l, &r, &k);
	cerr << calc(r) << "\n";
	cerr << calc(l - 1) << "\n";
	// printf("%lld", calc(r) - calc(l - 1));
}