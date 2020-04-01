#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define foru(i,a,b) for (int i=a;i<=b;i++)
#define ford(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int x1,x2,y1,y2,x,y,a,b;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    scanf("%d%d",&a,&b);
    x=(x1-x2)/a;
    y=(y1-y2)/b;
    if (((x-y)%2)||((x1-x2)%a!=0||(y1-y2)%b!=0)) printf("NO"); else printf("YES");
    return 0;
}
/* --------------------------<< BACK UP >>-------------------------

*/
