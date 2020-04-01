#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, k, cnt[30];
string s;

int main() {
	scanf("%d%d ", &n, &k);
	getline(cin, s);
	for (int i = 0; i < n; ++ i) {
		++ cnt[s[i] - 'A'];
	}
	int res = cnt[0];
	for (int i = 1; i < k; ++ i) {
		res = min(res, cnt[i]);
	}
	printf("%d", res * k);
}