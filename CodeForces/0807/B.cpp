#include <bits/stdc++.h>
using namespace std;
int p,x,y,s;
bool win(int n)
{
    int i=(s/50)%475;
    for (int j=1;j<=25;j++)
    {
        i= (i * 96 + 42) % 475;
        if (26+i==p) return 1;
    }
    return 0;
}
int main()
{
    //freopen("807B.inp","r",stdin);
    cin>>p>>x>>y;
    s=y-1;
    while (++s)
    {
        if ((s%50)!=(x%50)) continue;
        //cout<<s<<"\t";
        if (win(s))
        {
            printf("%d\n",(max(0,s-x)+50)/100);
            break;
        }
    }
}
