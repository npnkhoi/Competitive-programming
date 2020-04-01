/**Coder Khỏe ♥♥♥ Code Vui**/
#include<bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define li pair<long long, int>
#define si pair<string, int>
#define is pair<int, string>
#define ci pair<char, int>
#define ic pair<int, char>
#define iii pair<pair<int, int>, int>
#define fi first
#define se second
#define FOR(i,x,y) for (int i=x; i<=y; i++)
#define FOD(i,x,y) for (int i=x; i>=y; i--)

const int oo=1e9+9;
const int nmax=1e4+9;
const int mmax=59;
const int cot[4]={0, 0, -1, 1};
const int dong[4]={-1, 1, 0, 0};
int n, m, a[nmax][mmax];
int dp[nmax][nmax], sum[nmax], pre[nmax][mmax];
//------------------------------------------
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("meadow.inp",  "r", stdin);
    freopen("meadow.ans", "w", stdout);
    cin>>n>>m;
    FOR(i,1,n)
    {
        string s;
        cin>>s;
        FOR(j,1,m)
        {
            a[i][j]=s[j-1]-'0';
            sum[i]+=a[i][j];
            if (a[i][j]==1) pre[i][j]=m*(i-1)+j;
        }
    }
    int res=0;
    FOR(i,1,n)
    {
        int S=0;
        FOR(j,1,n)
        {
            FOR(k,1,m)
            {
                if (a[j][k]==1) pre[j][k]=m*(j-1)+k;
            }
        }
        FOR(j,i,n)
        {
            S+=sum[j];
            if (i==j)
            {
                FOR(k,2,m)
                {
                    if (a[i][k]==1)
                    {
                        if (a[i][k-1]==1)
                        {
                            S--;
                            pre[i][k]=pre[i][k-1];
                        }
                    }
                }
                dp[i][j]=S;
                res=res+S;
                continue;
            }
            FOR(k,1,m)
            {
                if (a[j][k]==1)
                {
                    if (a[j-1][k]==1)
                    {
                        S--;
                        pre[j][k]=pre[j-1][k];
                    }
                }
            }
            FOR(k,2,m)
            {
                if (a[j][k]==1)
                {
                    if (a[j][k-1]==1 && pre[j][k]!=pre[j][k-1])
                    {
                        if (a[j-1][k]==1 && a[j-1][k-1]==1)
                        {
                            pre[j][k]=min(pre[j][k-1], pre[j][k]);
                            pre[j][k-1]=pre[j][k];
                            continue;
                        }
                        S--;
                        pre[j][k]=min(pre[j][k-1], pre[j][k]);
                        pre[j][k-1]=pre[j][k];
                    }
                }
            }
            dp[i][j]=S;
            res=res+S;
        }
    }
    cout<<res<<endl;
    return 0;
}


