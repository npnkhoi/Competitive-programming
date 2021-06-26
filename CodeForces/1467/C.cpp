#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

long long n[3], a[3][N], sum[3], mini[3];

int main() {
	cin >> n[0] >> n[1] >> n[2];
	mini[0] = mini[1] = mini[2] = 1e9 + 7;
	for (int i = 0; i < 3; ++ i) {
		for (int j = 0; j < n[i]; ++j) {
			cin >> a[i][j];
			sum[i] += a[i][j];
			mini[i] = min(mini[i], a[i][j]);
		}
	}
	long long min_minus = min(sum[0], min(sum[1], sum[2]));
	min_minus = min(min_minus, mini[0] + mini[1]);
	min_minus = min(min_minus, mini[1] + mini[2]);
	min_minus = min(min_minus, mini[0] + mini[2]);
	cout << sum[0] + sum[1] + sum[2] - min_minus * 2;
}