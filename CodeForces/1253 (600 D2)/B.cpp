#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, VAL = 1e6 + 5, base = 1e6;

int n, a[N], mark[VAL], cnt_in = 0;
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	int flag = -1;
	for (int i = 0; i < n; ++ i) {
		cin >> a[i];
		if (a[i] > 0) {
			if (mark[a[i]] == 0) {
				mark[a[i]] ++;
				cnt_in ++;
			} else {
				cout << -1;
				return 0;
			}
		} else {
			a[i] = -a[i];
			if (mark[a[i]] == 1) {
				mark[a[i]] ++;
				cnt_in --;
			} else {
				cout << -1;
				return 0;
			}
		}
		if (cnt_in == 0) {
			ans.push_back(i - flag);
			for (int j = flag + 1; j <= i; ++ j) {
				mark[a[j]] = 0;
			}
			flag = i;
		}
	}
	if (cnt_in != 0) {
		cout << -1;
	} else {
		cout << ans.size() << '\n';
		for (int x : ans) cout << x << ' ';
	}
}