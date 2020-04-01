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
const int oo = 1e8;

struct node {
    int num;
    int lab;
    int point;
    char ch;
    char chpr;
    struct node *a[26];
} *T;

int n;
string s;
string w[1001];
int p[1001];
int dp[101][101];
int g[101][101][3000];
int f[101];
vector <int> v[30];
int cnt = 0;
void init (node *&p,int prev)
{
    p=new node;
    p->num=++cnt;
    p->ch='-';
    p->chpr=27+'a';
    p->point = 0;
    p->lab=prev;
    for (int i=0;i<26;i++)
        p->a[i]=NULL;
}
void add (string s,int po)
{
    node *p=T;
    for (int i=0;i<s.length();i++)
    {
        if (p->a[s[i]-'a']==NULL)
            init(p->a[s[i]-'a'],p->num);
        p=p->a[s[i]-'a'];
        p->ch=s[i];
        if (i==0)
            p->chpr=27+'a';
        else
            p->chpr=s[i-1];
    }
    p->point=max(p->point,po);
}

int Find(string s)
{
    node *p=T;
    for (int i=0;i<s.length();i++)
    {
        if (p->a[s[i]-'a']==NULL )
            return -oo;
        p=p->a[s[i]-'a'];
    }
    return p->point;
}

int locf(int i, int j)
{
    if (i > j) return 0;
    else return dp[i][j];
}
int locg(int i, int j, int h)
{
    //printf("dp3_g\n");
    if (i > j)
        if (h==1)
            return 0;
        else
            return -oo;
    else
        if (h==1)
            return -oo;
        else
            return g[i][j][h];
}
void tinh(int i,int j,node *p)
{
    int h = p->num;
    int pre = p->lab;
    int chprev=p->chpr-'a';
    if (p->num==1 || s[j]==p->ch)
    {
        int st = lower_bound(v[chprev].begin(),v[chprev].end(),i-1)-v[chprev].begin();
        //printf("g[%d][%d][%d]=%d now=%c pre=%d\n",i,j,h,g[i][j][h],p->ch,pre);
        //cout << (char)(p->chpr) << " ";
        //for (int i=0;i<v[chprev].size();i++)
        //    cout << v[chprev][i] << " ";
        //cout << endl;
        //for (int k=st;k<v[chprev].size();k++)
        g[i][j][h]=max(g[i][j][h],locg(i,i-1,pre)+locf(i,j-1));
        //for (int k=i;k<=j;k++)
        for (int k=st;k<v[chprev].size();k++)
            if (v[chprev][k]<=j-1 )
            {
                int jj=v[chprev][k]+1;
                g[i][j][h]=max(g[i][j][h],locg(i,jj-1,pre)+locf(jj,j-1));

            }
            else
                break;
        if (p->point>0)
            dp[i][j]=max(dp[i][j],g[i][j][h]+p->point);
    }
    for (int k=0;k<26;k++)
        if (p->a[k]!=NULL && p->a[k]->ch!='-')
            tinh(i,j,p->a[k]);
}
void sub3()
{
    for( int i=0;i<=s.length();i++)
        for (int j=0;j<=s.length();j++)
        {
            dp[i][j]=-oo;
            for (int k=0;k<=2600;k++)
                    g[i][j][k]=-oo;
        }
    for (int i=s.length()-1;i>=0;i--)
        for (int j=i;j<s.length();j++)
            tinh(i,j,T);
    for (int i=0;i<s.length();i++)
    {
        if (i > 0)
            f[i] = max(0, max(f[i-1], dp[0][i]));
        else
            f[i] = max(0, dp[0][i]);
        for (int j=i;j>=0;j--)
            f[i] = max(f[i], f[j-1] + dp[j][i]);
        }
    cout << f[s.length()-1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("WORD.inp","r",stdin);
    freopen("WORD.ans","w",stdout);
    getline(cin,s);
    for (int i=0;i<s.length();i++)
        v[s[i]-'a'].pb(i);
    cin >> n;
    for (int i=0;i<26;i++)
    {
        v[i].pb(-1);
        sort(v[i].begin(),v[i].end());
    }
    init(T,0);
    memset(g,-1,sizeof(g));
    memset(dp,-1,sizeof(dp));
    for (int i=1;i<=n;i++)
    {
        string pp;
        string x;
        int d = 0;
        cin >> w[i] >> pp;
        for (int j=0;j<pp.length();j++)
            d=d*10+(pp[j]-'0');
        p[i]=d;
        add(w[i],p[i]);
    }
    sub3();
    return 0;
}
