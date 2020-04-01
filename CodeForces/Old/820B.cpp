#include <bits/stdc++.h>

using namespace std;
double n, a, res, x;
int idx;
double cl(int i)
{
    return abs((180-x)*1.0*i/2 - 1.0*a);
}
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin >> n >> a;
    x = 180.0*(n-2)/n;
    res = 180;
    for (int i = 1; i <= n - 2; i++)
    if (cl(i) < res)
    {
        res = cl(i);
        idx = 2+i;
    }
    cout << "2 1 " << idx;
    return 0;
}
/**/
