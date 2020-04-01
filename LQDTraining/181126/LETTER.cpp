#include <bits/stdc++.h>
using namespace std;

long long num, s;
vector<long long> v;
int mark[10];

void gen(int i) {
	for (int d = 1; d <= 9; ++ d) {
		if (mark[d]) continue;

		mark[d] = 1;
		num = num * 10 + d;

		v.push_back(num);
		if (i < 9) gen(i + 1);

		num /= 10;
		mark[d] = 0;
	}
}

int main() {
	// freopen("LETTER.inp", "r", stdin);
	// freopen("LETTER.out", "w", stdout);
	num = 0;
	gen(1);
	sort(v.begin(), v.end());
	while (scanf("%d", &s) != EOF) {
		// cerr << s << "\n";
		if (s > v.back()) printf("0\n");
		else if (s < 0) printf("1\n");
		else printf("%lld\n", *lower_bound(v.begin(), v.end(), s));
	}
}