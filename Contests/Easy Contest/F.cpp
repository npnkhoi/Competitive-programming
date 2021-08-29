#include <bits/stdc++.h>
using namespace std;

const int N = 4005;
const int VAL = 1e6 + 5;

stack<int> st;
int n, a[N], res, inStack[VAL], f[VAL];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++ i) {
		int cnt0 = 0;
		for (int j = i + 1; j <= n; ++ j) {
			if (a[j] == a[i]) {
				cnt0 ++;
				while (!st.empty()) {
					f[st.top()] += 2;
					inStack[st.top()] = 0;
					res = max(res, 1 + f[st.top()]);
					st.pop();
				}
			} else if (!inStack[a[j]]) { 
				inStack[a[j]] = 1;
				res = max(res, f[a[j]] + 2);
				st.push(a[j]);
			}
		}
		res = max(res, cnt0 + 1);

		for (int i = 1; i <= n; ++ i) f[a[i]] = 0;
		while (!st.empty()) {
			inStack[st.top()] = 0;
			st.pop();
		}
	}
	printf("%d", res);
}