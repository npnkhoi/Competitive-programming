
// THINHK CAREFULLY ... ARE YOU READY !?
#include <stdio.h>
#include <algorithm>
#include <iostream>
//#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define foru(i,a,b) for (int i=a;i<=b;i++)
#define ford(i,a,b) for (int i=a;i>=b;i--)

using namespace std;
//==================<< END OF TEMPLATE >>========================
int a[12][1010],f[12][1010];
int x,tc;
const int oo=1e9;
//--------------<< ENF OF VARIABLES DECLARATION >>---------------

//-------------------<< END OF FUNCTIONS >>---------------------
int main()
{
    //freopen("10337.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&tc);
    while (tc--)
    {
        scanf("%d",&x); x/=100;
        for (int i=9;i>=0;i--)
        for (int j=0;j<x;j++) scanf("%d",&a[i][j]);
        f[0][0]=-a[0][0];
        for (int i=1;i<=9;i++) f[i][0]=oo;
        for (int j=1;j<x;j++)
            for (int i=0;i<=9;i++)
        {
            f[i][j]=f[i][j-1]+30;
            if (i>0) f[i][j]=min(f[i][j],f[i-1][j-1]+60);
            if (i<9) f[i][j]=min(f[i][j],f[i+1][j-1]+20);
            f[i][j]-=a[i][j];
        }
        /*for (int i=9;i>=0;i--)
        {
            for (int j=0;j<x;j++) cout << f[i][j] << "\t";
            cout << endl;
        }*/
        printf("%d\n\n",min(f[0][x-1]+30,f[1][x-1]+20));
    }
    return 0;
}
/* --------------------------<< BACK UP >>-------------------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
