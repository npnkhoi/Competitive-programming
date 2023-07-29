#include <bits/stdc++.h>
using namespace std;

const int CHAR = 26, N = 13;

vector<int> parents[CHAR];
int num_children[CHAR];
bool appear[CHAR];
char ch[N];

int main() {
	int tc; cin >> tc;
	while (tc --) {
		for (int i = 0; i < CHAR; ++ i) {
			parents[i].clear();
			num_children[i] = 0;
			appear[i] = false;
		}
		int cnt_chars = 0;
		vector<int> targer_chars;

		int n, r; cin >> n >> r;
		while (r --) {
			int x; cin >> x;
			for (int i = 0; i < x; ++ i) {
				cin >> ch[i];
				if (!appear[ch[i] - 'A']) {
					appear[ch[i] - 'A'] = true;
					cnt_chars ++;
					targer_chars.push_back(ch[i] - 'A');
				}
			}
			for (int i = 1; i < x; ++ i) {
				int parent, child;
				parents[ch[i] - 'A'].push_back(ch[i - 1] - 'A');
				num_children[ch[i - 1] - 'A'] ++;
			}
		}

		if (cnt_chars != n) {
			cout << "NOT ENOUGH INFO\n";
			continue;
		}

		queue<int> q;
		bool queue_exceed = false;
		for (int c : targer_chars) {
			if (num_children[c] == 0) {
				q.push(c);
			}
		}

		vector<int> ans;
		while (!q.empty()) {
			if (q.size() > 1) {
				queue_exceed = true;
			}
			int c = q.front(); q.pop();
			ans.push_back(c);
			for (int v : parents[c]) {
				num_children[v] --;
				if (num_children[v] == 0) {
					q.push(v);
				}
			}	
		}

		if (ans.size() != n || queue_exceed) {
			cout << "NOT ENOUGH INFO\n";
		} else {
			for (int i = n - 1; i >= 0; -- i) {
				cout << char(ans[i] + 'A') << ' ';
			}
			cout << '\n';
		}
	}
}