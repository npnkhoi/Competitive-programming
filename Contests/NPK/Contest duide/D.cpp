
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct rc
{
    long long x,y;
};
int n;
rc a[1010];
bool Free[1010];
long long l,r,mid;
vector<int> v;


bool inrange(int u, int v)
{
    return
    ((a[u].x-a[v].x)*(a[u].x-a[v].x)+(a[u].y-a[v].y)*(a[u].y-a[v].y)) <= mid;
}
void flood(int i)
{
    //cout << i << endl;
    int u=v[i];
    v.erase(v.begin()+i);
    //for (int j=0;j<v.size();j++) cout << v[j] << " ";
    //cout << endl;
    for (int j=0;j<v.size();j++) if (inrange(v[j],u)) flood(j);
}
bool ok()
{
    for (int i=1;i<=n;i++)
    {
        v.clear();
        for (int j=1;j<=n;j++) v.push_back(j);
        flood(i-1);
        if (v.empty()) return 1;
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lld%lld",&a[i].x,&a[i].y);
    l=0; r=1250000000+10;
    while (l<r)
    {
        mid= (l+r)/2;
        //cout <<"case: " <<mid<< endl;
        if (ok()) r=mid; else l=mid+1;
    }
    printf("%lld",l);
    //for (int i=0;i<=n;i++) cout << groupof[i] << " ";
}

/*
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct rc
{
    int x,y;
};
int n;
rc a[1010];
long long tmp,res;


long long dist(int u, int v)
{
    return (a[u].x-a[v].x)*(a[u].x-a[v].x)+(a[u].y-a[v].y)*(a[u].y-a[v].y);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    long long res = 1e11;
    for (int i=1;i<=n;i++)
    {
        tmp=0;
        for (int j=1;j<=n;j++) tmp=max(tmp,dist(i,j));
        res=min(res,tmp);
    }
    cout << res<< endl;
    //for (int i=0;i<=n;i++) cout << groupof[i] << " ";
}

*/
