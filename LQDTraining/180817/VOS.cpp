#include <bits/stdc++.h>
using namespace std;

#define task "VOS"

const int N = 1e6 + 5;
int n, k, a[N], l[N], r[N];
stack<int> st;

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= n; i ++) {
		while (!st.empty() && a[st.top()] <= a[i]) {
			st.pop();
		}
		l[i] = (st.empty() ? 0 : st.top());
		st.push(i);
	}

	while (!st.empty()) st.pop();
	for (int i = n; i >= 1; -- i) {
		while (!st.empty() && a[st.top()] < a[i]) {
			st.pop();
		}
		r[i] = (st.empty() ? n + 1 : st.top());
		st.push(i);
	}

	long long res = 0;
	for (int i = 1; i <= n; i ++) {
		if (a[i] == k) {
			// cerr << i << " " << l[i] << " " << r[i] << "\n";
			res += 1LL * (r[i] - i) * (i - l[i]);
		}
	}
	printf("%lld", res);
}