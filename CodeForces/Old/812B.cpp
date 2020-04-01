#include <bits/stdc++.h>
using namespace std;
int n,m,s,res,a[20][1520],f[20],b[20][2];
void Try(int i)
{
        f[i]=0;
        s+=(m-b[i+1][f[i+1]])+(m-b[i][0])+1;
        cout<<s<<endl;
        if (i>1) Try(i-1); else res=min(res,s);
        s-=(m-b[i+1][f[i+1]])+(m-b[i][0])+1;

        f[i]=1;
        s+=(b[i+1][f[i-1]]-1)+(b[i][1]-1)+1;
        if (i>1) Try(i-1); else res=min(res,s);
        cout<<s<<endl;
        s-=(b[i+1][f[i-1]]-1)+(b[i][1]-1)+1;

}
int main()
{
    cin>>n>>m;
    m+=2;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
    {
        char ch;
        scanf(" %c",&ch);
        a[i][j]=ch-'0';
        if (a[i][j])
            {
                if (b[i][0]==0) b[i][0]=j;
                b[i][1]=j;
            }
    }
    for (int i=1;i<=n;i++) cout<<b[i][0]<< " "<< b[i][1]<<endl;
    s=b[n][1]-1; res=15000; f[n]=1;
    Try(n-1);
    cout<<res;
}
