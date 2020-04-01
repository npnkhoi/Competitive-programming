/* <3 <3 <3 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair <ll,ll>
#define iii pair <ii,int>
#define fi first
#define se second
#define pb push_back

const int HashMod=1125022017;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int oo = 2e9;
const int nmax=1e5+9;
struct node{
    int val, upd, lazy;
}
node IT[nmax*8];

iii a[nmax];
ii b[nmax];

int n,m;
void Down(int p, int l, int r) {
    lazy[2*p] =
}
void Update(int p, int l, int r, int L, int R, int k)
{
    Down(p, l, r);
    if (l > r || L > R || l > R || L > r) return;
    if (L <= l && r <= R && IT[p].upd == 0) {
        IT[p].upd = r-l+1;
        int mi = (l+r)/2;
        lazy[2*p] = mi - l + 1;
        lazy[2*p+1] = r - mi;
    }
    if (IT[p].upd == 0) {
        IT[p].udp =
    }
    else {
        int mi = (l+r)/2;
        update(2*p, l, mi, L, R, k);
        update(2*p+1, mi+1, r, L, R, k);
        IT[p].udp = IT[2*p].udp + IT[2*p+1].upd;
    }
}
int query(int p, int l, int r, int idx) {
    Down(p);
    if (l < r || i < l || r < i) return -1;
    if (l == r) return IT[p].val;
    else {
        int mi = (l+r)/2;
        int ans1 = query(2*p, l, mi, idx);
        int ans2 = query(2*p+1, mi+1, r, idx);
        if (ans1 == -1) return ans2;
        else return ans1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("Test.inp","r",stdin);
    //freopen("Test.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        string x,y;
        ll c=0;
        ll e=0;
        ll t=0;
        cin >> y;
        //cout << y << " " ;
        cin >> x;
        //cout << x << " " ;
        cin >> x;
        //cout << x << "\n";
        bool ok = false;
        int lt=4;
        for (int j=0;j<x.length();j++)
        {
            if (x[j]=='/')
            {
                lt-=1;
                c+=(1LL<<(8LL*lt))*t;
                ok=true;
                continue;
            }
            if (x[j]=='.')
            {
                lt-=1;
                c+=(1LL<<(8LL*lt))*t;
                t=0;
                continue;
            }
            t=t*10+x[j]-'0';
            //cout << t << " " ;
        }
        //cout << endl;
        if (ok==false)
        {
            c+=t;
            e=c;
        }
        else
        {
            e=c+(1LL<<t);
        }
        a[i].fi.fi=c;
        a[i].fi.se=e;
        a[i].se=(y=="allow");
    }
    for (int i=1;i<=n;i++)
        cout << a[i].fi.fi << " " << a[i].fi.se << " " << a[i].se << endl;
    cin >> m;
    for (int i=1;i<=m;i++)
    {
        b[i].fi=0;
        string x;
        cin >> x;
        ll t=0;
        ll c=0;
        ll lt= 4;
        for (int j=0;j<x.length();j++)
        {
            if (x[j]=='.')
            {
                lt-=1;
                c+=(1LL<<(8LL*lt))*t;
                t=0;
                continue;
            }
            t=t*10+x[j]-'0';
        }
        b[i].fi=c+t;
        b[i].se=i;
        cout << b[i] << " ";
    }
    sort(b+1,b+m+1,comp);
    Update(1,1,m,l,r,-1);
    for (int i=1;i<=n;i++)
    {
        int ok=a[i].se;
        int l = Find1(a[i].fi.fi);
        int r = Find2(a[i].fi.se);
        Update(1,1,m,l,r,ok);
    }
    return 0;
}
