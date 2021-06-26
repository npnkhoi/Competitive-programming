#include <bits/stdc++.h>
using namespace std;

int n, id[30], cnt[4];
string s;

bool pain() {
	return (cnt[0] > n/4) || (cnt[1] > n/4) || (cnt[2] > n/4) || (cnt[3] > n/4);
}

int main() {
	id['t' - 'a'] = 0;
	id['d' - 'a'] = 1;
	id['h' - 'a'] = 2;
	id['p' - 'a'] = 3;
	getline(cin, s);
	n = s.size();
	for (int i = 0; i < n; ++ i) {
		cnt[id[s[i] - 'a']] ++;
	}

	// main sol
	if (!pain()) {
		cout << 0;
		return 0;
	}

	int res = n;
	int r = -1, l = 0;
	while (pain()) {
		++r;
		cnt[id[s[r] - 'a']] --;
	}
	res = min(res, r - l + 1);
	for (r = r + 1; r < n; ++ r) {
		cnt[id[s[r] - 'a']] --;
		while (!pain()) {
			cnt[id[s[l] - 'a']] ++;
			l ++;
		}
		l --;
		cnt[id[s[l] - 'a']] --;
		res = min(res, r - l + 1);
	}
	cout << res;
}