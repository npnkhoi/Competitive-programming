#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n, len, cnt, tmp;
int l[N + 5], a[N + 5];
char s[N + 5];
int pre[N + 5], lastPos[2*N + 5];
// deque<int> pos[2 * N + 5];

int main() {
	freopen("BRACKET.inp", "r", stdin);
	freopen("BRACKET.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	memset(lastPos, -1, sizeof lastPos);
	lastPos[0 + N] = 0;

	for (int i = 1; i <= n; ++ i) {
		a[i] = a[i - 1] + (s[i] == '(' ? 1 : - 1);
		int val = a[i] + N;

		int tmp = i - 1;
		while (tmp != 0 && a[tmp] >= a[i]) {
			tmp = l[tmp];
		}
		l[i] = tmp;

		if (lastPos[val] != -1 && lastPos[val] > l[i]) {
			pre[i] = pre[lastPos[val]];
			int l = i - pre[i];
			if (l > len) {
				len = l;
				cnt = 1;
			} else if (l == len) {
				++ cnt;
			}	
		} else pre[i] = i;
		lastPos[val] = i;
	}
	if (len == 0) printf("-1");
	else printf("%d %d\n", len, cnt);
}