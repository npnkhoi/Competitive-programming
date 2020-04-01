#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int N = 1e5 + 5;

int n, m, k;
int a[N];
deque<ii> q;
map<int, int> cnt;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);

	int pre = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == n || a[i] != a[i + 1]) {
			q.push_back(make_pair(a[i], i - pre));
			if (a[i]) {
				cnt[i - pre] ++;
				// cerr << i - pre << "\n";
			}
			pre = i;
		}
	}

	int head = 1;
	while (m --) {
		char ch;
		scanf(" %c", &ch);

		if (ch == '?') {
			while (!cnt.empty() && cnt.rbegin() -> second == 0) 
				cnt.erase(cnt.rbegin() -> first);
			printf("%d\n", (cnt.empty() ? 0 : min(k, cnt.rbegin() -> first)));
		}
		else {
			int tail = (head == 1 ? n : head - 1);

			int u = q.back().first, v = q.back().second;
			if (u) {
				cnt[v] --;
				cnt[v - 1] ++;
			}
			if (v == 1) q.pop_back();
			else q.back().second --;

			u = q.front().first, v  = q.front().second;
			if (a[tail] == u) {
				if (u) {
					cnt[v] --;
					cnt[v + 1] ++;
				}
				q.front().second ++;
			} else {
				q.push_front(make_pair(a[tail], 1));
				if (a[tail] == 1) cnt[1] ++;
			}	

			// cerr << q.front().second << " " << q.back().second << "\n";

			head = tail;
		}
	}
}