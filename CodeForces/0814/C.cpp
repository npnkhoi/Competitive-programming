
using namespace std;

#include <stdio.h>
#include <algorithm>
#include <iostream>
const int N=1510;
int n,q;
char str[N];
int f[N],dp[N][30];
int main()
{
    scanf("%d",&n);
    scanf("%s",&str);
    for (int x=0;x<26;x++)
    {
        char ch=x+'a';
        //cout << ch << endl;
        int m_max=0;
        f[0]=-1;
        for (int i=0;i<n;i++)
        if (str[i]!=ch)
        {
            m_max++;
            f[m_max]=i;
        }
        f[m_max+1]=n;
        for (int m=1;m<=n;m++)
            if (m>=m_max) dp[m][x]=n;
        else
        {
            int res=0;
            for (int i=m;i<=m_max;i++) res=max(res,f[i+1]-1-f[i-m]);
            dp[m][x]=res;
        }
    }
    scanf("%d",&q);
    while (q--)
    {
        int m_;
        char ch_;
        scanf("%d %c",&m_,&ch_);
        printf("%d\n",dp[m_][ch_-'a']);
    }
}
