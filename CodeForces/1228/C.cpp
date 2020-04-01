#include <bits/stdc++.h>
using namespace std;

const long long md = 1e9 + 7;

vector<int> prime; // less than log2(1e9) elements
long long res = 1, n;
int x;

void factorize(int x) {
	// 2 <= x <= 10e9
	for (int i = 2; i * i <= x; ++ i) {
		if (x % i == 0) {
			prime.push_back(i);
			do {
				x /= i;
			} while (x % i == 0);
		}
	}
	if (x > 1) prime.push_back(x);
}

long long Exp(int a, long long n) {
	if (n == 0) return 1;
	long long res = Exp(a, n / 2);
	res = res * res % md;
	if (n % 2) res = res * a % md;
	return res;
}

void calc(long long n, int fact) {
	long long mul = fact;	
	long long cnt = 0;
	for (int i = 1; mul <= n; ++ i, mul *= 1LL * fact) {
		cnt += n / mul;
		if (cnt > md - 1) {
			cnt %= (md - 1);
			// cerr << "mod cnt\n";
		}
		if (n / fact + 1 < mul) break;
	}
	// res *= fact ^ cnt % md
	// res < md
	res = res * Exp(fact, cnt) % md;
} 

int main() {
	scanf("%d%lld", &x, &n);
	factorize(x);
	// cerr << "number of factors: " << prime.size() << '\n';
	for (int fact : prime) {
		// cerr << fact << '\n';
		calc(n, fact);
	}
	printf("%lld", res);
}