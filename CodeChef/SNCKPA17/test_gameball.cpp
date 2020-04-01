//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
    //freopen("","r",stdin);
    freopen("gameball.inp","w",stdout);
    int tc=50;
    int N=10;
    int M=10;
    cout<<tc<<endl;
    //cout<<00;
    while (tc--)
    {
        int n,m,a,b;
        //cout<<0;
        //do
        {
            n=rand()%N+1;
            m=rand()%M+1;
        } //while (n<=2||m<=2);
        cout<<n<<" "<<m<<endl;
        if (n>1) a=rand()%(n-1)+1; else a=1;
        if (m>1) b=rand()%(m-1)+1; else b=1;
        //cout<<"1";
        for (int i=1;i<=n;i++)
        {
        for (int j=1;j<=m;j++)
        if (i!=a||j!=b) cout<<"*"; else cout<<".";
        cout<<endl;
        }
    }
}
