#include <bits/stdc++.h>
using namespace std;

// const long long BASE1 = 1e5;
// const long long BASE2 = 1e10;

// struct Big {
// 	long long a, b, c;
// 	Big() {a = b = c = 0;}

// 	Big operator + (const Big &oth) {
// 		c += oth.c;
// 		b += oth.b;
// 		a += oth.a;

// 		b += c / BASE;
// 		c %= BASE;
// 		a += b / BASE;
// 		b %= BASE;
// 		a %= BASE;

// 		return a;
// 	}
// 	Big operator * (const Big &oth) {
// 		Big res;
// 		res.a = a * oth.c + b * oth.b + c * oth.a;
// 		res.b = b * oth.c + c * oth.b;
// 		res.c = c * oth.c;

// 		res.b += res.c / BASE;
// 		res.c %= BASE;
// 		res.a += res.b / BASE;
// 		res.b %= BASE;
// 		res.a %= BASE;

// 		return res;
// 	}
// };

const int N = 1e3 + 5;
const long long md = 1e15;

int k;
vector<int> types;
long long f[N], res;

long long mul(long long a, long long b) {
	if (a == 0 || b == 0) return 0;
	long long res = mul(a / 2, 2 * b % md);
	if (a % 2) res = (res + b) % md;
	return res;
}

int main() {
	freopen("TILES.inp", "r", stdin);
	freopen("TILES.out", "w", stdout);
	scanf("%d", &k);
	int u;
	for (int i = 1; i <= 5; ++ i) {
		scanf("%d", &u);
		if (u == 1) types.push_back(i);
	}
	f[0] = 1;
	for (int i = 1; i <= k; ++ i) {
		f[i] = 0;
		for (int x : types) {
			if (x == 1) {
				// res = res + f[i-1] * f[i-1];
				f[i] = (f[i] + mul(f[i-1], f[i-1])) % md;
			} else if (x == 2 && i >= 2) {
				// res = res + f[i-2] * f[i-2] * f[i-2] * f[i-2];
				f[i] = (f[i] + mul(mul(f[i-2], f[i-2]), mul(f[i-2], f[i-2]))) % md;
			} else if (x == 3 && i >= 4) {
				// res = res + f[i-1] * f[i-2] * f[i-3];
				f[i] = (f[i] + mul(mul(mul(f[i-1], f[i-2]), mul(f[i-3], f[i-4])), f[i-4])) % md;
			} else if (x == 4 && i >= 4) {
				f[i] = (f[i] + mul(mul(mul(f[i-1], f[i-2]), mul(f[i-3], f[i-4])), f[i-4])) % md;
			} else if (x == 5) {
				f[i] = (f[i] + mul(mul(f[i-2], mul(f[i-3], f[i-3])), mul(f[i-2], mul(f[i-3], f[i-3])))) % md;
			}
		}
	}
	printf("%lld", f[k]);
}