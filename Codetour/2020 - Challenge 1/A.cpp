#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k;
pair<double, int> male[N], female[N];
string real_score[N];

int main() {
	cin >> n >> k;
	k --;
	string raw;
	for (int i = 0; i < n; ++ i) {
		cin >> raw;
		male[i] = {stod(raw), i};
	}
	for (int i = 0; i < n; ++ i) {
		cin >> raw;
		female[i] = {stod(raw), -i};
		real_score[i] = raw;
	}
	sort(male, male + n);
	sort(female, female + n);
	for (int i = 0; i < n; ++ i) {
		if (male[i].second == k) {
			// cerr << i << '\n';
			int j = n - i - 1;
			int id = - female[j].second;
			cout << id + 1 << ' ' << real_score[id];
			return 0;
		}
	}
}