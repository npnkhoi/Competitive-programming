#include <bits/stdc++.h>
using namespace std;

const int N = 14e4 + 5, L = 1e6 + 5;

int n, par[N];
char s[L];
stack<int> st;

int main() {
	scanf("%d", &n);
	scanf("%s", s);
	int l = strlen(s);
	// cerr << s << '\n';
	for (int i = 0; i < l;) {
		// cerr << i << '\n';
		if (isdigit(s[i])) {
			// get num
			int num = 0;
			do {
				num = num * 10 + s[i] - '0';
				i ++;
				// cerr << i << '\n';
			} while (isdigit(s[i]));
			// add edge
			if (!st.empty()) par[num] = st.top();
			st.push(num);
		} else {
			if (s[i] == ')') st.pop();
			i ++;
		}
	}
	for (int i = 1; i <= n; ++ i) printf("%d ", par[i]);
}