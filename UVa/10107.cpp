using namespace std;
#include <stdio.h>
#include <vector>
#include <algorithm>
int x;
vector <int> v;
int main()
{
    while (scanf("%d",&x)!=EOF)
    {
       v.insert(upper_bound(v.begin(),v.end(),x),x);
        if (v.size()%2)
            printf("%d\n",v[v.size()/2]);
        else printf("%d\n",(v[v.size()/2]+v[v.size()/2-1])/2);
    }
}
