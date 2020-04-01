#include <bits/stdc++.h>
using namespace std;
string st;
int n,res;
int LCS(int i)
{
    int a,b,f[105][105];
    for (b=i;b<=n;b++) f[0][b]=0;
    for (a=0;a<=i;a++) f[a][i]=0;
    for (a=1;a<=i;a++)
        for (b=i+1;b<=n;b++)
        if (st[a]==st[b]) f[a][b]=max(f[a-1][b-1]+1,max(f[a-1][b],f[a][b-1]));
            else f[a][b]=max(f[a-1][b],f[a][b-1]);
    return f[i][n];
}
int main()
{
    getline(cin,st);
    n=st.size();
    st='0'+st;
    res=0;
    for (int i=1;i<n;i++)
        res=max(res,LCS(i));
    res*=2;
    printf("%d",res);
}
