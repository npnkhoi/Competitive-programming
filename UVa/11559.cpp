#include <stdio.h>
#include <algorithm>
using namespace std;
//const oo=1e3+5;
int n,b,h,w,res,cost,rooms;
int main()
{
    //freopen("11559.inp","r",stdin);
    //freopen("11559.out","w",stdout);
    while (scanf("%d%d%d%d",&n,&b,&h,&w)!=EOF)
    {
        res=b+5;
        for (int i=0;i<h;i++)
        {
            scanf("%d",&cost);
            for (int j=0;j<w;j++)
            {
                scanf("%d",&rooms);
                if (rooms>=n) res=min(res,cost*n);
            }
        }
        if ((res>b)) printf("stay home\n");
            else printf("%d\n",res);
    }
}//4
