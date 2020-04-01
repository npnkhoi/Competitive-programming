using namespace std;
#include <bits/stdc++.h>
const int N=1e4+50;
int a[N],n,i;
int main()
{
    cin>>n;
    for (int i=n-1;i>=0;i--)
    {
        char ch;
        cin>>ch;
        a[i]=ch-'0';
    }
    i=0;
    while ((a[i]==1)&&(i<n)) i++;
    if (i==n)
    {
        printf("-1");
    }else
    {
        for (int j=n-1;j>i;j--) printf("%d",a[j]);
        printf("1");
        for (int j=i-1;j>=0;j--) printf("0");
    }

}
