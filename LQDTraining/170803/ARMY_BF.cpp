/* <3 <3 <3 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair <int,int>
#define iii pair <ii,int>
#define iiii pair <ii,ii>
#define dd pair <double,double>
#define fi first
#define se second
#define pb push_back

const int HashMod=1125022017;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int oo = 2e9;
const int nmax=25;

int n;
iiii a[nmax];
int res=0;
double sqr(int u)
{
    return u*u;
}
double dist(int xa,int ya,int xb,int yb)
{
    return sqrt(sqr(xa-xb)+sqr(ya-yb));
}
void ghep(int u,int v)
{
    int xa=a[u].fi.fi;
    int ya=a[u].fi.se;
    int xb=a[u].se.fi;
    int yb=a[u].se.se;
    int xc=a[v].fi.fi;
    int yc=a[v].fi.se;
    int xd=a[v].se.fi;
    int yd=a[v].se.se;
    int A1=ya-yb;
    int B1=xb-xa;
    int A2=yc-yd;
    int B2=xd-xc;
    if (A1*B2!=A2*B1)
        return ;
    int C1=A1*(-xa)+B1*(-ya);
    int C2=A2*(-xc)+B2*(-yc);
    int PC=A1*xc+B1*yc+C1;
    int PD=A1*xd+B1*yd+C1;
    int PA=A2*xa+B2*ya+C2;
    int PB=A2*xb+B2*yb+C2;
    double m=0;
    if (PA*PB<=0 && PC*PD<=0)
    {
        a[u].fi.fi=-1;
        if (dist(xa,ya,xb,yb)>m)
        {
            m=dist(xa,ya,xb,yb);
            a[v].fi.fi=xa;
            a[v].fi.se=ya;
            a[v].se.fi=xb;
            a[v].se.se=yb;
        }
        if (dist(xc,yc,xd,yd)>m)
        {
            m=dist(xc,yc,xd,yd);
            a[v].fi.fi=xc;
            a[v].fi.se=yc;
            a[v].se.fi=xd;
            a[v].se.se=yd;
        }
        if (dist(xa,ya,xc,yc)>m)
        {
            m=dist(xa,ya,xc,yc);
            a[v].fi.fi=xa;
            a[v].fi.se=ya;
            a[v].se.fi=xc;
            a[v].se.se=yc;
        }
        if (dist(xa,ya,xd,yd)>m)
        {
            m=dist(xa,ya,xd,yd);
            a[v].fi.fi=xa;
            a[v].fi.se=ya;
            a[v].se.fi=xd;
            a[v].se.se=yd;
        }
        if (dist(xb,yb,xc,yc)>m)
        {
            m=dist(xb,yb,xc,yc);
            a[v].fi.fi=xb;
            a[v].fi.se=yb;
            a[v].se.fi=xc;
            a[v].se.se=yc;
        }
        if (dist(xb,yb,xd,yd)>m)
        {
            m=dist(xb,yb,xd,yd);
            a[v].fi.fi=xb;
            a[v].fi.se=yb;
            a[v].se.fi=xd;
            a[v].se.se=yd;
        }
    }
}
bool cat(int u,int v)
{
    int xa=a[u].fi.fi;
    int ya=a[u].fi.se;
    int xb=a[u].se.fi;
    int yb=a[u].se.se;
    int xc=a[v].fi.fi;
    int yc=a[v].fi.se;
    int xd=a[v].se.fi;
    int yd=a[v].se.se;
    if (xa==-1 || xb==-1)
        return 0;
    int A1=ya-yb;
    int B1=xb-xa;
    int A2=yc-yd;
    int B2=xd-xc;
    if (A1*B2==A2*B1)
        return 0;
    int C1=A1*(-xa)+B1*(-ya);
    int C2=A2*(-xc)+B2*(-yc);
    int PC=A1*xc+B1*yc+C1;
    int PD=A1*xd+B1*yd+C1;
    int PA=A2*xa+B2*ya+C2;
    int PB=A2*xb+B2*yb+C2;
    return PC*PD<=0 && PA*PB<=0;
}

dd gd(int u,int v)
{
    int xa=a[u].fi.fi;
    int ya=a[u].fi.se;
    int xb=a[u].se.fi;
    int yb=a[u].se.se;
    int xc=a[v].fi.fi;
    int yc=a[v].fi.se;
    int xd=a[v].se.fi;
    int yd=a[v].se.se;
    int A1=ya-yb;
    int B1=xb-xa;
    int A2=yc-yd;
    int B2=xd-xc;
    int C1=A1*(-xa)+B1*(-ya);
    int C2=A2*(-xc)+B2*(-yc);
    int D=A1*B2-A2*B1;
    double Dx=A1*C2-A2*C1;
    double Dy=C1*B2-C2*B1;
    return dd(Dx/D,Dy/D);

}
void xuat(int u)
{
    cout << a[u].fi.fi << " " << a[u].fi.se << " " << a[u].se.fi << " " << a[u].se.se << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("ARMY.inp","r",stdin);
    freopen("ARMY.ans","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se.fi >> a[i].se.se;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            if (i==-1)
                break;
            ghep(i,j);
        }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            for (int k=j+1;k<=n;k++)
                if (cat(i,j) && cat(i,k) && cat(j,k) && gd(i,j)!=gd(i,k))
                    res+=1;
    cout << res;
    return 0;
}
