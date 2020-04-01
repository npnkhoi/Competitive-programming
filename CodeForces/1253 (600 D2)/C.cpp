#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, a[N];
long long s[N], ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) {
		s[i] = a[i] + (i > m ? s[i - m] : 0);
		ans += s[i];
		cout << ans << ' ';
	}
}