#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k, idx, res;
int a[2*N], cnt[N], le[N], ri[N];
map<int, int> stat[N];

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; ++ i) {
		cin >> a[i];
		a[n+i] = a[i];
	}
}

void add(int val, int group) {
	if (stat[group].find(val) == stat[group].end()) {
		stat[group][val] = 1;
		cnt[group] ++;
	} else {
		stat[group][val] ++;
	}
}

void init(int start) {
	for (int i = 1; i <= idx; ++ i) stat[i].clear();
	idx = 1;
	memset(cnt, 0, sizeof cnt); // remember this

	le[1] = start; // left end of first group
	for (int i = start; i < start + n; ++i) {
		if (cnt[idx] == k) {
			ri[idx] = i-1;
			idx ++;
			le[idx] = i;
			// cerr << i << ' ';
		}
		add(a[i], idx);
	}	
	// cerr << '\n';
	ri[idx] = start + n - 1; // right end of last group
	res = max(res, idx - (cnt[idx] != k));
}

void slide() {

}

int main() {
	srand(time(NULL));
	double time = clock();
	input();
	for (int i = 0; i < n; ++ i) {
		init(rand() % n);
		if ((time - clock()) / CLOCKS_PER_SEC > 0.9) break;
	}
	cout << res << '\n';
}