#include <bits/stdc++.h>
using namespace std;

void answer_all_B() {
	cout << "Yes\n";
	for (int i = 0; i < m - 1; ++ i) {
		cout << k << ' ';
		for (int j = 0; j < k; ++ j) {
			cout << i * k + j << ' ';
		}
		cout << '\n';
	}
	cout << n - (m - 1) * (k) << ' ';
	for (int x = (m - 1) * (k); x < n; ++ i) {
		cout << x << ' ';
	}
	cout << '\n';
}

int nxt(int x) {
	return (x + 1 == n ? 0 : x + 1);
}

int pre(int x) {
	return (x == 0 ? n - 1: x - 1);
}

void answer_normal() {
	int head = 0;
	while (s[head] != 'C') head ++;

	int pos = pre(head), mark = head;
	for (int i = 0; i < n; ++ i, pos = nxt(pos)) {

		if (s[pos] == 'B' && s[pre(pos)] == 'C') {
			mark = pos;
		} else if (s[pos] == 'C' && s[pre(pos)] == 'B') {
			if (pos == mark) continue;
			// Found new chain!!
			int x = mark;
			while (x != mark && nxt(x) != mark) {
				v.push_back({x, nxt(x)});
				vis[x] = vis[nxt(x)] = 1;
				x = nxt(nxt(x));
			}
		}
	}

	if (v.size() >= m)
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tc;
	while (tc --) {
		cin >> n >> m >> k >> s;
		if (n % k != 0) {
			cout << "No\n";
			continue;
		}

		// check if all is B
		int has_C = false;
		for (int i = 0; i < n; ++ i) {
			if (s[i] == 'C') has_C = true;
		}

		if (has_C == false) {
			answer_all_B();
		} else {
			answer_normal();
		}
	}
}