
// THINHK CAREFULLY ... ARE YOU READY !?

//#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define foru(i,a,b) for (int i=a;i<=b;i++)
#define ford(i,a,b) for (int i=a;i>=b;i--)

using namespace std;
//==================<< END OF TEMPLATE >>========================
int n,m,k;
ll f[52][52];
//--------------<< ENF OF VARIABLES DECLARATION >>---------------

//-------------------<< END OF FUNCTIONS >>---------------------
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    while (scanf("%d%d%d",&n,&k,&m)!=EOF)
    {
        f[0][0]=1;
        for (int i=1;i<=n;i++) f[i][0]=0;

        for (int i=1;i<=n;i++)
        for (int j=1;j<=min(k,i);j++)
            {
                f[i][j]=0;
                for (int x=max(j-1,i-m);x<i;x++) f[i][j]+=f[x][j-1];
            }
        /*for (int i=0;i<=n;i++)
        {
            for (int j=0;j<=k;j++) cout << f[i][j] << "\t";
            cout << endl;
        }*/
        printf("%lld\n",f[n][k]);
    }
    return 0;
}
/* --------------------------<< BACK UP >>-------------------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
