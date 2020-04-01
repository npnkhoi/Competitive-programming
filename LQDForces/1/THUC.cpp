#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define FORR(i,a,b) for (int i=(a); i>=(b); --i)
#define REP(i,b) for (int i=0; i<(b); ++i)
#define input stdin
#define output stdout
#define assign freopen
#define endl '\n'
#define sz(x) (int) x.size()
#define div /
#define mod %
#define fillchar(x,y,z) memset(x,z,y)
#define pii pair<int64,int64>
#define fi first
#define se second
#define mp make_pair
#define sqr(x) ((x)*(x))
typedef long long int64;
typedef unsigned long long qword;
typedef void procedure;
using namespace std;
const int maxn=1005;
pii Group[maxn],P[maxn];
int val[maxn],R[maxn];
int n,m;
bool mark[maxn];
procedure Input()
{
    cin >> n;
    FOR(i,1,n) {
        cin >> Group[i].fi >> Group[i].se >> val[i] >> R[i];
    }
    cin >> m;
    FOR(i,1,m)
        cin >> P[i].fi >> P[i].se;
}
pii operator - (pii A, pii B){
    return mp(A.fi-B.fi,A.se-B.se);
}
int64 operator * (pii A, pii B)
{
    return A.fi*B.fi+A.se*B.se;
}
long double dis(pii A, pii B)
{
    return sqrt((A.fi-B.fi)*(A.fi-B.fi)+(A.se-B.se)*(A.se-B.se));
}
long double dis(pii A, int64 a, int64 b, int64 c)
{
    return abs(1.0/(sqrt(a*a+b*b))*(a*A.fi+b*A.se-c));
}
procedure MeoMeo(pii A, pii B)
{
    int64 a=B.se-A.se;
    int64 b=A.fi-B.fi;
    int64 c=a*A.fi+b*A.se;
    FOR(i,1,n) {
        pii C=Group[i];
        long double tmp;
        //CAB>90||CBA>90
        if ((C-A)*(B-A)<0||(C-B)*(A-B)<0)
            tmp=min(dis(A,C),dis(B,C));
        else
            tmp=dis(C,a,b,c);
        if (tmp<=R[i]+1e-8) mark[i]=true;
    }
}
procedure Solve()
{
    if (m==1)
        P[2]=P[1],++m;
    FOR(i,1,m-1) {
        MeoMeo(P[i],P[i+1]);
    }
    int64 res=0;
    FOR(i,1,n)
        res+=val[i]*mark[i];
    cout << res;
}
int main()
{
    // freopen("A.inp", "r", stdin);
    // freopen("thuc.txt", "w", stdout);
    iostream::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Solve();
    return 0;
}