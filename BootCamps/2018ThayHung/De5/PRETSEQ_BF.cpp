#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <map>
#include <set>
#include <stack>
#include <queue>

#define FOR(i,x,y) for (int i = x ; i <= y ; i++)
#define ROF(i,x,y) for (int i = x ; i >= y ; i--)
#define REP(i,x)   for (int i = 0 ; i < x ; i++)
#define ll long long
#define ull unsigned long long
#define ii pair <int,int>
#define iii pair <iii,int>
#define fi first
#define se second
#define pb push_back

using namespace std;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
const int oo = 1e9+9;
const int nmax = 1e5+9;

priority_queue <int> pq;
int n,q,ans = 0 ;
int a[nmax],b[nmax],IT[nmax*8],Lazy[nmax*8];
ii ds[nmax];

void down(int id){
    IT[id] += Lazy[id];
    Lazy[id*2] += Lazy[id];
    Lazy[id*2+1] += Lazy[id];
    Lazy[id] = 0 ;
}
void up(int id,int l,int r,int u,int v,int val){
    down(id);
    if (l>v || r<u)
        return;
    if (l>=u && r<=v){
        IT[id] +=val;
        Lazy[id*2] += val;
        Lazy[id*2+1] += val;
        return;
    }
    int mid = (l+r)/2;
    up(id*2,l,mid,u,v,val);
    up(id*2+1,mid+1,r,u,v,val);
    IT[id] = IT[id*2] + IT[id*2+1];
}

int get(int id, int l,int r,int u,int v){
    down(id);
    if (l>v || r<u)
        return 0;
    if (l>=u && r<=v)
        return IT[id];
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}
void Inp(){
    freopen("PRETSEQ.inp","r",stdin);
    freopen("PRETSEQ.ans","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n)
        scanf("%d",&a[i]);
    scanf("%d",&q);
    FOR(i,1,q){
        scanf("%d%d",&ds[i].fi,&ds[i].se);
        b[ds[i].fi]+=1;
        b[ds[i].se+1]-=1;
    }
    return;
}

void Build_B(){
    int x = 0;
    FOR(i,1,n){
        x+=b[i];
        up(1,1,n,i,i,x-a[i]);
    }
}

void Process(){
    Build_B();
    sort(ds+1,ds+q+1);
    int pre = 1;
    FOR(i,1,n){
        while (ds[pre].fi<=i){
            pq.push(ds[pre].se);
            ++pre;
        }
        int val = get(1,1,n,i,i);
        while (val>0){
            -- val;
            up(1,1,n,i,pq.top(),-1);
            pq.pop();
            ++ans;
        }
    }
    cout << ans ;
}
int main(){
    Inp();
    Process();
    return 0;
}
