#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#define ll long long

using namespace std;
int tc,n,m,a,b;
char ch;
bool rot;
void show(int x, int y, int u, int v)
{
    if (rot) printf("%d %d %d %d\n",y,x,v,u);
    else printf("%d %d %d %d\n",x,y,u,v);
}
void down(int x, int y)
{
    //printf("down %d %d:\n",x,y);
    for (int u=x+1;u<=n;u++)
        show(u-1,y,u,y);
}
void right(int x, int y)
{
    //printf("right %d %d:\n",x,y);
    for (int v=y+1;v<=m-2;v++)
        show(x,v-1,x,v);
}
void init()
{

    for (int u=a+1;u<=n;u++) show(u,b,u-1,b);
    for (int v=b+1;v<=m;v++) show(n,v,n,v-1);
}
void clear_left()
{
    for (int i=n;i>=1;i--)
    for (int j=m-2;j>=1;j--)
    {
        //cout<<i<<" "<<j<<": "<<endl;
        down(i,j);
        right(n,j);
        show(n,m-2,n,m);
        show(n,m,n,m-1);
    }
}
void clear_right()
{
    for (int u=n-1;u>=1;u--)
    {
        down(u,m-1);
        show(n,m-2,n,m);
        show(n,m,n,m-1);
        show(n,m-1,n,m-2);
    }
    for (int u=n-1;u>=1;u--)
    {
        show(u,m,u,m-1);
        down(u,m-1);
        show(n,m-2,n,m);
        show(n,m,n,m-1);
        show(n,m-1,n,m-2);

    }
}
int main()
{
    //freopen("gameball.inp","r",stdin);
    //freopen("gameball.out","w",stdout);
    scanf("%d",&tc);
    //cout<<tc<<endl;
    while (tc--)
    {
        scanf("%d%d",&n,&m);
        if (m<=2) rot=1; else rot=0; //rotate
        //------------------------------------
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
        {
            cin>>ch;
            if (ch=='.')
            {
                a=i; b=j;
            }
        }
        //printf("%d %d %d %d\n",n,m,a,b);
        if ((m<=2)&&(n<=2))
        {
            printf("-1\n");
            continue;
        }
        if (rot)
        {
            int t;
            t=a; a=b; b=t;
            t=m; m=n; n=t;
        }
        //----------------------------------
        int res=n+m-a-b;
        for (int i=0;i<n;i++)
            for (int j=0;j<m-2;j++) res+=i+j+2;
        res++;
        for (int i=1;i<n;i++) res+=i+i+7;
        printf("%d\n",res);
        init();
        //cout<<"clr_left"<<endl;
        clear_left();
        //cout<<endl;
        show(n,m-1,n,m-2);
        //cout<<"clr_right"<<endl;
        clear_right();
    }
}
