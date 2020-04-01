#include <bits/stdc++.h>
using namespace std;
const int md=1000000007;

long long tc,n,x,sum,pro,res,lt;
int main()
{
    //freopen("plusmul.inp","r",stdin);
    cin>>tc;
    while (tc--)
    {
        cin>>n;
        cin>>x;
        sum=x; pro=x; res=x; lt=1;

        for (int i=2;i<=n;i++)
        {
            cin>>x;
            pro=((pro*x)%md+(x*lt)%md)%md;
            res=(sum+pro)%md;
            sum=(sum+res)%md;
            //printf("%lld %lld %lld %lld\n",lt,pro,res,sum);
            lt=(lt*2)%md;
        }
        cout << res <<endl;
    }
}
