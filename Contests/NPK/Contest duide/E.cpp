
#include <stdio.h>
#include <iostream>
#include <algorithm>


using namespace std;

struct rc
{
    int x,y;
};
int H,G;
const int oo=2e9;
rc h[1010],g[1010];
long long f[1010][1010][2];
int dist(rc a, rc b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main()
{
    freopen("E.inp","r",stdin);
    scanf("%d%d",&H,&G); H--;
    scanf("%d%d",&h[0].x,&h[0].y);
    g[0].x=h[0].x; g[0].y=h[0].y;
    for (int i=1;i<=H;i++) scanf("%d%d",&h[i].x,&h[i].y);
    for (int i=1;i<=G;i++) scanf("%d%d",&g[i].x,&g[i].y);
    f[0][0][0]=0;
    f[0][0][1]=0;
    for (int i=1;i<=H;i++)
    {
        f[i][0][0]=f[i-1][0][0]+dist(h[i],h[i-1]);
        f[i][0][1]=oo;
        //cout << f[i][0][0] << endl;
    }
    for (int j=1;j<=G;j++)
    {
        f[0][j][1]=f[0][j-1][1]+dist(g[j],g[j-1]);
        f[0][j][0]=oo;
        //cout << f[0][j][1] << endl;
    }

    for (int i=1;i<=H;i++)
        for (int j=1;j<=G;j++)
    {
        f[i][j][0]=min(f[i-1][j][0]+dist(h[i-1],h[i]),f[i-1][j][1]+dist(g[j],h[i]));
        f[i][j][1]=min(f[i][j-1][0]+dist(g[j],h[i]),f[i][j-1][1]+dist(g[j],g[j-1]));
    }
    for (int i=0;i<=H;i++)
        for (int j=0;j<=G;j++)
    {
        //printf("%d %d %d %d\n",i,j,f[i][j][0],f[i][j][1]);
    }
    cout << f[H][G][0];

}


