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
const int nmax=1501;

vector <int> v[nmax*nmax];
vector <int> app;

int l[nmax*nmax],r[nmax*nmax],d[nmax*nmax];
int b[nmax*nmax];
int ans[2*nmax];

int n;
void Inp(){
    freopen("FASTFOOD.inp","r",stdin);
    freopen("FASTFOOD.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n)
        FOR(j,1,n){
            int x;
            scanf("%d",&x);
            if (b[x] == 0){
                b[x] = 1;
                app.pb(x);
            }
            v[x].pb(j);
        }
    return;
}

void Proc(int id){
    FOR(i,0,v[id].size()+1)
        l[i] = 0 , r[i] = 0, d[i] = 0;
    int R = 0;
    REP(i,v[id].size()){
        int L_ = 1;
        int R_ = R;
        while (L_<=R_){
            int mid = (L_+R_)/2;
            if (l[mid] > v[id][i])
                R_ = mid - 1;
            else
                L_ = mid + 1;
        }
        l[L_] = v[id][i];
        d[i] += L_;
        R = max (R,L_);
    }
    R = 0;
    ROF(i,v[id].size()-1,0){
        int L_ = 1;
        int R_ = R;
        while (L_<=R_){
            int mid = (L_+R_)/2;
            if (r[mid] < v[id][i])
                R_ = mid - 1;
            else
                L_ = mid + 1;
        }
        ans[d[i] + L_ - 1] += 1;
        r[L_] = v[id][i];
        R = max (R,L_);
    }
}
void Process(){
    REP(i,app.size()){
        Proc(app[i]);
    }
    FOR(i,1,2*n-1)
        printf("%d ",ans[i]);
}
int main(){
    Inp();
    Process();
    return 0;
}
