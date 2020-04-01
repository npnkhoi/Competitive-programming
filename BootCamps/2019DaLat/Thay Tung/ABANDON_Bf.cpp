#include <bits/stdc++.h>
using namespace std;

vector<int> v, t;
long long n;
int k;

int main() {
	scanf("%lld%d", &n, &k);

	for (int i = 1; i <= n; ++ i) {
		v.push_back(i);
	}
	while (v.size() >= k) {
		t.clear();
		for (int i = 1; i <= v.size(); ++ i) {
			if (i % k) t.push_back(v[i - 1]);
		}
		v = t;
		for (int x : t) cerr << x << " ";
		cerr << "\n";
	}
}