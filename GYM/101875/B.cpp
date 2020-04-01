#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n;
char s[N];
int z[N];

void Z_fn(char s[], int z[], int n) {
    z[0] = 0;
    int l = 0, r = 0;

    for (int i = 1; i <= n - 1; ++i) {
        z[i] = 0;
        if (i <= r) z[i] = min(z[i-l], r-i+1);
        while (i+z[i] < n && s[i+z[i]] == s[z[i]])
            ++ z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

int main() {
	scanf("%d ", &n);
	scanf("%s", s);
	for (int i = 0; i < n; ++i) {
		s[n + i] = s[i];
	}
	Z_fn(s, z, n + n);
	for (int i = 1; i < n; ++i) {
		if (z[i] < n) {
			if (s[z[i]] > s[i + z[i]]) {
				printf("No\n");
				exit(0);
			}
		}
	}
	printf("Yes\n");
}