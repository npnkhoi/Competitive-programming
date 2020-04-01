#include<bits/stdc++.h>
using namespace std;

#define FOR(i,x,n) for(int i=x;i<=n;i++)
#define REP(i,x) for(int i=0;i<x;i++)
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >
#define fi first
#define se second
#define fr front()
#define t top()
#define pb push_back
#define pp pop_back
#define lli long long int
#define li long int
#define ld long double
#define vi vector<int>
#define vii vector<ii>
#define viii vector<iii>
#define viv vector<iv>
#define qi queue<int>
#define qii queue<ii>
#define qiii queue<iii>
#define qiv queue<iv>
#define si stack<int>
#define sii stack<ii>
#define oo 999999999
#define N 200005

int st[4*N],n,m;
int res;

void up(int id,int l,int r,int i,int v)
{
    if(l>i || r<i)
        return;
    st[id]=min(st[id],v);
    if(l==r)
        return;
    int mid=(l+r)/2;
    up(id*2,l,mid,i,v);
    up(id*2+1,mid+1,r,i,v);
}

void get(int id,int l,int r,int u,int v,int val)
{
    if(res!=-1)
        return;
    if(r<u || l>v )
        return;
    else if(l>=u && r<=v)
    {
        if(st[id]>val)
            return;
        if(l==r)
        {
            res=l;
            return;
        }
    }
     int mid=(l+r)/2;
        get(id*2,l,mid,u,v,val);
        get(id*2+1,mid+1,r,u,v,val);
}

int main()
{
    freopen("DADY.inp","r",stdin);
    freopen("DADY.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(st,0x1f,sizeof(st));
    cin>>n>>m;
    while(m--)
    {
        char f;int x,y;
        cin>>f>>x>>y;
        if(f=='M')
            up(1,1,n,y,x);
        else
        {
            res=-1;
            get(1,1,n,y,n,x);
            cout<<res<<endl;
        }
    }
}
