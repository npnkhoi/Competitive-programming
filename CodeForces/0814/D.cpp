using namespace std;
#include <stdio.h>
#include <iostream>
#include <math.h>

const double pi = acos(-1);
const int N = 1e3 + 50;
long long x[N], y[N], r[N];
int  cnt, n;
double res = 0;

bool inside(int i, int j)
{

    return ((double)(r[j] - r[i])) >=
        sqrt((double)(x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> r[i];
    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        for (int j = 1; j <= n; j++)
            if (j != i && inside(i,j)) cnt ++;
        if (cnt == 0 || cnt % 2) res += r[i] * r[i] * pi;
            else res -= r[i] * r[i] * pi;
     }
     printf("%.15f", res);
}
