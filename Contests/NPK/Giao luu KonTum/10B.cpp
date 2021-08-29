#include <bits/stdc++.h>
using namespace std;
int n;
int a[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
bool ok(int N)
{
    int y=(N%a[n/2]);
    int x=(N/a[n/2]);
    return ((x+y)*(x+y)==N);
}
void show(int N)
{
    int M=N;
    int cnt=0;
    while (N) {N/=10; cnt++;}
    for (int i=1;i<=n-cnt;i++) printf("0");
    if (M) printf("%d",M);
    printf("\n");
}
int main()
{
    //freopen("10B.out","w",stdout);
    while (scanf("%d",&n)!=EOF)
    {
        if (n==2) printf("00\n01\n81\n");
        if (n==4) printf("0000\n0001\n2025\n3025\n9801\n");
        if (n==6) printf("000000\n000001\n088209\n494209\n998001\n");
        if (n==8) printf("00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n");
        //for (int i=0;i<a[n];i++)
        //    if (ok(i)) show(i);
    }
}
