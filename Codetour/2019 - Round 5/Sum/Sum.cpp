#include <bits/stdc++.h>
using namespace std;

string ord, a, b, sum;
int val[30];

void init() {
	ord = "asdfghjklzxcvbnmqwertyuiop";
	for (int i = 0; i < 26; ++ i) {
		val[ord[i] - 'a'] = i;
	}
}

void solve() {
	int i = a.size() - 1, j = b.size() - 1;
	sum = "";
	int tmp = 0;
	for (; i >= 0 || j >= 0; i --, j --) {
		if (i >= 0) tmp += val[a[i] - 'a'];
		if (j >= 0) tmp += val[b[j] - 'a'];
		sum += ord[tmp % 26];
		tmp = (tmp >= 26);
	}
	if (tmp) sum += ord[1];
	reverse(sum.begin(), sum.end());
}

int main() {
	init();
	cin >> a >> b;
	solve();
	cout << sum;
}