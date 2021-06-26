#include <bits/stdc++.h>
using namespace std;

const int N = 50;

int n, k;
long long f[N][N + 1], weight[N];

bitset<N> max_subset(long long limit) {
	// max subset that <= limit
	long long total = 0;
	bitset<N> res;
	for (int i = 0; i < n; ++ i) {
		if (total + weight[i] <= limit) {
			res.set(i, 1);
			total += weight[i];
		}
	}
	return res;
}


long long count_subset(bitset<N> seq, int count_ones) {
	// count subset < seq with count_ones ones
	
	memset(f, 0, sizeof f);
	f[0][0] = seq[0];
	int cnt_ones = seq[0];

	for (int i = 1; i < n; ++ i) {
		// add 1
		for (int ones = 1; ones <= count_ones; ++ ones) {
			f[i][ones] += f[i - 1][ones - 1];
		}
		// add 0
		for (int ones = 0; ones <= count_ones; ++ ones) {
			f[i][ones] += f[i - 1][ones];
		}
		// equal mostly
		if (seq[i]) {
			f[i][cnt_ones] ++;
		}
		// update
		cnt_ones += seq[i];
	}
	return f[n - 1][count_ones] + (seq.count() == count_ones);
}

void show(bitset<N> s) {
	for (int i = 0; i < n; ++ i) {
		cerr << s[i] << ' ';
	}
	cerr << '\n';
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++ i) {
		cin >> weight[i];
	}
	sort(weight, weight + n, greater<long long>());
	long long a, b;
	cin >> a >> b;
	bitset<N> upper_set = max_subset(b);
	bitset<N> lower_set = max_subset(a - 1);
	cout << count_subset(upper_set, k) - count_subset(lower_set, k);
}