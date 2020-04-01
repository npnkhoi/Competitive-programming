/* <3 <3 <3 */
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i = a ;i <= b ; ++i)
#define ROF(i,a,b) for (int i = a ;i >= b ; --i)
#define REP(i,a) for (int i = 0 ; i < a ; i++)
#define ll long long
#define ull unsigned long long
#define ii pair <int,int>
#define iii pair <ii,int>
#define fi first
#define se second
#define pb push_back
#define pu push
#define debug(x) cerr << #x << " : " << x << "\n"

const int HashMod=1125022017;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int oo = 2e9;
const int nmax = 1e5 + 9;

int n,k;
ll ans = 0;
int a[nmax];
priority_queue <int, vector <int>, greater <int> > q;

void Inp(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("DOLLS.inp","r",stdin);
    freopen("DOLLS.out","w",stdout);
    cin >> n >> k;
    FOR(i,1,n)
        cin >> a[i];
}

void Process(){
    sort(a+1, a+n+1);
    q.push(a[1]);
    FOR(i,2,n){
        if (a[i] - q.top() >= k)
            q.pop(), q.push(a[i]);
    }
    while (!q.empty())
        ans += q.top(), q.pop();
}

int main(){
    Inp();
    Process();
    return 0;
}
