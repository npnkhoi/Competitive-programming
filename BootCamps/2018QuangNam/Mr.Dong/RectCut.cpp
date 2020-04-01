#include <iostream>
using namespace std;
const int N=1e4+50;
const int oo=1e9;
int a,b,f[N][N];
int main()
{
    cin>>a>>b;
    for (int i=1;i<=a;i++)
        for (int j=1;j<=b;j++)
    {
        if (i==j)
        {
            f[i][j]=1;
            continue;
        }
        int tmp=oo;
        for (int ci=1;ci<i;ci++) tmp=min(tmp,f[ci][j]+f[i-ci][j]);
        for (int cj=1;cj<j;cj++) tmp=min(tmp,f[i][cj]+f[i][j-cj]);
        f[i][j]=tmp;
    }
    cout<<f[a][b];
}
