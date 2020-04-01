/* <3 <3 <3 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair <int,int>
#define iii pair <ii,int>
#define fi first
#define se second
#define pb push_back

const int HashMod=1125022017;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int oo = 2e9;
const int nmax=1000;

int a[nmax];
int c[nmax];
int tmp[nmax];
int ma[1000][1000];

int ans = 0;
int n,m,k;
int K;
void check()
{
    for (int i=m+1;i<=m*n;i++)
        tmp[i]=c[i]=0;
    for (int i=1;i<=m;i++)
    {
        tmp[i]=(c[i-1]+c[i+1])%2;
        if (tmp[i]!=a[i])
            return;
    }
    for (int i=m+1;i<=m*n;i++)
    {
        tmp[i]=(c[i-m])%2;
        if (i%m!=1)
            tmp[i]+=c[i-1];
        if (i%m!=0)
            tmp[i]+=c[i+1];
        tmp[i]%=2;
        if (tmp[i]!=a[i])
        {
            c[i+m]=1;
            if (i+m>m*n)
                return;
            tmp[i]=a[i];
        }
    }
    for (int i=1;i<=m*n;i++)
        if (a[i]!=tmp[i])
            return ;

    ans+=1;
}
void Try(int i)
{
    if (i>m)
        check();
    else
        for (int j=0;j<=1;j++)
        {
            c[i]=j;
            Try(i+1);
        }
}

void check1()
{
    for (int i=1;i<=m*n;i++)
        if (a[i]!=-1 && tmp[i]%2!=a[i])
            return;
    ans+=1;
}
void Try1(int i)
{
    if (i>m*n)
        check1();
    else
        for (int j=0;j<=1;j++)
        {
            c[i]=j;
            if(i-m>0)
                tmp[i-m]+=j;
            if (i+m<=n*m)
                tmp[i+m]+=j;
            if (i%m!=0)
                tmp[i+1]+=j;
            if (i%m!=1)
                tmp[i-1]+=j;
            Try1(i+1);
            if(i-m>0)
                tmp[i-m]-=j;
            if (i+m<=n*m)
                tmp[i+m]-=j;
            if (i%m!=0)
                tmp[i+1]-=j;
            if (i%m!=1)
                tmp[i-1]-=j;
        }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("BOMB.inp","r",stdin);
    freopen("BOMB.ans","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin >> a[(i-1)*m+j];
    for (int i=1;i<=n*m;i++)
    {
        if (a[i]!=-1)
        {
            ++k;
            for (int j=1;j<=m*n;j++)
                if ((i-1 == j && i%m!=1) || (i+1==j && i%m!=0) || i-m == j || i+m == j)
                    ma[k][j]=1;
            ma[k][m*n+1]=a[i];
        }
    }
    K=k;
    for (int i=1;i<=k;i++)
    {
        int c = -1;
        for (int j=1;j<=m*n;j++)
            if (ma[i][j]==1)
            {
                c = j;
                break;
            }
        if (c==-1)
            if (ma[i][m*n+1]==0)
            {
                K-=1;
                continue;
            }
            else
            {
                //cout << i  << endl;
                cout << "0";
                return 0;
            }
        for (int j = i+1;j<=k;j++)
            if (ma[j][c]==1)
            {
                for (int t=1;t<=m*n+1;t++)
                    ma[j][t]=(ma[j][t]+ma[i][t])%2;
            }
    }
    cout << (1LL<<(m*n-K));
    return 0;
}
