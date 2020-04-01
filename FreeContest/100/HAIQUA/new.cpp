#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 20) + 5;

int k, n, sum, res;
int w[N], s1[N], s2[N], ft1[N], ft2[N];
vector<int> picks, ord;

void update(int ft[], int i, int val) {
	while (i <= n) {
		ft[i] += val;
		i += i&-i;
	}
}

int get(int ft[], int i) {
	int ret = 0;
	while (i) {
		ret += ft[i];
		i -= i&-i;
	}
	return ret;
}

int get(int ft[], int l, int r) {
	return get(ft, r) - get(ft, l - 1);
}

void answer() {
	cout << res << '\n';
	for (int x : ord) cout << x << ' ';
}

void brute(bool equal, int l, int r) {
	// cerr << equal << ' ' << l << ' ' << r << '\n';
	if (get(ft2, l, r) == 0) return;
	if (l == r) {
		if (equal && w[l] == 2) return;

		update(ft1, l, -w[l]);
		update(ft2, l, -1);
		sum += 1;
		picks.push_back(l);

		if (sum > res) {
			res = sum;
			ord = picks;
		}
		if (res == s2[n]) {
			answer();
			exit(0);
		}
		brute(0, 1, n);

		update(ft1, l, w[l]);
		update(ft2, l, 1);
		sum -= 1;
		picks.pop_back();
		return;
	}
	int mid = (l + r) / 2;
	int tmp = get(ft1, l, mid) - get(ft1, mid + 1, r);
	if (tmp == 1) {
		brute(equal, l, mid);
	} else if (tmp == -1) {
		brute(equal, mid + 1, r);
	} else if (tmp == 0) {
		brute(1, l, mid);
		brute(1, mid + 1, r);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> k;
	n = (1 << k);
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
		s1[i] = s1[i - 1] + w[i];
		s2[i] = s2[i - 1] + (w[i] <= 2);
	}
	for (int i = 1; i <= n; ++ i) {
		ft1[i] = s1[i] - s1[i - (i &-i)];
		ft2[i] = s2[i] - s2[i - (i &-i)];
	}
	brute(0, 1, n);
	answer();
}