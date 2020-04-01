#include <bits/stdc++.h>

using namespace std;

int main() {
	scanf("%lld%lld", &a, &b);
	for (int i = 1; i <= sqrt(a); i ++) {
		if (a % i == 0) {
			va.push_back(i);
		}
	}
	for (int i = 1; i <= sqrt(b); i ++) {
		if (b % i == 0) {
			vb.push_back(i);
		}
	}
	c = a + b;
	for (int i = sqrt(c); i >= 1; i --) {
		int t;
		t = upper_bound(va.begin(), va.end(), i) - va.begin();
		if (t > 0) {
			if ()
		}
	}
}