#include <bits/stdc++.h>
using namespace std;
const int N=3e3+50;
const int M=1e9+7;
int Hash[N][N],k[15];
int n,res,l;
int f[N][N][15];
string st;
void sol1()
{
    for (int loop=1;loop<=n;loop++)
    {
        res=0;
        for (int i=0;i<l;i++)
        for (int j=i;j<=(l+i-2)/2;j++)
            {
                int cnt=0;
                for (int l_=i;l_<=j;l_++) if (st[l_]!=st[l_+j-i+1]) cnt++;
                if (cnt<=k[loop]) res=max(res,j-i+1);
            }
        printf("%d\n",res);
    }
}
void sol2()
{
    res=0;
    for (int i=0;i<l;i++)
    {
        Hash[i][i]=st[i]%M;
        for (int j=i+1;j<l;j++) Hash[i][j]=((Hash[i][j-1]*26)%M+st[j]%M)%M;
    }
    for (int i=0;i<l;i++)
        for (int j=i;j<=(l+i-2)/2;j++)
        {
            if (Hash[i][j]==Hash[j+1][j+j-i+1]) res=max(res,j-i+1);
            //cout<<Hash[i][j]<<" "<<Hash[j+1][j+j+i-1];

        }

    while (n--) printf("%d\n",res);
}
void sol3()
{
    for (int j=l-1;j>0;j--)
        for (int i=j-1;i>=0;i--)
            for (int x=0;x<=10;x++)
    {
        if (j==l-1)
        {
            if (x>0) f[i][j][x]=1;
                else f[i][j][x]=(st[i]==st[j]);
            //cout<<i<<j<<x<<f[i][j][x]<<endl;
        }
        else
        {
            if (st[i]==st[j]) f[i][j][x]=f[i+1][j+1][x]+1;
                else
            if (x>0) f[i][j][x]=f[i+1][j+1][x-1]+1;
                else f[i][j][x]=0;
        }
    }
    /*for (int x=0;x<=1;x++)
    {
        for (int i=0;i<l;i++)
        {
            for (int j=0;j<l;j++) cout<<f[i][j][x]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }*/


    for (int loop=1;loop<=n;loop++)
    {
        res=0;
        int K=k[loop];
        for (int i=0;i<l-1;i++)
            for (int j=i+1;j<l;j++) if (f[i][j][K]>=j-i) res=max(res,j-i);
        printf("%d\n",res);
    }
}
int main()
{
    freopen("VIRUS.inp","r",stdin);
    freopen("VIRUS.out","w",stdout);
    cin>>n;
    cin>>st; l=st.size();
    for (int i=1;i<=n;i++) scanf("%d",&k[i]);
    //if (l<=300) sol1();
        //else
            sol3();
}
