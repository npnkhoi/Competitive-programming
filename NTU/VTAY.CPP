#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int n;
    scanf("%d",&n);
    n=n%14;
    if (n<7) printf("%d %d",7-n,n);
    else printf("%d %d",n-7,14-n);
}
