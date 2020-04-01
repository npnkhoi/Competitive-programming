#include <bits/stdc++.h>
using namespace std;
double memo[1000000005];
double f(int x)
{
    if (memo[x]) return memo[x];
    else {
        double s=f(x)+f((x+1)/2);
        s-=((int)s)-((int)s)%1000;
        f[x]=s;
        return s;
    }

}
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
}
