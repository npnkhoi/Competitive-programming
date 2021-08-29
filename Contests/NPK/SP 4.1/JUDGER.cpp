using namespace std;
#include <stdio.h>
#include <map>
#include <set>
multiset<long long> score;
map<int, long long> data;
int n,m;
int x,y,cmd;
void do1()
{
    scanf("%d",&x);
    if (data.find(x)==data.end())
    {
        data[x]=0;
        score.insert(0);
        /*for (multiset<long long>::iterator it = score.begin();
        it!=score.end();it++) printf("%lld ",*it);
        printf("+++\n");*/
    }
}
void do2()
{
    scanf("%d",&x);
    if (data.find(x)!=data.end())
    {
        score.erase(score.lower_bound(data[x]));
        data.erase(x);
        /*for (multiset<long long>::iterator it = score.begin();
        it!=score.end();it++) printf("%lld ",*it);
        printf("---\n");*/
    }
}
void do3()
{
    scanf("%d%d",&x,&y);
    if (data.find(x)!=data.end())
    {
        score.erase(score.lower_bound(data[x]));
        data[x]+=1LL*y;
        score.insert(data[x]);
    }
    /*for (multiset<long long>::iterator it = score.begin();
        it!=score.end();it++) printf("%lld ",*it);
        printf("~~~\n");*/
}
void do4()
{
    multiset<long long>::iterator it = score.end();
    if (!score.empty()) for (int i=1;i<=3;i++)
    {
        it--;
        printf("%lld ",*it);
        if (it==score.begin()) break;
    }
    if (!score.empty()) printf("\n"); else printf("EMPTY\n");
    /*for (multiset<long long>::iterator it = score.begin();
        it!=score.end();it++) printf("%lld ",*it);
    if (!score.empty()) printf(" *** \n");*/
}
int main()
{
    freopen("JUDGER.inp","r",stdin);
    freopen("JUDGER.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        data[i]=0;
        score.insert(0);
    }
    while (m--)
    {
        scanf("%d",&cmd);
        if (cmd==1) do1();
        else if (cmd==2) do2();
        else if (cmd==3) do3();
        else do4();
    }
}
