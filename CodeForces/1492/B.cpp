#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int tc, n, p[N], max_left[N];

int main() {
	cin >> tc;
	while (tc --) {
		cin >> n;
		int pos = -1, val = 0, max_pos;
		for (int i = 0; i < n; ++ i) {
			cin >> p[i];
			if (p[i] > val) {
				max_left[i] = pos;
				pos = i;
				val = p[i];
			}
			if (p[i] == n) {
				max_pos = i;
			}
		}
		int right_bound = n;
		int index = max_pos;
		while (index != -1) {
			for (int i = index; i < right_bound; ++ i) {
				cout << p[i] << ' ';
			}
			right_bound = index;
			index = max_left[index];
		}
		cout << '\n';
	}
}