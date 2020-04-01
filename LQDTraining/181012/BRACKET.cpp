#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n, len, cnt;
char s[N + 5];
stack<pair<int, int> > st;
// deque<int> pos[2 * N + 5];

int main() {
	freopen("BRACKET.inp", "r", stdin);
	freopen("BRACKET.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);


	for (int i = 1; i <= n; ++ i) {
		if (s[i] == '(') {
			st.push(make_pair(i, 1));
		} else {
			if (st.empty() || st.top().second == 0) st.push(make_pair(i, 0));
			else {
				st.pop();
				// cerr << "pop\n";
			}
		}
		int l = i - (st.empty() ? 0 : st.top().first);
		// cerr << l << "\n";
		if (l > len) {
			len = l;
			cnt = 1;
		} else if (l == len) {
			cnt ++;
		}
	}
	if (len == 0) printf("-1");
	else printf("%d %d\n", len, cnt);
}