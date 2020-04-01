#include <bits/stdc++.h> 

using namespace std; 
double p, a, b, c, d; 
int n; 

double price(int k) {
	return p * (sin(a * k + b) + cos(c * k + d) + 2); 
}

int main () {
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);                 
	cin >> p >> a >> b >> c >> d >> n; 
	cout << p << ' ' << a << ' ' << b << ' ' << c << ' ' << d << endl; 
	double mini = (double) 1e9, maxi = -mini; 

	for (int i = 1; i <= n; i++) {
		mini = min(mini, price(i));
		maxi = max(maxi, price(i));  
	}

	double res = maxi - mini; 

	printf("%.6f", res); 
	return 0; 
}