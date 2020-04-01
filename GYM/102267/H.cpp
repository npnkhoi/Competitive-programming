#include <bits/stdc++.h>
using namespace std;

int v;
double a;

int main() {
	scanf("%d%lf", &v, &a);
	double pi = acos(-1);
	double r = a / 2.0 / sin(pi / v);
	printf("%.10lf", r * r * pi);
}