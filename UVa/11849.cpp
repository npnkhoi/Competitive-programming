#include <set>
#include <stdio.h>
using namespace std;
set<int> data;
int m,n,x,res;
int main()
{
    while (1)
    {
        scanf("%d%d",&m,&n);
        if (m==0&&n==0) break;
        data.clear();
        res=0;
        while (m--)
        {
            scanf("%d",&x);
            data.insert(x);
        }
        while (n--)
        {
            scanf("%d",&x);
            res+= (data.find(x)!=data.end());
        }
        printf("%d\n",res);
    }
}
