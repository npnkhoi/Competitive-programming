#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n, k, pos[N], val[N];
map<int, int> cnt;

int main() {
	cin >> n >> k;

	for (int i = 1; i <= k + 1; ++ i) {
		cout << "? ";
		for (int j = 1; j <= k + 1; ++ j) {
			if (j == i) continue;
			cout << j << ' ';
		}
		cout << endl;
		cin >> pos[i] >> val[i];
		cnt[val[i]] ++;
	}
	cout << "! " << cnt.rbegin() -> second << endl;
}