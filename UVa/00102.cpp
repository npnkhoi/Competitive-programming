#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <fstream>
//#include <bits/stdc++.h>
using namespace std;
int a[9];
int sum,res;
string ans;
int main()
{
    //freopen("00102.inp","r",stdin);
    string ans1[6]={"BCG","BGC","CBG","CGB","GBC","GCB"};
    int ans2[6][3]={{0,2,1},{0,1,2},{2,0,1},{2,1,0},{1,0,2},{1,2,0}};
    /*ans2[0]={0,1,2};
    ans2[1]={0,2,1};
    ans2[2]={1,0,2};
    ans2[3]={1,2,0};
    ans2[4]={2,0,1};
    ans2[5]={2,1,0};*/
    while (scanf("%d",&a[0])!=EOF)
    {
        sum=a[0];
        for (int i=1;i<=8;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        res=sum;
        for (int i=0;i<6;i++)
        {
            int tmp=0;
            for (int j=0;j<3;j++) tmp+=a[3*j+ans2[i][j]];
            if (sum-tmp<res)
            {
                ans=ans1[i];
                res=sum-tmp;
            }
        }
        cout<<ans<<' '<<res<<endl;
    }
//ahihi this is the first time I code in Far Manager ahihihihihihi!!!!!!!!!!!!!
    return 0;
}
