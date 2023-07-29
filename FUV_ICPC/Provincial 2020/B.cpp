#include <bits/stdc++.h>
using namespace std;

void print2ddigit(int num) {
	if (num > 9) 
		cout << num;
	else
		cout << 0 << num;
}

int main() {
	int n, fade, total_dur = 0;
	cin >> n >> fade;
	for (int i = 0; i < n; ++ i) {
		string dur;
		cin >> dur;
		// cerr << dur << '\n';
		// cerr << dur[0] << dur[2] << dur[3] << '\n';
		total_dur += (dur[0] - '0') * 60 + (dur[2] - '0') * 10 + (dur[3] - '0');
		// cerr << total_dur << '\n';
	}
	total_dur -= (n - 1) * fade;
	// cout << total_dur << '\n';
	print2ddigit(total_dur / 3600);
	total_dur %= 3600;
	cout << ":";
	print2ddigit(total_dur / 60);
	total_dur %= 60;
	cout << ":";
	print2ddigit(total_dur);
}