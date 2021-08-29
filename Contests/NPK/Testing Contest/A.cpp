//#include <bits/stdc++.h>
#include <stdio.h>
#include <utility>
#include <algorithm>
#define ll long long
#define fi first
#define se second

using namespace std;
int n,k,res;
pair<int,int> a[55][25];
bool same(int i, int j)
{
    for (int l=1;l<=k;l++)
        if (a[i][l].se!=a[j][l].se) return 0;
    return 1;
}
bool newset(int i)
{
    for (int j=1;j<i;j++) if (same(j,i)) return 0;
    return 1;
}
int main()
{
    freopen("A.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=k;j++)
        {
            scanf("%d",&a[i][j].fi);
            a[i][j].se=j;
        }
        sort(a[i]+1,a[i]+k+1);
        if (newset(i)) res++;
    }
    printf("%d",res);
}
