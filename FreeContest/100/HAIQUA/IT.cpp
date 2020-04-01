#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 21) + 5;

int k, n, sum, res;
int w[N], p[N];
vector<int> picks, ord;
double Time;

void answer() {
	printf("%d\n", res);
	for (int x : ord) printf("%d ", x);
}

void TLE() {
	if ((clock() - Time) / CLOCKS_PER_SEC >= 0.99) {
		answer();
		exit(0);
	}
}

void brute(bool equal, int i) {
	TLE();
	// cerr << 1;
	// cerr << equal << ' ' << i << '\n';
	if (p[i] == 0) return;
	if (i >= n) {
		int pos = i - n + 1;
		if (equal && w[i] == 2) return;
		int val = w[i];
		for (int x = i; x >= 1; x /= 2) {
			w[x] -= val;
			p[x] -= 1;
		}
		sum += 1;
		picks.push_back(pos);

		if (sum > res) {
			res = sum;
			ord = picks;
		}
		if (p[1] == 0) {
			// cerr << res << ' ' << p[1] << '\n';
			// cerr << "end here ahuhuhuuuu\n";
			answer();
			exit(0);
		}
		brute(0, 1);

		for (int x = i; x >= 1; x /= 2) {
			w[x] += val;
			p[x] += 1;
		}
		sum -= 1;
		picks.pop_back();
		return;
	}
	int tmp = w[2 * i] - w[2 * i + 1];
	if (tmp == 1) {
		brute(equal, 2 * i);
	} else if (tmp == -1) {
		brute(equal, 2 * i + 1);
	} else if (tmp == 0) {
		brute(1, 2 * i);
		brute(1, 2 * i + 1);
	}
}

int main() {
	// Time = clock();
	scanf("%d", &k);
	n = 1 << k;
	int cnt = 0;
	for (int i = n; i <= 2 * n - 1; ++i) {
		scanf("%d", &w[i]);
		p[i] = w[i] <= 2;
		cnt += (w[i] >= 2);
	}
	if (cnt > 1) {
		printf("0\n");
		exit(0);
	}
	for (int i = n - 1; i >= 1; -- i) {
		w[i] = w[2 * i] + w[2 * i + 1];
		p[i] = p[2 * i] + p[2 * i + 1];
	}
	brute(0, 1);
	answer();
}