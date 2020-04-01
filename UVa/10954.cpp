using namespace std;
#include <stdio.h>
#include <iostream>
#include <queue>
int n, x;
long long a;
priority_queue<long long, vector<long long>, greater<long long>> pq;
long long res;
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0) break;
        for (int i=1; i<=n; i++) scanf("%d",&x), pq.push(x);
        res = 0;
        for (int i=1; i<n; i++)
        {
            a = pq.top(); pq.pop();
            a += pq.top(); pq.pop();
            res += a;
            pq.push(a);
        }
        printf("%lld\n",res);
        pq.pop();
    }
}
