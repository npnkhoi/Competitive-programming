#include <bits/stdc++.h>
using namespace std;

int get_distance(int a, int b, bool dir) {
	if (dir) return 9 * ((a - b + 40) % 40);
	else return 9 * ((b - a + 40) % 40);
}

int main() {
	int start, one, two, three;
	while (scanf("%d %d %d %d", &start, &one, &two, &three)) {
		if (start == 0 && one == 0 && two == 0 && three == 0) {
			break;
		}
		printf("%d\n", 360 * 3 + 
			get_distance(start, one, true) + get_distance(one, two, false) + get_distance(two, three, true));
	}
}