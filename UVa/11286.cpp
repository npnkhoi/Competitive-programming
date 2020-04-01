#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<long long,int> data;
int n,a[6],tc,MAX;
long long s;
int res;

int main()
{
    //freopen("11286.inp","r",stdin);
    while (1)
    {
        data.clear();
        scanf("%d",&n);
        if (n==0) break;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<5;j++) scanf("%d",&a[j]);
            sort(a,a+5);
            s=0;
            for (int j=0;j<5;j++) s=300*s+a[j]-100;
            if (data.count(s)==0) data[s]=1;
            else data[s]++;
        }
        MAX=0; res=0;
        for (map<long long, int>::iterator it=data.begin();it!=data.end();it++)
            {
                if ((it->second)==MAX) res+=MAX;
                if ((it->second)>MAX) res=MAX=it->second;

            }
        printf("%d\n",res);
    }
}
