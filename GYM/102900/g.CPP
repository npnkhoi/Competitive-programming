#include <bits/stdc++.h>

using namespace std;
#define int long long

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	int m = n / 3, rem = n - m;
	// cerr << m << endl;?
	int res = n * (n - 1) / 2 - rem * (rem - 1) / 2;
	cout << res << endl;

}