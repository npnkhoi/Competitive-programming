//#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>

#define ll long long

using namespace std;

int main()
{
    //freopen("consesnk.inp","r",stdin);
    //freopen("","w",stdout);
    const int N=1e5+50;
    ll tc,n,l,a,b,lo,hi,s[N],s1,s2,x;
    scanf("%lld",&tc);
    while (tc--)
    {
        scanf("%lld%lld%lld%lld",&n,&l,&a,&b);
        lo=a-l; hi=b-(n+1)*l;
        //-----------------------------
        for (int i=1;i<=n;i++) scanf("%lld",&s[i]);
        sort(s+1,s+n+1);
        for (ll i=1;i<=n;i++)
        {
            s[i]-=l*i;
            //cout<<s[i]<<endl;
        }
        sort(s+1,s+n+1);
        //for (int i=1;i<=n;i++) cout<<s[i]<<" "; cout<<endl;
        //------------------------------
        s1=s[n/2]; s2=s[(n+1)/2];
        if (hi<s1) x=hi;
        else if (s2<lo) x=lo;
        else x=s1;
        ll res=0;
        for (int i=1;i<=n;i++) res+=abs(x-s[i]);
        printf("%lld\n",res);
    }
}
