#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,_round;
ll i;
const int N=1e8+5000;
int f[N],g[N];
int d[N];
int main()
{
    //freopen("FIBSEQ.INP","r",stdin);
    //freopen("FIBSEQ.OUT","w",stdout);
    int tc;
    scanf("%d",&tc);
while (tc--)
{
    bool cont=0;
    scanf("%d",&n);
    scanf("%lld",&i);
    scanf("%d",&k);
    f[0]=0; f[1]=1; _round=1;
    do
    {
        _round++;
        f[_round]=(f[_round-2]+f[_round-1])%k;
        //cout<<f[_round]<<" ";
    } while (f[_round-1]!=0||f[_round]!=1);
    //cout<<endl;
    _round--;
    //cout<<_round<<endl;
    for (int j=0;j<n;j++)
    {
        g[j]=f[(i+j)%_round];
        if (j) g[j]=(g[j]+g[j-1])%k;
        //cout<<g[j]<<endl;
    }
    //for (int j=0;j<n;j++) cout<<f[j]<<" "; cout<<endl;
    //for (int j=0;j<n;j++) cout<<g[j]<<" "; cout<<endl;
    for (int j=0;j<n;j++) if (g[j]==0)
    {
        printf("%d ",j+1);
        for (int l=0;l<=j;l++) printf("%lld ",i+l);
        printf("\n");
        cont=1;
        break;
    }
    if (cont) continue;
    memset(d,-1,sizeof(d));
    for (int j=0;j<n;j++)
    {
        if (d[g[j]]==-1) d[g[j]]=j;
        else
        {
            int a=d[g[j]];
            printf("%d ",j-a);
            for (int l=a+1;l<=j;l++) printf("%lld ",i+l);
            printf("\n");
            break;
        }
    }
}
}
