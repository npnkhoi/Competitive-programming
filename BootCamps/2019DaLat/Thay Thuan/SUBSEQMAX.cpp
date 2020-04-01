#include <bits/stdc++.h>
using namespace std;

int n, val;
long long s, minS, res;

void read(int &number) { 
  bool negative = false; 
  register int c; 
  number = 0; 
  do c = getchar(); while (c == ' ');
  if (c == '-') { 
    negative = true; 
    c = getchar();
  } 
  for (; (c > 47 && c < 58); c = getchar()) 
    number = number * 10 + c - 48; 
  if (negative) number = - number;
}

void read(long long &number) { 
  bool negative = false; 
  register int c; 
  number = 0; 
  do c = getchar(); while (c == ' ');
  if (c == '-') { 
    negative = true; 
    c = getchar();
  } 
  for (; (c > 47 && c < 58); c = getchar()) 
    number = number * 10 + c - 48; 
  if (negative) number = - number;
}

int main() {
	read(n);
	for (int i = 1; i <= n; ++ i) {
		// scanf("%d", &val);
		// cin >> val;
		read(val);
		s += val;
		res = max(res, s - minS);
		minS = min(minS, s);
	}
	printf("%lld", res);
	// cout << res;
}