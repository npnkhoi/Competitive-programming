#include <bits/stdc++.h>

#define ll long long

using namespace std;
const int N=2100;
int n,l[10],f[7][3][N][N];
string s[7][3];
int main()
{
    freopen("STR5.inp","r",stdin);
    freopen("STR5.out","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        cin>>s[i][0];
        l[i]=s[i][0].size();
        //cerr<<l[i];
    }
    for (int i=1;i<n;i++)
        for (int j=l[i]-1;j>=0;j--)
        {
            s[i][1]+=s[i][0][j];
            //cerr<<s[i][1]<<endl;
        }

    for (int i=0;i<l[0];i++) s[0][0]+=s[0][0][i];
    for (int t=1;t<n;t++)
        for (int cs=0;cs<2;cs++)
            for (int j=0;j<=l[t];j++) s[t][cs]+=s[t][cs][j];
    for (int i=0;i<n;i++) l[i]*=2;
    //---------------------------------
    for (int t=1;t<n;t++)
    for (int cs=0;cs<=1;cs++)
    for (int i=0;i<l[0];i++)
    for (int j=0;j<l[t];j++)
    {
        if (s[0][0][i]!=s[t][cs][j]) f[t][cs][i][j]=0;
        else
        {
            if (i&&j) f[t][cs][i][j]=f[t][cs][i-1][j-1]+1;
            else f[t][cs][i][j]=1;
        }
    }
    //cerr<<f[1][0][3][4];
    //-------------------------------------
    int res=0;
    for (int i=0;i<l[0];i++)
    {
        int tmp=N;
        for (int t=1;t<n;t++)
        {
            int max0=0, max1=0;
            for (int j=0;j<l[t];j++) max0=max(max0,f[t][0][i][j]);
            for (int j=0;j<l[t];j++) max1=max(max1,f[t][1][i][j]);
            tmp=min(tmp,max(max0,max1));
        }
        res=max(res,tmp);
    }
    printf("%d",min(l[0]/2,res));
}
