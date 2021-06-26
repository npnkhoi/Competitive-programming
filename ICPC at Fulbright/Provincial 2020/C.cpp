#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long num) {
	if (num <= 1) return false;
	if (num <= 3) return true;
	if (num % 2 == 0 || num % 3 == 0) return false;


	for (long long i = 5; i <= sqrt(num); i += 6) {
		if (num % i == 0) return false;
		if ((i + 2) <= sqrt(num) && num % (i + 2) == 0) return false;
	}
	return true;
}

long long rev(long long num) {
	int rev_dig[] = {0, 1, 2, -1, -1, 5, 9, -1, 8, 6};
	long long res = 0;
	while (num > 0) {
		int dig = num % 10;
		num /= 10;
		if (rev_dig[dig] == -1) {
			return 0;
		}
		res = res * 10 + rev_dig[dig];
	}
	return res;
}

int main() {
	// for (int i = 1; i <= 100; i ++) {
	// 	cerr << i << ' ' << is_prime(i) << '\n';
	// }
	long long n;
	cin >> n;
	if (is_prime(n) and is_prime(rev(n)))
		cout << "yes";
	else
		cout << "no";
}