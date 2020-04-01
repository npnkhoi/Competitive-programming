#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		a[2 * i - 1] = i;
	}
	int emp = 2 * n - 2;
	int idx = 2 * n - 1;
	for (int i = 1; i <= n; ++ i) {
		a[emp] = a[idx];
		idx --;
		emp -= 2;
	}
	for (int i = 1; i <= n; ++ i) cerr << a[i] << " ";
}