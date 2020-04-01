#include <stdio.h>
#include <string>
using namespace std;
int main()
{
    int k=1,n,m,x,y;
    while (k)
    {
        scanf("%d",&k);
        if (k!=0)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=k;i++)
        {
            scanf("%d%d",&x,&y);
            if ((x==n)||(y==m)) printf("divisa\n");
            else
            {
                string ans="";
                if (y>m) ans=ans+"N";
                    else ans=ans+"S";
                if (x>n) ans=ans+"E";
                    else ans=ans+"O";
                printf("%s\n",&ans[0]);
            }
        }
    }
    }
}
