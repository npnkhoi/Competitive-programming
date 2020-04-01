using namespace std;
#include <stdio.h>
int n;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n/4;i++) printf("aabb");
    if (n%4==1) printf("a");
    else if (n%4==2) printf("aa");
    else if (n%4==3) printf("aab");

}
