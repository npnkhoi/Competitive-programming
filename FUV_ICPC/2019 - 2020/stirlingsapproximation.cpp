#include <bits/stdc++.h>
using namespace std;
 
double pi = acos(-1);
// double e = pow((1+1/1E100),1E100);

double findthenumber(int number)
{
	double logone = 0;
	for (int i = 1; i <= number; i++)
	{
		logone = logone + log(i);
	}
	double logtwo = -0.5*log(2*pi*number) - number*log(number/exp(1));
	double total = logone + logtwo;
	return exp(total); 
}

double answer(int n) {
	double res = 1;
	for (int i = 1; i <= n; ++ i) {
		res = res * i * exp(1) / (double) n;
	}
	res /= sqrt(2 * pi * (double) n);
	return res;
}

int main() 
{
	// freopen("inp.txt", "r", stdin);
	int number;
	while (cin >> number) {
		if (number == 0) break;
		cout << fixed << setprecision(20) << findthenumber(number) << '\n';
	}
	return 0;
}