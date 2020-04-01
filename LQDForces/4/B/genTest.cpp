// Create a folder contain this generator and <task>.exe
#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define mp make_pair
#include <bits/stdc++.h>
using namespace std;
#define task ""
typedef long long lint;

lint Rand(lint l, lint r) {
    return l + (
    (lint) rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    (lint) rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    (lint) rand() * (RAND_MAX + 1) +
    (lint) rand()) % (r - l + 1);
}

set<pair<int, int>> data;

int main() {
	srand(time(NULL));
	FOR(iTest, 6, 6) {
		ofstream inp((to_string(iTest) + ".inp").c_str());

		int tc = 10;
		inp << tc << '\n';
		REP(z, tc) {
			data.clear();

			// int n = Rand(300, 400);
			int n = 400;
			inp << n << '\n';
			FOR(i, 1, n) {
				int x, y;
				do {
					x = Rand(-1e4, 1e4);
					y = Rand(-1e4, 1e4);
				} while (data.find(mp(x, y)) != data.end());
				data.insert(mp(x, y));
				inp << x << ' ' << y << '\n';
			}
		}

		inp.close();
	}
}
