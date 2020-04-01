#include <bits/stdc++.h>
#define ll long long
using namespace std;
int giam(int &i)
{
    while (i>0) i--;
}
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int i=5;
    giam(i);
    cout<<i;
}
