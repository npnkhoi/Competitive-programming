#include <bits/stdc++.h>
using namespace std;

int cnt_top = 0, n;
bool ok;

void solve(vector<int> v) {
	if (v.size() <= 1 || ok) return;
	int size = v.size();
	int pivot = rand() % size;

	vector<int> le, ri;
	char answer;
	for (int i = 0; i < size; ++ i) {
		if (i == pivot) continue;
		cout << "? " << v[i] << ' ' << v[pivot] << endl;
		cin >> answer;
		if (answer == '<') {
			le.push_back(v[i]);
		} else {
			ri.push_back(v[i]);
		}
	}
	if (cnt_top + ri.size() > n) {
		solve(ri);
	} else if (cnt_top + ri.size() == n || cnt_top + ri.size() + 1 == n) {
		ok = true;
		return;
	} else {
		cnt_top += ri.size() + 1;
		solve(le);
	}
}

int main() {
	srand(time(NULL));
	int tc;
	cin >> tc;
	while (tc --) {
		cin >> n;
		
		cnt_top = 0;
		ok = false;

		vector<int> v;
		for (int i = 0; i < n + n; ++ i) v.push_back(i + 1);
		solve(v);
		cout << "!" << endl;
	}
}