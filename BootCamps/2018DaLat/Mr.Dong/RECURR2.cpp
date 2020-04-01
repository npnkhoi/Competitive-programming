/* <3 <3 <3 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int HashMod=1125022017;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int oo = 2e9;

struct Matrix{
    int m[51][51];
};

int c[51];
int a[51];
int n,d;
int t;
bool Ok=false;
Matrix G;

Matrix Mul(Matrix A,Matrix B)
{
    Matrix C;
    for (int i=1;i<=d;i++)
        for (int j=1;j<=d;j++)
        {
            C.m[i][j]=0;
            for (int k=1;k<=d;k++)
            {
                C.m[i][j]+=A.m[i][k]*B.m[k][j];
                C.m[i][j]%=3;
            }
        }
    return C;
}

Matrix Pow(Matrix a,int n)
{
    //cerr << n << endl;
    if (n==1)
        return a;
    Matrix t = Pow(a,n/2);
    t=Mul(t,t);
    if (n%2==0)
        return t;
    return Mul(t,a);
}
void check()
{
    Matrix A ;
    for (int i=1;i<=d;i++)
        for (int j=1;j<=d;j++)
            A.m[i][j]=0;
    for (int i=1;i<=d;i++)
    {
        A.m[1][i]=c[i];

    }
    A=Mul(A,G);
    for (int i=1;i<=d;i++)
    {
        if (A.m[1][i]!=a[i] && a[i]!=-1)
        {
            return ;
        }
    }
    for (int i=1;i<=d;i++)
        cout << c[i] << " ";
    Ok=true;

}
void Try(int i)
{
    if (Ok)
        return;
    if (i>d)
        check();
    else
        for (int j=0;j<=2;j++)
        {
            c[i]=j;
            Try(i+1);
        }
}
int main()
{
    freopen("RECURR.inp","r",stdin);
    //freopen("RECURR.ans","w",stdout);
    cin >> t;
    //cout << t << endl;
    while (t--)
    {
        Ok=false;
        cin >> n >> d;
        //cout << n << d << endl;
        for (int i=1;i<=d;i++) {
            cin >> a[i];
            //cout << i << " " << a[i] << endl;
        }
        //cout << n << endl;
        //cout << "ok\n";
        for (int i=1;i<=d;i++)
            for (int j=1;j<=d;j++)
                G.m[i][j]=0;
        //cout << "ok\n";
        for (int i=1;i<=d;i++)
            G.m[i][i-1]=1;
        //cout << "ok\n";
        for (int i=1;i<=d;i++)
            G.m[i][d]=1;
        //cout << "ok\n";
        if (n==1)
        {
            for (int i=1;i<=d;i++)
                cout << a[i] << " ";
            cout << endl;
            continue;
        }
        //cout << "ok\n";

        G=Pow(G,n-1);
        //cout << "ok\n";
        Try(1);
    }

    return 0;
}
