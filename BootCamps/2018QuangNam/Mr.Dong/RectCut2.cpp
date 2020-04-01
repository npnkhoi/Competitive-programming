#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
const int N=20;
const int oo=N*N;
int f[N][N][N][N],m,n,a[N][N];
int s(int x, int y, int u, int v)
{
    int s=a[u][v];
    if (x>1) s-=a[x-1][v];
    if (y>1) s-=a[u][y-1];
    if (x>1&&y>1) s+=a[x-1][y-1];
    return s;
}
int sol(int x, int y, int u, int v)
{
    if (f[x][y][u][v]!=-1) return f[x][y][u][v];
    if ((s(x,y,u,v)==(u-x+1)*(v-y+1))||(s(x,y,u,v)==0))
    {
        f[x][y][u][v]=1;
        return 1;
    }
    int res=oo;
    for (int c=x;c<u;c++) res=min(res,sol(x,y,c,v)+sol(c+1,y,u,v));
    for (int c=y;c<v;c++) res=min(res,sol(x,y,u,c)+sol(x,c+1,u,v));
    //printf("f[%d,%d,%d,%d]=%d\n",x,y,u,v,res);
    f[x][y][u][v]=res;
    return res;
}
int main()
{
    freopen("RectCut2.inp","r",stdin);
    memset(f,-1,sizeof(f));
    scanf("%d%d",&m,&n);
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if (i>1) a[i][j]+=a[i-1][j];
            if (j>1) a[i][j]+=a[i][j-1];
            if (i>1&&j>1) a[i][j]-=a[i-1][j-1];
            //printf("%5d",a[i][j]);
        }
        //cout<<endl;

    }
    printf("%d",sol(1,1,m,n));
}
