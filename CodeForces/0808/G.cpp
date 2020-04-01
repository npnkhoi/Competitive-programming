
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s,t;
int n,res,i;
bool ok(int x)
{
    for (int i=0;i<n;i++)
        if ((s[x+i]!=t[i])&&(s[x+i]!='?')) return false;
    return true;
}
int main()
{
    freopen("808G.inp","r",stdin);
    //freopen("","w",stdout);

    //scanf("%s",&s);
    //scanf("%s",&t);
    getline(cin,s); getline(cin,t);
    n=t.size();
    i=0; res=0;
    while (i<s.size())
    {
        if (ok(i)) res++;

    }
    printf("%d",res);
}
