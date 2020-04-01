#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("BIMAT.inp","r",stdin);
    //freopen("","w",stdout);
    string st;
    getline(cin,st);
    int n,x;
    n=st.size();
    x=sqrt(n);
    while (n%x) x--;
    //cout<<x<<endl;
    for (int i=0;i<x;i++)
        for (int j=0;j<n/x;j++)
        printf("%c",st[i+j*x]);
}
