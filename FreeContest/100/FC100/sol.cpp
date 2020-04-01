#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {
		if (s == "Free Contest 100") {
			printf("Let\'s start!\n");
			return 0;
		} else {
			printf("Wait\n");
		}
	}
}