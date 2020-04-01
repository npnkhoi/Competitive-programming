using namespace std;
#include <stdio.h>
#include <iostream>
const int N = 2e5 + 10;
int n,k,q,a,b;
int m[N+50];
int main()
{
    scanf("%d%d%d",&n,&k,&q);
    while (n--)
    {
        scanf("%d%d",&a,&b);
        m[a] ++; m[b+1]--;
    }
//    x = 0;
    for (int i = 1; i<= N; i++) m[i]+=m[i-1];
    for (int i = 1; i<= N; i++) m[i] = (m[i]>=k) + m[i-1];
    while (q--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",m[b]-m[a-1]);
    }
}
