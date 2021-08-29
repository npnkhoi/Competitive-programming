#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str1[15],str2[15];
int n,a[30][30][30][30];
long long res;
int main()
{
    //freopen("B.inp","r",stdin);
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    while (n--)
    {
        scanf("%s",&str1);
        scanf("%s",&str2);
        //cout << str << endl;
        //cout << str1 << " " << str2 << endl;
        //cout << str1[0]-'A'<< str1[1]-'A' << str2[0]-'A'<< str2[1]-'A' << endl;
        if (str1[0]==str2[0]&&str1[1]==str2[1]) continue;
        res+= a[str2[0]-'A'][str2[1]-'A'][str1[0]-'A'][str1[1]-'A'];
        a[str1[0]-'A'][str1[1]-'A'][str2[0]-'A'][str2[1]-'A']++;

    }
    /*res=0;
    for (int i=0;i<26;i++)
        for (int j=0;j<26;j++)
            for (int k=0;k<26;k++)
            for (int l=0;l<26;l++)
        {
            int x=a[i][j][k][l];
            //if (a[i][j][k][l]>0) cout << x << endl;
            res+=x*(x-1)/2;
        }*/
    cout << res;
    return 0;
}
