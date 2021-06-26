#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int tc, n, a[N];
long long mark[N], counter, res;

int main() {
	 cin >> tc;
	 while (tc --) {
	 	cin >> n;
	 	for (int i = 0; i < n; ++ i) {
	 		cin >> a[i];
	 	}
	 	counter = res = 0;
	 	memset(mark, 0, sizeof mark);
	 	for (int i = 0; i < n; ++ i) {
	 		counter += mark[i];
	 		res += max(a[i] - 1 - counter, 0LL);
	 		if (a[i] >= 2) {
	 			mark[i + 2] ++;
	 			mark[min(i + a[i] + 1, n)] --;
	 		}
	 		if (counter >= a[i] - 1) {
	 			int tmp = counter - a[i] + 1;
	 			mark[i + 1] += tmp;
	 			mark[i + 2] -= tmp;
	 		}
	 		// printf("at %d, counter = %d\n", i, counter);
	 		// for (int i = 0; i < n; ++ i) {
	 		// 	cerr << mark[i] << ' ';
	 		// }
	 		// cerr << '\n';
	 	}	
	 	cout << res << '\n';
	 }
}