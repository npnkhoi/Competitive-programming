#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char s[N];
int n;

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	s[n + 1] = 'b';

	int ord = 0; // a -> b
	for (int i = 2; i <= n + 1; ++ i) {
		if ((ord == 0) ^ (s[i] == 'b')) {
			// cerr << ord << " " << s[i] << "\n";
 			ord ^= 1;
			printf("1 ");
		} else {
			printf("0 ");
		}
	}
}