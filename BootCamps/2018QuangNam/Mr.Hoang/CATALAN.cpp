// THINHK CAREFULLY ... ARE YOU READY !?

#include <bits/stdc++.h>
#define ll long long
using namespace std;

//==================<< END OF TEMPLATE >>========================
const int N=1e5;
int n,m,k,f[N+5];
ll res;
bool Free[1000010];
vector<int> prime;

//-----------------funciton
void build()
{
    int n=1000000;
    memset(Free,1,sizeof(Free));
    for (int i=2;i<=n;i++)
        if (Free[i])
    {
        prime.push_back(i);
        for (int j=2;j<=(n/i);j++) Free[i*j]=false;
    }
    //zz();
}
void factor_in(int x)
{
    //printf("in %d\n",x);
    if (Free[x])
    {
        f[x]++;
        return;
    }
    int j=-1;
    while (x>1)
    {
        j++; int i=prime[j];
        //printf("in %d %d",x,i);
        while ((x%i)==0)
        {
            //cout<<x<<"---------"<<endl;
            x/=i;
            f[i]++;
        }
    }

}
void factor_out(int x)
{
    //printf("out %d\n",x);
    if (Free[x])
    {
        f[x]--;
        return;
    }
    int j=-1;
    while (x>1)
    {
        j++; int i=prime[j];
        while ((x%i)==0)
        {
            //cout<<x<<endl;
            x/=i;
            f[i]--;
        }
    }

}
//--------------<< ENF OF VARIABLES DECLARATION >>---------------
int main()
{
    //freopen("","r",stdin);
    //freopen("ckn.txt","w",stdout);
    scanf("%d%d",&n,&m);
    build();
    memset(f,0,sizeof(f));
    for (int i=n+2;i<=n+n;i++)
    {
        factor_in(i);
        //for (int i=1;i<=n;i++)   /printf("%d: %d\n",i,f[i]);
    }
    for (int i=2;i<=n;i++)
    {
        factor_out(i);
        //for (int i=1;i<=n;i++)   //printf("%d: %d\n",i,f[i]);
    }
    res=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=f[i];j++) res=(res*i)%m;
    }
    printf("%lld",res);

    return 0;
}
/* -----BACKUP -------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
