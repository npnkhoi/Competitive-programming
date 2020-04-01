using namespace std;
#include <stdio.h>
#include <map>
int tc, n, x, res, cnt;
map<int, int> data;
const int N = 1e6 +10;
int a[N];
int main()
{
    //freopen("11572.inp","r",stdin);
    //freopen("11572.out","w",stdout);
    scanf("%d",&tc);
    while (tc--)
    {
        scanf("%d",&n);
        res=0; cnt=0;
        int pre=0;
        data.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if (data.count(a[i]))
            {
                x=data[a[i]];
                do
                {
                    pre++;
                    data.erase(a[pre]);
                } while (pre<x);
            }
            data[a[i]]=i;
            res=max(res,i-pre);
            //printf("%d %d\n",pre,i);
        }
        printf("%d\n",res);
    }
}
