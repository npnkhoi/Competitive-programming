#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
struct mobile
{
    string m;
    int l,h;
};
int T,d,q,p;
struct mobile a[10005];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&d);
        string line;
        getline(cin,line);

        //--------------
        scanf("%d",&q);
        for (int i=1;i<=q;i++)
        {
            scanf("%d",&p);
            int cnt=0;
            string ans="";
            for (int j=1;j<=d;j++)
                if ((a[j].l<=p)&&(p<=a[j].h))
                {
                    {
                        cnt++;
                        ans=a[j].m;
                    }
                }
            if (cnt==1) printf("%s",ans.c_str());
            else printf("UNDETERMINED");
        }
    }

}
