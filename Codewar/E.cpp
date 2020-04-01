vector<int> prime_list;

void init() {
	vector<bool> prime(10005, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i < prime.size(); ++ i) {
		if (prime[i]) {
			prime_list.push_back(i);
			for (long long j = 1LL * i * i; j < prime.size(); j += i) {
				prime[j] = false;
			}
		}
	}
}

bool check(int num) {
	for (int x : prime_list) {
		if (1LL * x * x > num) break;
		if (num % x == 0) return false;
	}
	return true;
}

int findTheLargestPrime(std::vector<int> digits) {
	init();
	sort(digits.begin(), digits.end());
	int res = -1;
	do {
		int num = 0;
		for (int i = 0; i < digits.size(); ++ i) {
			num = num * 10 + digits[i];
			if (check(num)) {
				res = max(res, num);
			}
		}
	} while (next_permutation(digits.begin(), digits.end()));
	return res;
}