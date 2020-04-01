#include <bits/stdc++.h>
using namespace std;

class TheRoundCityDiv2 {
public:
	int find(int r) {
		int res = 0;
		for (int x = -r; x <= r; ++ x) {
			int y = sqrt(r*r - x*x);
			res += 2 * y + 1;
		}
		return res - 1;
	}
};

int main() {
	TheRoundCityDiv2 a;
	cerr << a.find(2);
}