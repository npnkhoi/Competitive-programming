#include <bits/stdc++.h>
using namespace std;

int rem[2], tmp;

void writeBit(int bit, int count) {
	for (int i = 0; i < count; ++ i) {
		cout << bit;
	}
	rem[bit] -= count;
}

int main() {
	int a, b, k;
	cin >> a >> b >> k;
	if (k == 0) {
		cout << "Yes\n";
		writeBit(1, b); writeBit(0, a); cout << '\n';
		writeBit(1, b); writeBit(0, a); cout << '\n';
	} else if (k <= a + b - 2 && a >= 1 && b >= 2) {
		cout << "Yes\n";

		rem[0] = a; rem[1] = b;
		writeBit(1, 2);
		if (k-1 <= rem[1]) {
			writeBit(1, k-1);
		} else {
			tmp = rem[1];
			writeBit(1, rem[1]);
			writeBit(0, k-1-tmp);
		}
		writeBit(0, 1);
		writeBit(1, rem[1]);
		writeBit(0, rem[0]);
		cout << '\n';
		
		rem[0] = a; rem[1] = b;
		writeBit(1, 1); writeBit(0, 1);
		if (k-1 <= rem[1]-1) {
			writeBit(1, k-1);
		} else {
			tmp = rem[1] - 1;
			writeBit(1, rem[1]-1);
			writeBit(0, k-1-tmp);
		}
		writeBit(1, rem[1]);
		writeBit(0, rem[0]);
		cout << '\n';
	} else {
		cout << "No\n";
	}
}