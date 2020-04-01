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

struct rec{
    int x,y,z;
};

ll ans = 0;
ll sum = 0 ;
int n;
rec a[nmax];
int Ly[nmax],Ry[nmax],Lz[nmax],Rz[nmax];
void Inp(){
    freopen("CINEMA.inp","r",stdin);
    freopen("CINEMA.ans","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        a[i].z-=a[i].x;
        a[i].y-=a[i].x;
        sum += a[i].x * 1LL;
        Ly[i] = Ry[i] = Lz[i] = Rz[i] = -oo ;
    }
    return;
}

void Process(){
    Ly[0] = -oo;
    Lz[0] = -oo;
    Ry[n+1] = -oo;
    Rz[n+1] = -oo;
    FOR(i,1,n){
        Ly[i] = max(Ly[i-1],a[i].y);
        Lz[i] = max(Lz[i-1],a[i].z);
    }
    ROF(i,n,1){
        Ry[i] = max(Ry[i+1],a[i].y);
        Rz[i] = max(Rz[i+1],a[i].z);
    }
    FOR(i,1,n){
        ans = max(ans, a[i].y*1LL + 1LL*max(Lz[i-1],Rz[i+1]));
        ans = max(ans, a[i].z*1LL + 1LL*max(Ly[i-1],Ry[i+1]));
    }
    printf("%lld",1LL*ans+sum);
}
int main(){
    Inp();
    Process();
    return 0;
}
