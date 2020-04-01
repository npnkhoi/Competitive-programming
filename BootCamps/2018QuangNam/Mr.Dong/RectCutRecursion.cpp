#include <iostream>
#include <string.h>
using namespace std;
int const N=1e4+50;
int a,b,f[N][N],tc;
int sol(int a, int b)
{
    //cout<<a<<" "<<b<<endl;
    if (f[a][b]>-1) return f[a][b];
    if (a>b) return sol(b,a);
    if (a==b)
    {
        f[a][b]=1;
        return 1;
    }
    int res=a*b;
    for (int ca=1;ca<=a/2;ca++) res=min(res,sol(ca,b)+sol(a-ca,b));
    for (int cb=1;cb<=b/2;cb++) res=min(res,sol(a,cb)+sol(a,b-cb));
    f[a][b]=res;
    return res;
}
int main()
{
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) f[i][j]=-1;
    cin>>tc;
    while (tc--)
    {
        cin>>a>>b;
        cout<<sol(a,b);
    }
}
