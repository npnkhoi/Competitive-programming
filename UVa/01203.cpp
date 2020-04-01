using namespace std;
#include <stdio.h>
#include <iostream>
#include <queue>
#define fi first
#define se second
bool Greater(pair<int, int> x, pair<int, int> y)
{
    if (x.fi != y.fi) return x.fi > y.fi;
    else return x.se > y.se;
}
typedef pair<int, int> p;
priority_queue<p, vector <p>, greater<p>> pq;
const int N = 3e3 +50;
int id[N], a[N];
int n, m;
//char str[20], tmp[20];
string str;

long long f(int x)
{
    long long s = 0;
    for (int i = 1; i <= n; i++)
        s += 1LL*x/a[i];
    //printf("f(%d) = %lld\n",x,s);
    return s;
}
int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    n = 0;
    while (1)
    {
        cin >> str;
        if (str=="#") break;
        n++;
        scanf("%d %d",&id[n], &a[n]);
        //cout << str << endl;
    }
    scanf("%d",&m);
    long long l, r, mid;
    l = 1; r = 1LL * a[1] * m;
    //cout << r << endl;
    while (l<r)
    {
        mid = (l + r) / 2;
        if (f(mid) >= m) r = mid;
        else l = mid + 1;
    }
    //cout << l << endl;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= l/a[i]; j++)
    {
        pq.push(make_pair(a[i]*j,id[i]));
        //printf(" %d %d \n",a[i]*j,-id[i]);
    }

    //for (auto it = pq.begin();it!=pq.end(   );it++) cout << *it << " ";
    while (m--)
    {
        printf("%d\n", pq.top().se);
        pq.pop();
    }
}
